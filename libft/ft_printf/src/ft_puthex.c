/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:37:40 by acollon           #+#    #+#             */
/*   Updated: 2025/04/14 12:03:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(unsigned long n, char format)
{
	char	*base;
	int		count;

	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	count += ft_putchar(base[n % 16]);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int count;

	count = ft_puthex_base(255, 'x'); // f f
	printf("\nNombre de caractères : %d\n", count);

	count = ft_puthex_base(48879, 'X'); // BEEF
	printf("\nNombre de caractères : %d\n", count);
}
*/