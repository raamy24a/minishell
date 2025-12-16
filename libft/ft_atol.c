/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:14:34 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:18:48 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// peut gerer au dela de long_max correctement a changer si necessaire
long	ft_atol(const char *nptr)
{
	long		result;
	int			sign;

	result = LONG_MAX;
	sign = 1;
	if (ft_strlen(nptr) >= 19)
		return (result);
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) && *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10;
		result = result + (*nptr - '0');
		if (result >= LONG_MAX)
			return (LONG_MAX);
		nptr++;
	}
	return (result * sign);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("%lu\n", ft_atol(av[1]));
// 		printf("%lu\n", atol(av[1]));
// 	}
// 	return (0);
// }