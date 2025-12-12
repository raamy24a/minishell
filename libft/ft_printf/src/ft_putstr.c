/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:37:40 by acollon           #+#    #+#             */
/*   Updated: 2025/04/14 12:03:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}
/*
#include <stdio.h> // pour printf

int	main(void)
{
	int	count;

	count = ft_putstr("Hello, world!");
	printf("\nNombre de caractères affichés : %d\n", count);

	count = ft_putstr("");
	printf("\nNombre de caractères affichés : %d\n", count);

	count = ft_putstr(NULL);
	printf("\nNombre de caractères affichés : %d\n", count);

	return (0);
}*/
