/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:22:49 by acollon           #+#    #+#             */
/*   Updated: 2025/04/11 18:35:45 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>

int     main()
{
        char *str = "Hello World!5";
        int     i = 0;
        char    c;

        while (str[i])
        {
                c = ft_tolower(str[i]);
                printf("%c", c);
                i++;
        }
        return (0);
}*/
