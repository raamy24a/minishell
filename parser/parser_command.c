/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:28:04 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:12:00 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_command	*command_new(void)
{
	t_command	*cmd;

	cmd = (t_command *)ft_calloc(1, sizeof(*cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->argc = 0;
	cmd->redirs = NULL;
	cmd->pipe_before = false;
	cmd->pipe_after = false;
	cmd->type = CMD_SIMPLE;
	cmd->next = NULL;
	return (cmd);
}

static void	copy_argv_array(char **new_argv, t_command *cmd)
{
	size_t	i;

	i = 0;
	while (i < cmd->argc)
	{
		new_argv[i] = cmd->argv[i];
		i++;
	}
}

static int	handle_new_word(char **new_argv, t_command *cmd,
		const t_tokens *token)
{
	new_argv[cmd->argc] = parser_token_value(token);
	if (!new_argv[cmd->argc])
	{
		free(new_argv);
		return (0);
	}
	free(cmd->argv);
	cmd->argv = new_argv;
	cmd->argc++;
	return (1);
}

int	command_add_word(t_command *cmd, const t_tokens *token)
{
	char	**new_argv;

	if (!cmd || !token || !token->token)
		return (0);
	new_argv = (char **)ft_calloc(cmd->argc + 2, sizeof(*new_argv));
	if (!new_argv)
		return (0);
	copy_argv_array(new_argv, cmd);
	return (handle_new_word(new_argv, cmd, token));
}
