/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:37:40 by acollon           #+#    #+#             */
/*   Updated: 2025/04/14 12:03:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
//#include <stdio.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}
/*
#include <stdio.h> // pour printf

int	main(void)
{
	int	count;

	count = ft_putchar('A');
	printf("\nNombre de caractères affichés : %d\n", count);

	count = ft_putchar('\n');
	printf("Nombre de caractères affichés : %d\n", count);

	return (0);
}
*/