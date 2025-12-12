/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:28:04 by acollon           #+#    #+#             */
/*   Updated: 2025/11/14 22:54:15 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_argv(t_command *cmd)
{
	size_t	i;

	if (!cmd || !cmd->argv)
		return ;
	i = 0;
	while (i < cmd->argc)
	{
		free(cmd->argv[i]);
		i++;
	}
	free(cmd->argv);
	cmd->argv = NULL;
	cmd->argc = 0;
}

void	command_add_back(t_command **head, t_command *node)
{
	t_command	*cur;

	if (!head || !node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
}

void	free_command_list(t_command **head)
{
	t_command	*cmd;
	t_command	*next;

	if (!head)
		return ;
	cmd = *head;
	while (cmd)
	{
		next = cmd->next;
		free_argv(cmd);
		free_redir_list(cmd->redirs);
		free(cmd);
		cmd = next;
	}
	*head = NULL;
}
