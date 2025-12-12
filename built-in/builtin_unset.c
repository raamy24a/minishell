/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:24:56 by radib             #+#    #+#             */
/*   Updated: 2025/12/12 15:05:41 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

void	environement_modifications(t_env *env, t_env *temp, int y)
{
	int		i;
	t_env	*previous;

	previous = env;
	i = 0;
	while (i < y)
	{
		previous = previous->next;
		if (previous->next)
			temp = previous->next;
		i++;
	}
	if (temp->next->key)
	{
		previous->next = temp->next;
		previous->key = temp->key;
		previous->value = temp->value;
	}
	else
		previous->next = NULL;
	free(temp);
}

int	builtin_unset(t_env *env, char **to_unset, t_env *temp, int x)
{
	int	y;

	while (to_unset[x])
	{
		y = 0;
		temp = env;
		while (temp->next && ft_strcmp (to_unset[x], temp->key) != 0)
		{
			temp = temp->next;
			y++;
		}
		if (ft_strcmp (to_unset[x], temp->key) == 0)
			environement_modifications(env, temp, y - 1);
		x++;
	}
	return (0);
}
