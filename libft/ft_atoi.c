/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:37:40 by acollon           #+#    #+#             */
/*   Updated: 2025/04/14 12:03:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;
	long	flow;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		flow = result * 10 + (*nptr - '0');
		if (sign == 1 && flow < result)
			return (-1);
		if (sign == -1 && (-flow > -result))
			return (0);
		result = flow;
		nptr++;
	}
	return ((sign * result));
}
/*
#include <stdio.h>
#include <stdlib.h>

int     main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%d\n", ft_atoi(av[1]));
		printf("%d\n", atoi(av[1]));
	}
}*/