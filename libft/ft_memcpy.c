/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:20:42 by acollon           #+#    #+#             */
/*   Updated: 2025/05/04 14:19:53 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	unsigned char		*sc;
	size_t				i;

	i = 0;
	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char	dest[50];

	if (ac == 2)
	{
		printf("Source : %s\n", av[1]);
		printf("Dest : %p\n", ft_memcpy(dest, av[1], 15));
		printf("%p\n", memcpy(dest, av[1], 15));
	}
	return (0);
}*/