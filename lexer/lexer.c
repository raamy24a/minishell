/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:36 by acollon           #+#    #+#             */
/*   Updated: 2025/11/04 14:39:31 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	*new_node(t_tokens *tok)
{
	t_shell	*node;

	node = (t_shell *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->token = tok;
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

static void	print_token_type(t_token_type type)
{
	if (type == TOK_WORD)
		printf("WORD");
	else if (type == TOK_PIPE)
		printf("PIPE");
	else if (type == TOK_REDIR_IN)
		printf("REDIR_IN");
	else if (type == TOK_REDIR_OUT)
		printf("REDIR_OUT");
	else if (type == TOK_APPEND)
		printf("APPEND");
	else if (type == TOK_HEREDOC)
		printf("HEREDOC");
	else
		printf("ERROR");
}

int	main(int ac, char **av)
{
	t_shell	*list;
	t_shell	*tmp;

	if (ac != 2)
	{
		printf("Usage: ./lexer \"<command>\"\n");
		return (1);
	}
	if (!lexer(av[1], &list))
	{
		printf("Lexing error.\n");
		return (1);
	}
	tmp = list;
	while (tmp)
	{
		printf("[%s] -> ", tmp->token->token);
		print_token_type(tmp->token->type);
		if (tmp->token->quote)
			printf(" (quoted)");
		printf("\n");
		tmp = tmp->next;
	}
	free_token_list(&list);
	return (0);
}
