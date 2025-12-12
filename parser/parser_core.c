/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:28:04 by acollon           #+#    #+#             */
/*   Updated: 2025/11/14 22:53:40 by acollon          ###   ########.fr       */
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

static int	parse_tokens(t_shell *tokens, t_command **head,
		t_command **tail, t_command **current)
{
	t_shell		*node;
	bool		pipe_pending;

	pipe_pending = false;
	node = tokens;
	while (node)
	{
		if (!node->token
			|| !handle_token(&node, head, tail, current, &pipe_pending))
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

	if (!init_parser(&head, &tail, &current, out))
		return (0);
	if (!parse_tokens(tokens, &head, &tail, &current))
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
	return (1);
}
