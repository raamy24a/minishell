/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:09:54 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:21:14 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	advance_quoted_segment(const char *input, size_t *index)
{
	char	quote;

	quote = input[*index];
	(*index)++;
	while (input[*index] && input[*index] != quote)
		(*index)++;
	if (input[*index] != quote)
		return (0);
	(*index)++;
	return (1);
}

static int	scan_word(const char *input, size_t *size, int *fully_quoted,
		size_t i)
{
	int		unquoted;

	unquoted = 0;
	if (!input || !size)
		return (0);
	while (input[i] && !ft_isspace(input[i]) && !ft_istoken(input[i]))
	{
		if (ft_isquote(input[i]))
		{
			if (!advance_quoted_segment(input, &i))
				return (0);
		}
		else
		{
			unquoted = 1;
			i++;
		}
	}
	if (i == 0)
		return (0);
	*size = i;
	if (fully_quoted)
		*fully_quoted = !unquoted;
	return (1);
}

t_token_type	redir_append_heredoc(const char *input, char c,
		size_t *size, t_shell *sh)
{
	(void)sh;
	*size = 0;
	while (input[*size] == c)
		(*size)++;
	if (c == '|')
	{
		if (*size == 1)
			return (TOK_PIPE);
		return (TOK_ERROR);
	}
	if (*size == 1)
	{
		if (c == '<')
			return (TOK_REDIR_IN);
		return (TOK_REDIR_OUT);
	}
	if (*size == 2)
	{
		if (c == '<' && input[1] == '<')
			return (TOK_HEREDOC);
		if (c == '>' && input[1] == '>')
			return (TOK_APPEND);
	}
	return (TOK_ERROR);
}

int	parse_token(const char *input, size_t i, t_tokens **tok_out,
		size_t *size_out)
{
	t_tokens		*tok;
	t_token_type	type;
	size_t			size;

	tok = alloc_token();
	if (!tok)
		return (0);
	if (ft_istoken(input[i]))
		type = redir_append_heredoc(&input[i], input[i], &size, NULL);
	else if (!scan_word(&input[i], &size, &tok->quote, 0))
		type = TOK_ERROR;
	else
		type = TOK_WORD;
	if (type == TOK_ERROR || size == 0)
	{
		free(tok);
		return (0);
	}
	tok->type = type;
	*tok_out = tok;
	*size_out = size;
	return (1);
}

int	process_token_at(const char *input, size_t i, t_shell **out_list,
		size_t *size_out)
{
	t_tokens	*tok;
	size_t		size;

	if (!parse_token(input, i, &tok, &size))
		return (0);
	tok->token = ft_substr(input, i, size);
	if (!tok->token || !append_node(out_list, tok))
	{
		free(tok->token);
		free(tok);
		return (0);
	}
	*size_out = size;
	return (1);
}
