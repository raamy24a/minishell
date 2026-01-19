/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:24:56 by radib             #+#    #+#             */
/*   Updated: 2026/01/19 09:59:20 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

void	environement_modifications(t_env *env, t_env *temp, char *key)
{
	t_env	*previous;

	previous = env;
	temp = env;
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
	while (to_unset[x])
	{
		temp = env;
		environement_modifications(env, temp, to_unset[x]);
		x++;
	}
	return (0);
}
