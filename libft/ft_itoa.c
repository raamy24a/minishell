/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:24:24 by acollon           #+#    #+#             */
/*   Updated: 2025/04/17 14:08:35 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	if (n < 0)
		n = -n;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	nb;

	i = ft_intlen(n);
	nb = n;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
printf("%s\n", ft_itoa(0));
printf("%s\n", ft_itoa(42));
printf("%s\n", ft_itoa(-42));
printf("%s\n", ft_itoa(2147483647));
printf("%s\n", ft_itoa(-2147483648));
printf("%s\n", ft_itoa(-12448364));
return (0);
}*/
