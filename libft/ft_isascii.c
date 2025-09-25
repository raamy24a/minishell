/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:11:27 by acollon           #+#    #+#             */
/*   Updated: 2025/04/10 14:42:01 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if (ft_isascii(av[1][i]) == 0)
				printf("%c : is ascii\n", av[1][i]);
			else
				printf("%c : is not ascii\n", av[1][i]);
			i++;
		}		
	}
	return (0);
}*/
