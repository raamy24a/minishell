/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:09:54 by acollon           #+#    #+#             */
/*   Updated: 2025/11/06 10:53:03 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token_type	redir_append_heredoc(const char *input, char c, size_t *size,
									t_shell *sh)
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

t_token_type	get_token_type(const char *input, char c, size_t *size,
							t_shell *sh)
{
	size_t	i;

	if (ft_istoken(c))
		return (redir_append_heredoc(input, c, size, sh));
	i = 0;
	while (input[i]
		&& !ft_isspace(input[i])
		&& !ft_istoken(input[i])
		&& input[i] != '"')
		i++;
	*size = i;
	if (*size > 0)
		return (TOK_WORD);
	else
		return (TOK_ERROR);
}

t_token_type	quoted_token(const char *input, size_t *size, t_tokens *token)
{
	size_t	i;

	token->quote = 1;
	i = 0;
	if (input[i] != '"')
		return (TOK_ERROR);
	i++;
	while (input[i] && input[i] != '"')
		i++;
	if (input[i] != '"')
		return (TOK_ERROR);
	i++;
	*size = i;
	return (TOK_WORD);
}

int	parse_token(const char *input, size_t i,
		t_tokens **tok_out, size_t *size_out)
{
	t_tokens		*tok;
	t_token_type	type;
	size_t			size;

	tok = alloc_token();
	if (!tok)
		return (0);
	if (input[i] == '"')
		type = quoted_token(&input[i], &size, tok);
	else
		type = get_token_type(&input[i], input[i], &size, NULL);
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

int	process_token_at(const char *input, size_t i,
		t_shell **out_list, size_t *size_out)
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
