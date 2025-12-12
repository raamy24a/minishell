/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:50:12 by acollon           #+#    #+#             */
/*   Updated: 2025/04/13 14:18:15 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			total_len;
	size_t			i;
	unsigned char	*str;

	i = 0;
	total_len = nmemb * size;
	ptr = malloc(total_len);
	if (ptr == NULL)
		return (NULL);
	str = (unsigned char *)ptr;
	while (i < total_len)
	{
		str[i] = 0;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>

int	main()
{
	int	n = 5;
	int	*arr = (int *)ft_calloc(n, sizeof(int));
	int	i = 0;

	if (arr == NULL)
	{
		printf("Error\n");
		return (1);
	}
	while (i < n)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	free (arr);
	return (0);
}*/
