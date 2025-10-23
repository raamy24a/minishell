/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:16:30 by acollon           #+#    #+#             */
/*   Updated: 2025/10/23 23:25:48 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token_type	get_token_type(char *input, char c, size_t *size, t_shell *sh)
{
	t_token_type	type;

	while (input[*size] == c)
		*size++;
	if (*input == '|')
	{
		if (*size == 1)
			type = TOK_PIPE;
		else
		{
			type = TOK_ERROR;
			syntax_error(input, sh);
		}
	}
	else if (*input == '<' || *input == '>')
	{
		type = redir_append_heredoc(input, *input, *size, sh);
		if (type == TOK_ERROR)
			syntax_error(input, sh);
	}
	return (type);
}

t_token_type	redir_append_heredoc(char *input, char c, size_t *size, 
	t_shell *sh)
{
	int	i;

	i = 0;
	if (*size = 1)
	{
		if (c == '>')
			return (TOK_REDIR_OUT);
		if (c == '<')
			return (TOK_REDIR_IN);
	}
	if (*size == 2)
	{
		if (c == '>' && input[i + 1] == '>')
			return (TOK_APPEND);
		if (c == '<' && input[i + 1] == '<')
			return (TOK_HEREDOC);
	}
	return (TOK_ERROR);
}

t_token_type	quoted_token(char *input, int *size, t_tokens *token)
{
	token->quote = 1;
	if (input[*size] == '"')
		*size++;
	while (input[*size] != '"')
		*size++;
	*size += 1;
	return (TOK_WORD);
}
