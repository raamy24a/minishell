/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:28:04 by acollon           #+#    #+#             */
/*   Updated: 2026/01/16 05:22:54 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	init_parser(t_command **head, t_command **tail,
		t_command **current, t_command **out)
{
	if (!out)
		return (0);
	*out = NULL;
	*head = NULL;
	*tail = NULL;
	*current = NULL;
	return (1);
}

static int	parse_tokens(t_shell *tokens, t_struct *all)
{
	t_shell		*node;
	bool		pipe_pending;

	pipe_pending = false;
	node = tokens;
	while (node)
	{
		if (!node->token
			|| !handle_token(&node, all, &pipe_pending))
			return (0);
		node = node->next;
	}
	if (pipe_pending)
		return (0);
	return (1);
}

int	parser(t_shell *tokens, t_command **out)
{
	t_command	*head;
	t_command	*tail;
	t_command	*current;
	t_struct	*all;

	all = malloc(sizeof (t_struct));
	all->head = &head;
	all->tail = &tail;
	all->current = &current;
	if (!init_parser(&head, &tail, &current, out))
		return (0);
	if (!parse_tokens(tokens, all))
	{
		free_command_list(&head);
		return (0);
	}
	if (current && !current->argc && !current->redirs)
	{
		free_command_list(&head);
		return (0);
	}
	*out = head;
	free (all);
	return (1);
}
