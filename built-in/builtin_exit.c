/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:48:51 by radib             #+#    #+#             */
/*   Updated: 2026/01/12 13:07:23 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

int	exit_call(int x, t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp->next)
	{
		temp = temp->next;
		free(env->key);
		free(env->value);
		free(env);
		env = temp;
	}
	free(env->key);
	free(env->value);
	free(env);
	rl_clear_history();
	x = x % 256;
	printf("exit\n");
	exit (x);
}
