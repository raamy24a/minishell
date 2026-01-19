/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_execution_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:34:38 by radib             #+#    #+#             */
/*   Updated: 2026/01/18 21:04:50 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t	launch_command(t_command *cmd, int prev_fd, int next_fd, t_env *env)
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

int	wait_children(pid_t last_pid, int count)
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

int	run_pipeline(t_shell *tokens, t_env *env)
{
	t_command	*cmds;
	int			status;

	(void)env;
	cmds = NULL;
	status = 0;
	if (!parser(tokens, &cmds))
		status = 2;
	else if (cmds && cmds->argv)
		status = execute_commands(cmds, env, 0);
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
