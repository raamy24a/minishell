/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_shell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:36 by acollon           #+#    #+#             */
/*   Updated: 2026/01/13 13:29:05 by radib            ###   ########.fr       */
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

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		(void)sig;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		printf("\033[2K");
		rl_on_new_line();
		rl_redisplay();
	}
}

int	interactive_shell(t_env *env)
{
	char				*user_input;
	int					last_status;
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	while (1)
	{
		sigaction(SIGINT, &sa, NULL);
		signal(SIGQUIT, SIG_IGN);
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
