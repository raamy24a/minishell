/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:44:56 by acollon           #+#    #+#             */
/*   Updated: 2025/04/13 16:56:56 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	total_len;
	int		i;
	int		j;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * total_len + 1);
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] != '\0')
	{
		join[j + i] = s2[i];
		i++;
	}
	join[j + i] = '\0';
	return (join);
}
/*
#include <stdio.h>

int	main()
{
	char	*str1 = "Hello";
	char	*str2 = "World";

	printf("Concatanate string : %s\n", ft_strjoin(str1, str2));
	return (0);
}*/
