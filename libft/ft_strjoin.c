/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:44:56 by acollon           #+#    #+#             */
/*   Updated: 2026/01/16 22:27:26 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_strjoin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	printf("2:%s \n, 1:%s\n", s1, s2);
	str_strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str_strjoin)
		return (NULL);
	while (s1[i++])
		str_strjoin[i - 1] = s1[i - 1];
	while (s2[j++])
	{
		str_strjoin[i - 1] = s2[j - 1];
		i++;
	}
	str_strjoin[i - 1] = '\0';
	return (str_strjoin);
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
