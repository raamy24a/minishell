/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:58:01 by acollon           #+#    #+#             */
/*   Updated: 2025/04/10 21:20:03 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int n = av[1][0] - '0';
	char str[n];
	if (ac == 2)
	{
		ft_bzero(str, n);
		while (i < n)
		{
			if (str[i] != '\0')
			{
				printf("Error : str[%d] n'est pas null\n", i);
				return (1);
			}
			i++;
		}
	}
	printf("Tous les caracteres sont null\n");
	return (0);
}*/
