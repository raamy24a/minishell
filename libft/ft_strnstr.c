/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:22:07 by acollon           #+#    #+#             */
/*   Updated: 2025/04/13 11:52:25 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && len > 0)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] == big[i + j] && little[j] && (i + j) < len)
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	const char *big = "Hello world";
	const char *little = "world";
	char *res = ft_strnstr(big, little, 15);

	if (res)
		printf ("Found %s\n", res);
	else
		printf("Not found\n");
	return (0);
}*/
