/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:31:27 by radib             #+#    #+#             */
/*   Updated: 2026/01/17 06:48:20 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	export_with_args(t_env *environement, char **command, int i, int verify)
{
	char	**command_split;

	while (command[++i])
	{
		command_split = ft_split(command[i], "=");
		if (!command_split)
			return (0);
		if (verify == 1 && verify_identifier(command_split
				, i, 0, command_split[i]) != 1)
			continue ;
		else
			export_str(environement, &command_split[0]);
		free(command_split[0]);
		free(command_split);
	}
	return (0);
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
			printf("declare -x %s=\"%s\"\n", temp->key, temp->value);
			temp = temp->next;
		}
		printf("declare -x %s=\"%s\"\n", temp->key, temp->value);
	}
	else
		x = export_with_args(environement, &command[1], -1, verify);
	return (x);
}
