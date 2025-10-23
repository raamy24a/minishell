/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:27:59 by acollon           #+#    #+#             */
/*   Updated: 2025/10/23 23:32:36 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	lexer(char *input, t_shell *sh)
{
	int				i;
	size_t			*size;
	t_tokens		*token;

	i = 0;
	token = malloc(sizeof(t_tokens));
	while (input[i])
	{
		size = 0;
		if (input[i] ==  '"')
			token->type = quoted_token(input, size, token);
		else if (!ft_isspace(input[i]))
			token->type = get_token_type(input, input[i], size, sh);
		if (token->type == TOK_ERROR)
				return (0);
		else
			size++;
		token->token = ft_substr(input, i, *size);
		i += *size;
	}
	return (1);
}

void	free_token(t_shell *sh)
{
	if (!sh)
		return ;
	while(sh)
	{
		free(sh->token->token);	
		free(sh->token);	
		sh = sh->next;
	}
}

int	main(int ac, char **av)
{
	t_shell	*sh;
	
	sh = malloc(sizeof(sh));
	if (ac == 2)
	{
		if (!lexer(av[1], sh))
			// appelle a la fonction d'affichage d'erreur. 
		while (sh)
		{
			printf("%s %d\n", sh->token->token, sh->token->type);
			sh = sh->next;
		}
	}
	free_token(sh);
	free(sh);
	return (0);
}
