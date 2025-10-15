/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:27:59 by acollon           #+#    #+#             */
/*   Updated: 2025/10/07 11:16:10 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	lexer(char *input, t_minishell *sh)
{
	int				i;
	int				*size;
	t_token_type	*type;
	t_tokens		*token;

	i = 0;

	while (input[i])
	{
		*size = 0;
		if (!ft_isspace(input[i]))
			type = get_token_type(input, input[i], *size, sh);
		else
			*size++;
		i += *size;
	}
}

int	main(int ac, char **av)
{
	t_tokens	*token;

	if (ac == 2)
	{
		token = lexer(av[1]);
		while (token->next)
		{
			printf("%s %d", token->token, token->type);
			token = token->next;
		}
	}
	free_token(&token);
	return (0);
}
