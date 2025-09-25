/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:42:24 by acollon           #+#    #+#             */
/*   Updated: 2025/04/10 13:05:09 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (ft_isalpha(av[1][i]) == 0)
				printf("%c : is alpha\n", av[1][i]);
			else
				printf("%c : is not alpha\n", av[1][i]);
			i++;
		}
	}
	return(0);
}
*/
