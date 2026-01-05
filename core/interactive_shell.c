/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_shell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:36 by acollon           #+#    #+#             */
/*   Updated: 2026/01/05 15:23:36 by radib            ###   ########.fr       */
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

void sigint_handle (int sig)
{
	sig = 3;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	printf("\nminishell$ ");
}
void sigquit_handle (int sig)
{
	sig = 1;
	printf("\033[2K");
	rl_on_new_line();
	rl_redisplay();
}

void EOF_handle (int sig)
{
	sig = 3;
	if (ft_strlen (prompt_listener()))
	{
		printf("%c", 127);
		return ;
	}
	exit (0);
}

int	interactive_shell(t_env *env)
{
	char	*user_input;
	int		last_status;

	while (1)
	{
		signal(SIGINT, sigint_handle);
		signal(EOF, EOF_handle);
		signal(SIGQUIT, sigquit_handle);
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
