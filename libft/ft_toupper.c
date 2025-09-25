/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:22:49 by acollon           #+#    #+#             */
/*   Updated: 2025/04/11 18:34:51 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>

int	main()
{
	char *str = "Hello World!5";
	int	i = 0;
	char	c;

	while (str[i])
	{
		c = ft_toupper(str[i]);
		printf("%c", c);
		i++;
	}
	return (0);
}*/
