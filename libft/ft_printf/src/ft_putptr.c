/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:37:40 by acollon           #+#    #+#             */
/*   Updated: 2025/04/14 12:03:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	count += write(1, "0x", 2);
	count += ft_puthex(addr, 'x');
	return (count);
}
/*
#include <stdio.h>   
#include <stdlib.h>  

int	main(void)
{
	int				x = 42;
	void			*ptr_stack = &x;
	void			*ptr_null = NULL;
	void			*ptr_heap = malloc(1);
	int				count;

	// Test 1 : pointeur vers une variable (stack)
	count = ft_putptr(ptr_stack);
	printf(" ← (%d caractères)\n", count);

	// Test 2 : pointeur NULL
	count = ft_putptr(ptr_null);
	printf(" ← (%d caractères)\n", count);

	// Test 3 : pointeur sur mémoire heap
	count = ft_putptr(ptr_heap);
	printf(" ← (%d caractères)\n", count);

	free(ptr_heap);
	return (0);
}

#include "../ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	count;

	count = 0;
	count += ft_putchar(' ');
	count += ft_putptr(NULL);
	count += ft_putchar(' ');
	count += ft_putptr(NULL);
	count += ft_putchar(' ');
	printf("Caractères imprimés : %d\n", count);
	return (0);
}
*/