/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:28:04 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:12:16 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_redir_node(t_redir *node)
{
	if (!node)
		return ;
	free(node->target);
	free(node);
}

void	free_redir_list(t_redir *redir)
{
	t_redir	*next;

	next = NULL;
	while (redir)
	{
		next = redir->next;
		free_redir_node(redir);
		redir = next;
	}
}

static t_redir	*create_redir_node(t_token_type type, const t_tokens *token)
{
	t_redir	*node;

	node = (t_redir *)ft_calloc(1, sizeof(*node));
	if (!node)
		return (NULL);
	node->target = parser_token_value(token);
	if (!node->target)
		return (free_redir_node(node), NULL);
	if (type == TOK_REDIR_IN)
		node->type = REDIR_IN;
	else if (type == TOK_REDIR_OUT)
		node->type = REDIR_OUT;
	else if (type == TOK_APPEND)
		node->type = REDIR_APPEND;
	else if (type == TOK_HEREDOC)
		node->type = REDIR_HEREDOC;
	else
		return (free_redir_node(node), NULL);
	node->quoted = token->quote;
	node->next = NULL;
	return (node);
}

int	command_add_redir(t_command *cmd, t_token_type type,
		const t_tokens *token)
{
	t_redir	*node;
	t_redir	*cur;

	if (!cmd || !token || !token->token)
		return (0);
	node = create_redir_node(type, token);
	if (!node)
		return (0);
	if (!cmd->redirs)
	{
		cmd->redirs = node;
		return (1);
	}
	cur = cmd->redirs;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
	return (1);
}

int	handle_redirection(t_command *current, t_shell **token_node,
		t_token_type type)
{
	t_shell	*target;

	target = (*token_node)->next;
	if (!target || !target->token || target->token->type != TOK_WORD)
		return (0);
	if (!command_add_redir(current, type, target->token))
		return (0);
	*token_node = target;
	return (1);
}
