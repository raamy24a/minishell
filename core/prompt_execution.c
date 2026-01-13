/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:32:14 by acollon           #+#    #+#             */
/*   Updated: 2026/01/13 15:23:18 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <string.h>

static int	handle_heredoc(const char *delimiter)
{
	int		pipefd[2];
	char	*line;

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

static int	apply_redirections(t_redir *redir, int *input_fd, int *output_fd)
{
	int	fd;

	while (redir)
	{
		fd = -1;
		if (redir->type == REDIR_IN)
			fd = open(redir->target, O_RDONLY);
		else if (redir->type == REDIR_OUT)
			fd = open(redir->target, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		else if (redir->type == REDIR_APPEND)
			fd = open(redir->target, O_CREAT | O_APPEND | O_WRONLY, 0644);
		else if (redir->type == REDIR_HEREDOC)
			fd = handle_heredoc(redir->target);
		if (fd < 0)
		{
			perror(redir->target);
			return (-1);
		}
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
	if (ft_atoi(command[1], 0, 0, 0)
		== -20000000000 && ft_strlen(command[1]))
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
	exit_call(ft_atoi(command[1], 0, 0, 0), env);
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

int	is_builtin(char *builtin_str)
{
	if (ft_strcmp(builtin_str, "export") == 0)
		return (3);
	else if (ft_strcmp(builtin_str, "unset") == 0)
		return (4);
	else if (ft_strcmp(builtin_str, "cd") == 0)
		return (5);
	else if (ft_strcmp(builtin_str, "exit") == 0)
		return (6);
	return (0);
}

int	is_builtin_child(char *builtin_str)
{
	if (ft_strcmp(builtin_str, "echo") == 0)
		return (1);
	else if (ft_strcmp(builtin_str, "pwd") == 0)
		return (2);
	else if (ft_strcmp(builtin_str, "env") == 0)
		return (7);
	return (0);
}

static void	child_execute(t_command *cmd, int prev_fd, int next_fd, t_env *env)
{
	int	input_fd;
	int	output_fd;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	input_fd = prev_fd;
	output_fd = next_fd;
	if (input_fd == -1)
		input_fd = STDIN_FILENO;
	if (output_fd == -1)
		output_fd = STDOUT_FILENO;
	if (apply_redirections(cmd->redirs, &input_fd, &output_fd) == -1)
		exit(EXIT_FAILURE);
	if (dup2(input_fd, STDIN_FILENO) == -1)
		perror("dup2");
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		perror("dup2");
	if (input_fd != STDIN_FILENO)
		close(input_fd);
	if (output_fd != STDOUT_FILENO)
		close(output_fd);
	if (prev_fd != -1 && prev_fd != input_fd)
		close(prev_fd);
	if (next_fd != -1 && next_fd != output_fd)
		close(next_fd);
	if (is_builtin_child(cmd->argv[0]))
		exit(exec_builtin(is_builtin_child(cmd->argv[0]), cmd->argv, env));
	execve(get_value_of_key(env, "PATH"), cmd->argv, cmd->argv);
	perror(cmd->argv[0]);
	exit(127);
}

static	pid_t launch_command(t_command *cmd, int prev_fd, int next_fd, t_env *env)
{
	pid_t				pid;

	if (is_builtin(cmd->argv[0]))
		return (exec_builtin(is_builtin(cmd->argv[0]), cmd->argv, env));
	else
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			return (-1);
		}
		if (pid == 0)
			child_execute(cmd, prev_fd, next_fd, env);
		return (pid);
	}
}

static int	wait_children(pid_t last_pid, int count)
{
	int	status;
	int	exit_code;

	exit_code = 0;
	while (count--)
	{
		if (waitpid(-1, &status, 0) == last_pid)
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WTERMSIG(status) == SIGQUIT)
			{
				printf("Quit (core dumped)\n");
				exit_code = 131;
			}
			else if (WTERMSIG(status) == SIGINT)
			{
				printf("\n");
				exit_code = 130;
			}
			else
				exit_code = 1;
		}
	}
	return (exit_code);
}

static int	execute_commands(t_command *cmd, t_env *env)
{
	int		prev_fd;
	pid_t	last_pid;
	int		count;
	int		pipefd[2];

	prev_fd = -1;
	last_pid = -1;
	count = 0;
	while (cmd)
	{
		if (cmd->pipe_after)
		{
			if (pipe(pipefd) == -1)
				return (perror("pipe"), 1);
		}
		else
		{
			pipefd[0] = -1;
			pipefd[1] = -1;
		}
		last_pid = launch_command(cmd, prev_fd, pipefd[1], env);
		if (last_pid < 0)
			return (1);
		if (prev_fd != -1)
			close(prev_fd);
		if (pipefd[1] != -1)
			close(pipefd[1]);
		prev_fd = pipefd[0];
		cmd = cmd->next;
		count++;
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	return (wait_children(last_pid, count));
}

static int	run_pipeline(t_shell *tokens, t_env *env)
{
	t_command	*cmds;
	int			status;

	(void)env;
	cmds = NULL;
	status = 0;
	if (!parser(tokens, &cmds))
		status = 2;
	else if (cmds && cmds->argv)
		status = execute_commands(cmds, env);
	free_command_list(&cmds);
	return (status);
}

int	prompt_execution(char *user_input, t_env *env)
{
	t_shell	*token_list;
	int		status;

	token_list = NULL;
	status = 0;
	if (!lexer(user_input, &token_list))
		status = 2;
	else if (token_list)
		status = run_pipeline(token_list, env);
	free_token_list(&token_list);
	return (status);
}
