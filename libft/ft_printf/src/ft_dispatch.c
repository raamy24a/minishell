/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:37:40 by acollon           #+#    #+#             */
/*   Updated: 2025/04/14 12:03:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_dispatch(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (format == '%')
		return (ft_putchar('%'));
	return (0);
}
