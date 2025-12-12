/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:34:12 by acollon           #+#    #+#             */
/*   Updated: 2025/11/14 22:56:13 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t	stripped_length(const char *token)
{
	size_t	i;
	size_t	len;
	char	quote;

	i = 0;
	len = 0;
	quote = 0;
	while (token[i])
	{
		if (token[i] == 39 || token[i] == '"')
		{
			quote = token[i++];
			while (token[i] && token[i++] != quote)
				len++;
			continue ;
		}
		len++;
		i++;
	}
	return (len);
}

static char	*strip_quotes(const char *token)
{
	char	*result;
	size_t	i;
	size_t	j;
	char	quote;

	result = (char *)ft_calloc(stripped_length(token) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	quote = 0;
	while (token[i])
	{
		if (token[i] == 39 || token[i] == '"')
		{
			quote = token[i++];
			while (token[i] && token[i] != quote)
				result[j++] = token[i++];
			if (token[i] == quote)
				i++;
		}
		else
			result[j++] = token[i++];
	}
	return (result);
}

char	*parser_token_value(const t_tokens *token)
{
	if (!token || !token->token)
		return (NULL);
	return (strip_quotes(token->token));
}
