/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:14:13 by acollon           #+#    #+#             */
/*   Updated: 2025/10/23 23:00:26 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_istoken(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}
