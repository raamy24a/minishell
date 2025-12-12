/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labeuhlognaise <labeuhlognaise@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:11 by acollon           #+#    #+#             */
/*   Updated: 2025/12/11 13:51:59 by labeuhlogna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env   *env;

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
}
