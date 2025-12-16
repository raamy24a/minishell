/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:36 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:11:35 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	*new_node(t_tokens *tok)
{
	t_shell	*node;

	node = (t_shell *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->env = NULL;
	node->token = tok;
	node->error = NULL;
	node->next = NULL;
	return (node);
}

int	append_node(t_shell **head, t_tokens *tok)
{
	t_shell	*node;
	t_shell	*cur;

	node = new_node(tok);
	if (!node)
		return (0);
	if (!*head)
	{
		*head = node;
		return (1);
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
	return (1);
}

void	free_token_list(t_shell **head)
{
	t_shell	*cur;
	t_shell	*next;

	if (!head || !*head)
		return ;
	cur = *head;
	while (cur)
	{
		next = cur->next;
		if (cur->token)
		{
			free(cur->token->token);
			free(cur->token);
		}
		free(cur);
		cur = next;
	}
	*head = NULL;
}

t_tokens	*alloc_token(void)
{
	t_tokens	*tok;

	tok = (t_tokens *)malloc(sizeof(*tok));
	if (!tok)
		return (NULL);
	tok->quote = 0;
	tok->token = NULL;
	tok->type = TOK_ERROR;
	return (tok);
}

int	lexer(const char *input, t_shell **out_list)
{
	size_t	i;
	size_t	size;

	if (!input || !out_list)
		return (0);
	*out_list = NULL;
	i = 0;
	size = 0;
	while (input[i])
	{
		if (ft_isspace(input[i]))
		{
			i++;
			continue ;
		}
		if (!process_token_at(input, i, out_list, &size))
			return (free_token_list(out_list), 0);
		i += size;
	}
	return (1);
}
