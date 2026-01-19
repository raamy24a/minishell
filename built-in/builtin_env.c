/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:36:38 by radib             #+#    #+#             */
/*   Updated: 2026/01/06 13:00:32 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	call_env(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp->next)
	{
		printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
	printf("%s=%s\n", temp->key, temp->value);
	return (0);
}
