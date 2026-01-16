/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:32:14 by acollon           #+#    #+#             */
/*   Updated: 2026/01/16 04:00:12 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <string.h>

int	handle_heredoc(const char *delimiter)
{
	int		pipefd[2];
	char	*line;

	signal(SIGQUIT, SIG_IGN);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	while (1)
	{
		line = readline("> ");
		if (!line || !strcmp(line, delimiter))
			break ;
		ft_putendl_fd(line, pipefd[1]);
		free(line);
	}
	free(line);
	close(pipefd[1]);
	return (pipefd[0]);
}

int	fd_value(int fd, t_redir *redir)
{
	if (redir->type == REDIR_IN)
		fd = open(redir->target, O_RDONLY);
	else if (redir->type == REDIR_OUT)
		fd = open(redir->target, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (redir->type == REDIR_APPEND)
		fd = open(redir->target, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else if (redir->type == REDIR_HEREDOC)
		fd = handle_heredoc(redir->target);
	return (fd);
}

int	apply_redirections(t_redir *redir, int *input_fd, int *output_fd)
{
	int	fd;

	while (redir)
	{
		fd = -1;
		fd = fd_value(fd, redir);
		if (fd < 0)
			return (perror(redir->target), -1);
		if (redir->type == REDIR_IN || redir->type == REDIR_HEREDOC)
		{
			if (*input_fd != STDIN_FILENO && *input_fd != -1)
				close(*input_fd);
			*input_fd = fd;
		}
		else
		{
			if (*output_fd != STDOUT_FILENO && *output_fd != -1)
				close(*output_fd);
			*output_fd = fd;
		}
		redir = redir->next;
	}
	return (0);
}

void	exec_exit(char **command, t_env *env)
{
	t_long_verif	*nbr;

	nbr = ft_verif_atoll(command[1], 1, 0, 0);
	if (nbr->status == 0)
	{
		printf("minishell: exit: %s: numeric argument required\n", command[1]);
		exit_call(2, env);
	}
	else if (command[2])
	{
		printf ("minishell: exit: too many arguments\n");
		printf("exit\n");
		return ;
	}
	else if (!command[1])
		exit_call(0, env);
	exit_call(ft_atoi(command[1], 1, 0, 0), env);
}

int	exec_builtin(int x, char **command, t_env *env)
{
	t_env	*temp;

	temp = NULL;
	if (x == 1)
		return (echobuiltin(&command[1], env, 1, 0));
	if (x == 2)
		return (call_pwd());
	if (x == 3)
		return (export_builtin(env, command, 0));
	if (x == 4)
		return (builtin_unset(env, command, temp, 1));
	if (x == 5)
		return (call_cd(env, command[1]));
	if (x == 6)
		exec_exit(command, env);
	if (x == 7)
		return (call_env(env));
	return (0);
}
