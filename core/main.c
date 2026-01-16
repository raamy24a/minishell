/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:11 by acollon           #+#    #+#             */
/*   Updated: 2026/01/16 04:50:40 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("Usage: ./minishell", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	env = init_shell(envp);
	if (!env)
		return (EXIT_FAILURE);
	quit_shell(interactive_shell(env), env);
	return (0);
}
