/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:28 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:06:37 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*init_shell(char **envp)
{
	t_env	*env;

	env = init_env(envp);
	if (!env)
		ft_putendl_fd("minishell: failed to initialize environment",
			STDERR_FILENO);
	return (env);
}
