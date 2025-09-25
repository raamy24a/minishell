/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:01:19 by acollon           #+#    #+#             */
/*   Updated: 2025/04/11 18:21:44 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = 0;
	slen = 0;
	dlen = 0;
	while (dst[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (dlen >= size)
		return (size + slen);
	while ((src[i]) && (i < size - dlen -1))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
/*
#include <stdio.h>

int	main()
{
	char	s1[] = "Hello123456789";
	char	s2[] = "World";
	char	s3[] = "Hello123456789";
	char	s4[] = "World";
	
	printf("%zu\n", ft_strlcat(s1, s2, 10));
	printf("%zu\n", ft_strlcat(s3, s4, 40));
}*/
