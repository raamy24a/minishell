/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:37:40 by acollon           #+#    #+#             */
/*   Updated: 2025/04/14 12:03:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int nb)
{
	int		count;
	long	n;

	n = nb;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int	count;

	count = ft_putnbr(42);
	printf("\nNombre de caractères affichés : %d\n", count);

	count = ft_putnbr(-1234);
	printf("\nNombre de caractères affichés : %d\n", count);

	count = ft_putnbr(0);
	printf("\nNombre de caractères affichés : %d\n", count);

	count = ft_putnbr(-2147483648);
	printf("\nNombre de caractères affichés : %d\n", count);

	count = ft_putnbr(2147483647);
	printf("\nNombre de caractères affichés : %d\n", count);

	return (0);
}*/
