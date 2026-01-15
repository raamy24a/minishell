/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:37:40 by acollon           #+#    #+#             */
/*   Updated: 2026/01/15 16:24:55 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr, int sign, int total, int i)
{
	if (!nptr)
		return (-20000000000);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total *= 10;
		total += nptr[i] - '0';
		if ((total * sign > 0) && sign == -1)
			return (-20000000000);
		if ((total < 0) && sign == 1)
			return (-20000000000);
		i++;
	}
	if (!(nptr[i]) && !(sign == -1 && total == 0 && i == 1))
		return ((long)(total * sign));
	return (-20000000000);
}

// #include <stdio.h>
// #include <stdlib.h>

// int     main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("%ld\n", ft_atoi(av[1], 1, 0, 0));
// 		printf("%d\n", atoi(av[1]));
// 	}
// }