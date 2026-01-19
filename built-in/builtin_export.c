/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:36:10 by radib             #+#    #+#             */
/*   Updated: 2026/01/19 18:23:04 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

t_env	*list_duplicator(t_env *a, t_env *dup_head, t_env *cur_o,
	t_env *cur_dup)
{
	t_env	*new_node;

	dup_head = malloc(sizeof(t_env));
	if (!dup_head)
		return (NULL);
	dup_head->key = ft_strdup(a->key);
	dup_head->value = ft_strdup(a->value);
	dup_head->status = a->status;
	dup_head->next = NULL;
	cur_o = a->next;
	cur_dup = dup_head;
	while (cur_o)
	{
		new_node = malloc(sizeof(t_env));
		if (!new_node)
			return (dup_head);
		new_node->key = ft_strdup(cur_o->key);
		new_node->value = ft_strdup(cur_o->value);
		new_node->status = a->status;
		new_node->next = NULL;
		cur_dup->next = new_node;
		cur_dup = new_node;
		cur_o = cur_o->next;
	}
	return (dup_head);
}

int	list_not_sorted(t_env *list)
{
	t_env	*temp;

	temp = list;
	while (temp->next && ft_strcmp(temp->key, temp->next->key) < 0)
		temp = temp->next;
	if (temp->next)
		return (1);
	return (0);
}

t_env	*sorting_list(t_env *environement)
{
	t_env	*to_sort;
	t_env	*temp;
	char	*key;
	char	*value;

	if (!environement)
		return (NULL);
	to_sort = list_duplicator(environement, NULL, NULL, NULL);
	while (list_not_sorted(to_sort))
	{
		temp = to_sort;
		while (temp->next && ft_strcmp(temp->key, temp->next->key) < 0)
			temp = temp->next;
		if (temp->next)
		{
			key = temp->key;
			value = temp->value;
			temp->key = temp->next->key;
			temp->value = temp->next->value;
			temp->next->key = key;
			temp->next->value = value;
		}
	}
	return (to_sort);
}

int	verify_identifier(char **command, int i, int j, char *temp)
{
	if (ft_isalpha(command[i][j]) == 0 && command[i][j] != '_' && i % 2 == 0)
		return (printf("minishell: export: `%s=%s': not a valid identifier\n"
				, temp, command[i + 1]));
	while (command[i][++j] && command[i][j] != '=' && i % 2 == 0)
	{
		if (ft_isalnum(command[i][j]) == 0 || command[i][j] == '_')
		{
			return (printf
				("minishell: export:`%s=%s': not a valid identifier\n"
					, temp, command[i + 1]));
			i++;
		}
	}
	return (1);
}

int	export_str(t_env *env, char **to_export, int equal)
{
	t_env	*new;
	t_env	*temp;

	temp = env;
	while (temp->next && ft_strcmp (to_export[0], temp->key) != 0)
		temp = temp->next;
	if (ft_strcmp (to_export[0], temp->key) == 0)
		export_old_var(temp, to_export[1], equal);
	else
	{
		new = malloc(sizeof(t_env));
		if (!new)
			return (0);
		new->key = ft_strdup(to_export[0]);
		new->value = ft_strdup(to_export[1]);
		new->status = equal_choice(equal, temp->value);
		new->next = NULL;
		temp->next = new;
	}
	return (0);
}
