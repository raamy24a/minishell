/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:16:30 by acollon           #+#    #+#             */
/*   Updated: 2025/09/29 11:52:04 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token_type	get_token_type(char *input, char c, int *size, t_minishell *sh)
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

t_token_type	redir_append_heredoc(char *input, char c, int *size, 
	t_minishell *sh)
{
	if (c == '>' && *size == 1)
		return (TOK_REDIR_OUT);
	else if (c == '>' && *size == 2)
		return (TOK_APPEND);
	else if (c == '<' && *size == 1)
		return (TOK_REDIR_IN);
	else if (c == '<' || *size == 2)
		return (TOK_HEREDOC);
	return (TOK_ERROR);
}
