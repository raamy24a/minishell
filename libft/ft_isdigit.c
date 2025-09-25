/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:06:03 by acollon           #+#    #+#             */
/*   Updated: 2025/04/10 13:23:19 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int     main(int ac, char **av)
{
        int     i = 0;

        if (ac == 2)
        {
                while (av[1][i] != '\0')
                {
                        if (ft_isdigit(av[1][i]) == 0)
                                printf("%c : is digit\n", av[1][i]);
                        else
                                printf("%c : is not digit\n", av[1][i]);
                        i++;
                }
        }
        return(0);
}
*/
