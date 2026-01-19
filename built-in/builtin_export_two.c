/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:31:27 by radib             #+#    #+#             */
/*   Updated: 2026/01/19 18:37:10 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	equal_choice(int equal, char *value)
{
	if (!ft_strlen(value) && equal == 1)
		return (2);
	if (equal == 0)
		return (0);
	else
		return (1);
}

char	**export_one(char *input, char	*value, char **return_string)
{
	char	*sep;
	char	*key;

	sep = ft_strchr(input, '=');
	if (!sep)
	{
		key = ft_strdup(input);
		if (!key)
			return (NULL);
		value = NULL;
	}
	else
	{
		key = ft_substr(input, 0, sep - input);
		if (!key)
			return (NULL);
		value = ft_strdup(sep + 1);
		if (!value)
			return (NULL);
	}
	return_string[0] = key;
	return_string[1] = value;
	return (return_string);
}

int	export_with_args(t_env *environement, char **command, int i, int verify)
{
	int		j;
	char	**command_split;
	int		equal;

	command_split = ft_calloc(sizeof(char *), 3);
	while (command[++i])
	{
		j = 0;
		while (command[i][j] && command[i][j] != '=')
			j++;
		if (command[i][j] == '=')
			equal = 1;
		else
			equal = 0;
		command_split = export_one(command[i], NULL, command_split);
		if (!command_split)
			return (0);
		if (verify == 1 && verify_identifier(command_split
				, i, 0, command_split[i]) != 1)
			continue ;
		else
			export_str(environement, &command_split[0], equal);
		free(command_split);
	}
	return (0);
}

void	export_print(int equal, char *key, char *value)
{
	if (equal == 1)
		printf("declare -x %s=\"%s\"\n", key, value);
	else if (equal == 2)
		printf("declare -x %s=\"\"\n", key);
	else if (equal == 0)
		printf("declare -x %s\n", key);
}

int	export_builtin(t_env *environement, char **command, int verify)
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
			export_print(temp->status, temp->key, temp->value);
			temp = temp->next;
		}
		export_print(temp->status, temp->key, temp->value);
	}
	else
		x = export_with_args(environement, &command[1], -1, verify);
	return (x);
}
