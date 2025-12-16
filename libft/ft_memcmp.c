/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:27:32 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:18:24 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int     main()
{
char    s1[] = "abc";
char    s2[] = "abc";

printf("%d\n", ft_memcmp(s1, s2, 7));
return (0);
}*/
// #include <stdio.h>

// int	main()
// {
// 	char *s1 = NULL;
// 	char *s2 = NULL;
// 	int size = 5;

// 	printf("%d\n", ft_memcmp(s1, s2, size));
// }