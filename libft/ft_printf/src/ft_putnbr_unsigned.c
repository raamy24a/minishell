/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:37:40 by acollon           #+#    #+#             */
/*   Updated: 2025/04/14 12:03:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_unsigned(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
/*
#include <stdio.h>

int	ft_putnbr_unsigned(unsigned int nb);

int	main(void)
{
	int	count;

	count = ft_putnbr_unsigned(42);
	printf("\nNombre de caractères affichés : %d\n", count);

	count = ft_putnbr_unsigned(0);
	printf("\nNombre de caractères affichés : %d\n", count);

	count = ft_putnbr_unsigned(4294967295);
	printf("\nNombre de caractères affichés : %d\n", count);

	return (0);
}*/