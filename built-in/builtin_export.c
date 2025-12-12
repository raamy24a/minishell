/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:36:10 by radib             #+#    #+#             */
/*   Updated: 2025/09/29 18:45:37 by radib            ###   ########.fr       */
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
int	*export_with_args(t_env *environement, char **command, int i, int j)
{
	char	*temp_value;
	char	*temp_key;
	int		jump;

	temp_key = command[i];
	while (command[i])
	{
		jump = 0;
		j = -1;
		if (ft_isalpha(command[i][j]) == 0 && command[i][j] != '_')
		{
			printf("minishell: export: `%s': not a valid identifier\n",
				temp_key);
			jump = 1;
		}
		while (jump == 0 && command[i][++j] && command[i][j] != '=')
		{
			if (ft_isalnum(command[i][j]) == 0 && command[i][j] != '_')
			{
				printf("minishell: export: `%s': not a valid identifier\n",
					temp_key);
				i++;
				jump = 1;
			}
		}
		// je dois mettre ce qu'il y a au dessus dans une nouvelle fonction et faire les truc bidules avec = et = et mauvais charactere;
		if (jump == 0 && command[i][j] == '=')
		{
			command[i][j] = '\0';
			temp_value = command[i][j + 1];
		}
		i++;
	}
}
int	export_builtin(t_env *environement, char **command)
{
	t_env	*sorted_env;
	t_env	*temp;
	int		x;

	x = 0;
	if (command[0][0] == '/0')
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
		x = export_with_args(environement, command, 0, 0);
	return (x);
}
