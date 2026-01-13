/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:12:00 by acollon           #+#    #+#             */
/*   Updated: 2026/01/13 15:01:20 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static void	safe_close(int fd)
// {
// 	if (fd >= 0)
// 		close(fd);
// }

// static void	child_run(t_pipex *px, char *cmd, int input_fd, int output_fd)
// {
// 	if (dup2(input_fd, STDIN_FILENO) == -1)
// 		perror("dup2");
// 	if (dup2(output_fd, STDOUT_FILENO) == -1)
// 		perror("dup2");
// 	safe_close(px->infile);
// 	safe_close(px->outfile);
// 	if (input_fd != STDIN_FILENO)
// 		safe_close(input_fd);
// 	if (output_fd != STDOUT_FILENO)
// 		safe_close(output_fd);
// 	exit(px_exec(cmd, px->envp));
// }

// static int	fork_child(t_pipex *px, char *cmd, int input_fd, int output_fd)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("fork");
// 		return (-1);
// 	}
// 	if (pid == 0)
// 		child_run(px, cmd, input_fd, output_fd);
// 	return (pid);
// }

// static int	wait_for_children(int last_pid, int count)
// {
// 	int	status;
// 	int	exit_code;

// 	exit_code = 0;
// 	while (count--)
// 	{
// 		if (waitpid(-1, &status, 0) == last_pid)
// 		{
// 			if (WIFEXITED(status))
// 				exit_code = WEXITSTATUS(status);
// 			else
// 				exit_code = 1;
// 		}
// 	}
// 	return (exit_code);
// }

// static int	start_pipeline(t_pipex *px, int ac, char **av)
// {
// 	int		pipefd[2];
// 	int		i;
// 	pid_t	pid;
// 	pid_t	last_pid;

// 	i = 2;
// 	while (i < ac - 2)
// 	{
// 		if (pipe(pipefd) == -1)
// 		{
// 			perror("pipe");
// 			return (EXIT_FAILURE);
// 		}
// 		pid = fork_child(px, av[i], px->prev_fd, pipefd[1]);
// 		safe_close(pipefd[1]);
// 		safe_close(px->prev_fd);
// 		if (pid < 0)
// 			return (EXIT_FAILURE);
// 		px->prev_fd = pipefd[0];
// 		i++;
// 	}
// 	last_pid = fork_child(px, av[ac - 2], px->prev_fd, px->outfile);
// 	safe_close(px->prev_fd);
// 	safe_close(px->outfile);
// 	safe_close(px->infile);
// 	if (last_pid < 0)
// 		return (EXIT_FAILURE);
// 	return (wait_for_children(last_pid, ac - 3));
// }

// int	pipex(int ac, char **av, char **envp)
// {
// 	t_pipex	px;

// 	px.envp = envp;
// 	px.infile = open(av[1], O_RDONLY);
// 	if (px.infile < 0)
// 	{
// 		perror(av[1]);
// 		return (EXIT_FAILURE);
// 	}
// 	px.outfile = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
// 	if (px.outfile < 0)
// 	{
// 		perror(av[ac - 1]);
// 		safe_close(px.infile);
// 		return (EXIT_FAILURE);
// 	}
// 	px.prev_fd = px.infile;
// 	return (start_pipeline(&px, ac, av));
// }
