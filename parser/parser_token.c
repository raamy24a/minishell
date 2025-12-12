/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:28:04 by acollon           #+#    #+#             */
/*   Updated: 2025/11/14 23:26:53 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_redirection(t_token_type type)
{
	return (type == TOK_REDIR_IN || type == TOK_REDIR_OUT
		|| type == TOK_APPEND || type == TOK_HEREDOC);
}

static int	handle_pipe(t_command *current, t_shell *node, bool *pipe_pending)
{
	if (!current || (!current->argc && !current->redirs))
		return (0);
	if (!node->next || !node->next->token)
		return (0);
	if (node->next->token->type == TOK_PIPE)
		return (0);
	current->pipe_after = true;
	*pipe_pending = true;
	return (1);
}

int	ensure_command(t_command **head, t_command **tail,
		t_command **current, bool pipe_before)
{
	t_command	*node;

	if (*current)
		return (1);
	node = command_new();
	if (!node)
		return (0);
	node->pipe_before = pipe_before;
	if (!*head)
		*head = node;
	else if (*tail)
		(*tail)->next = node;
	*tail = node;
	*current = node;
	return (1);
}

static int	process_command_token(t_shell **node, t_command **head,
		t_command **tail, t_command **current, bool *pipe_pending)
{
	bool	pending;

	pending = *pipe_pending;
	if (!ensure_command(head, tail, current, pending))
		return (0);
	if (pending)
		*pipe_pending = false;
	if (is_redirection((*node)->token->type))
		return (handle_redirection(*current, node, (*node)->token->type));
	if (!command_add_word(*current, (*node)->token))
		return (0);
	return (1);
}

int	handle_token(t_shell **node, t_command **head,
		t_command **tail, t_command **current, bool *pipe_pending)
{
	if ((*node)->token->type == TOK_PIPE)
	{
		if (!handle_pipe(*current, *node, pipe_pending))
			return (0);
		*current = NULL;
		return (1);
	}
	return (process_command_token(node, head, tail, current, pipe_pending));
}
