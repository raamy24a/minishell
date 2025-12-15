/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:36:10 by radib             #+#    #+#             */
/*   Updated: 2025/12/15 15:11:56 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

t_env	*list_duplicator(t_env *a, t_env *dup_head, t_env *cur_o,
	t_env *cur_dup)
{
	t_env	*new_node;

	if (!a)
		return (NULL);
	dup_head = malloc(sizeof(t_env));
	if (!dup_head)
		return (NULL);
	dup_head->key = ft_strdup(a->key);
	dup_head->value = ft_strdup(a->value);
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
		return (printf
			("minishell: export: `%s': not a valid identifier\n", temp));
	while (command[i][++j] && command[i][j] != '=' && i % 2 == 0)
	{
		if (ft_isalnum(command[i][j]) == 0 || command[i][j] == '_')
		{
			return (printf
				("minishell: export:`%s': not a valid identifier\n", temp));
			i++;
		}
	}
	return (1);
}

int	export_str(t_env *env, char **to_export)
{
	t_env	*new;
	t_env	*temp;

	temp = env;
	while (temp->next && ft_strcmp (to_export[0], temp->key) != 0)
		temp = temp->next;
	if (ft_strcmp (to_export[0], temp->key) == 0)
		temp->value = to_export[1];
	else
	{
		new = malloc(sizeof(t_env));
		if (!new)
			return (0);
		new->key = ft_strdup(to_export[0]);
		new->value = ft_strdup(to_export[1]);
		new->next = NULL;
		temp->next = new;
	}
	return (0);
}

int	export_with_args(t_env *environement, char **command, int i)
{
	char	**command_split;

	while (command[++i])
	{
		command_split = ft_split(command[i], "=");
		if (verify_identifier(command_split, i, 0, command_split[i]) != 1)
			continue ;
		else
			export_str(environement, &command_split[0]);
		free(command_split);
	}
	return (0);
}

int	export_builtin(t_env *environement, char **command)
{
	t_env	*sorted_env;
	t_env	*temp;
	int		x;

	x = 0;
	if (!command[1])
	{
		sorted_env = sorting_list(environement);
		temp = sorted_env;
		while (temp->next)
		{
			printf("declare -x %s=\"%s\"\n", temp->key, temp->value);
			temp = temp->next;
		}
		printf("declare -x %s=\"%s\"\n", temp->key, temp->value);
	}
	else
		x = export_with_args(environement, &command[1], -1);
	return (x);
}
