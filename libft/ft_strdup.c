/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:45:02 by acollon           #+#    #+#             */
/*   Updated: 2025/12/10 13:24:35 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest [i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*cpy;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	cpy = (char *)malloc(len * sizeof(char));
	if (!cpy)
		return (NULL);
	return (ft_strcpy(cpy, s));
}
/*
#include <stdio.h>

int     main()
{
	char    src[] = "Hello World!";
	char    *copy = ft_strdup(src);

	printf("SRC : %s\n", src);
	printf("Copy : %s\n", copy);
	free(copy);
	return (0);
}*/
