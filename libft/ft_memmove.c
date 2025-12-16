/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:53:22 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:18:09 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*sc;
	unsigned char		*dst;

	dst = (unsigned char *)dest;
	sc = (const unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (dst < sc)
	{
		while (n--)
			*dst++ = *sc++;
	}
	else
	{
		while (n--)
			dst[n] = sc[n];
	}
	return (dest);
}

// #include <stdio.h>

// int	main()
// {
// 	char *s1 = NULL;
// 	s
// 	char *s2 = NULL;
// 	int size = 5;
// 	char	*test;
// 	test = (char *)ft_memmove(s1, s2, size);
// 	printf("%s\n", test);
// }
