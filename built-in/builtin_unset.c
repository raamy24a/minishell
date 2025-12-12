/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:24:56 by radib             #+#    #+#             */
/*   Updated: 2025/09/30 23:18:12 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

int	environement_modifications(t_env *env, char **to_unset, t_env *temp, int x)
{
	t_env *previous;

	if (ft_strcmp (to_unset[x], env->key) == 0)
	{
		if (temp->next)
		{
			previous = temp;
			temp->key = ft_strdup (temp->next->key);
			temp->next = temp->next->next;
			temp->value = ft_strdup (temp->next->key);
			free(temp->next);
		}
		else
		{
			previous->next = NULL;
			free(temp);
		}
	}
}

int	builtin_unset(t_env *env, char **to_unset, t_env *temp, int x)
{
	int	i;

	i = 0;
	while (to_unset[x][0])
	{
		temp = env;
		while (temp->next && ft_strcmp (to_unset[x], env->key) != 0)
			temp = temp->next;
		environement_modifications(env, to_unset, temp, x);
		x++;
	}
	return (0);
}
