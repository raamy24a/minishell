/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:16:47 by acollon           #+#    #+#             */
/*   Updated: 2025/04/12 13:55:45 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c2;

	i = 0;
	c2 = (unsigned char)c;
	while (s[i])
	{
		if ((unsigned char)s[i] == c2)
			return ((char *)s + i);
		i++;
	}
	if (c2 == '\0')
		return ((char *)s + i);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "Hello World";
	char	*result;

	result = ft_strchr(str, 'o');
	printf("Test 1 - 'o' trouvé : %s\n", result);

	result = ft_strchr(str, 'x');
	if (result)
		printf("Test 2 - 'x' trouvé : %s\n", result);
	else
		printf("Test 2 - 'x' pas trouvé\n");

	result = ft_strchr(str, '\0');
	if (result)
		printf("Test 3 - '\\0' trouvé à l’adresse : %p\n", result);
	else
		printf("Test 3 - '\\0' pas trouvé\n");

	result = ft_strchr(str, 't' + 256);
	if (result)
		printf("Test 4 - 't' + 256 trouvé : %s\n", result);
	else
		printf("Test 4 - 't' + 256 pas trouvé\n");

	result = ft_strchr(str, -42);
	if (result)
		printf("Test 5 - -42 trouvé : %s\n", result);
	else
		printf("Test 5 - -42 pas trouvé\n");

	result = ft_strchr(NULL, 'H');
	if (result)
		printf("Test 6 - NULL input (surprise!) : %s\n", result);
	else
		printf("Test 6 - NULL input géré correctement\n");

	return 0;
}
*/
