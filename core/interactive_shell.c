/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_shell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:36 by acollon           #+#    #+#             */
/*   Updated: 2025/12/28 16:27:34 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*prompt_listener(void)
{
	char	*user_input;

	user_input = readline("minishell$ ");
	if (user_input && *user_input)
		add_history(user_input);
	return (user_input);
}

int	interactive_shell(t_env *env)
{
	char	*user_input;
	int		last_status;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	last_status = 0;
	while (1)
	{
		user_input = prompt_listener();
		if (!user_input)
			break ;
		if (*user_input)
			last_status = prompt_execution(user_input, env);
		free(user_input);
	}
	ft_putendl_fd("exit", STDOUT_FILENO);
	return (last_status);
}
