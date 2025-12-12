/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:21:24 by acollon           #+#    #+#             */
/*   Updated: 2025/04/10 20:12:01 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*str;
	size_t				i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char	str[10];
		int	c = av[1][0];
		int	n = av[2][0] - 48;
		int	size;

		ft_memset(str, c, n);
		str[n] = '\0';
		size = strlen(str);
		printf("%s\n", str);
		printf("%d\n", size);
	}
	return (0);
}*/
