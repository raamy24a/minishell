/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:45 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:08:42 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	quit_shell(int exit_status, t_env *env)
{
	if (env)
		free_env(&env);
	rl_clear_history();
	exit(exit_status);
}
