/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:24:56 by radib             #+#    #+#             */
/*   Updated: 2025/12/18 15:41:59 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

void	environement_modifications(t_env *env, t_env *temp, char *key)
{
	int		i;
	t_env	*previous;

	previous = env;
	temp = env;
	i = 0;
	while (temp->next && ft_strcmp (key, temp->key) != 0)
	{
		previous = temp;
		temp = temp->next;
	}
	if (ft_strcmp (key, temp->key) != 0)
		return ;
	if (temp->next)
		previous->next = temp->next;
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
		environement_modifications(env, temp, to_unset[x]);
		x++;
	}
	return (0);
}
