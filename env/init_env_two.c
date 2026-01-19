/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:56:06 by radib             #+#    #+#             */
/*   Updated: 2026/01/15 14:56:56 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*init_env(char **env, int i)
{
	t_env	*head;
	t_env	*node;

	head = NULL;
	while (env[i])
		i++;
	if (i < 10)
		head = default_env(ft_split(ft_strjoin (ft_strjoin
						("PWD=", get_pwd()), "-SHLVL=0-_=/usr/bin/env"), "-"));
	else
	{
		while (*env)
		{
			node = duplicate_env(*env);
			if (!node)
			{
				free_env(&head);
				return (NULL);
			}
			add_to_env(&head, node);
			env++;
		}
	}
	return (head);
}
