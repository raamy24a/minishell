/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:20:02 by acollon           #+#    #+#             */
/*   Updated: 2025/04/19 15:20:05 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*str = strdup("Hello, world!");
	t_list	*node;

	if (!str)
		return (1);
	node = ft_lstnew(str);
	if (!node)
	{
		free(str);
		return (1);
	}
	printf("Contenu du noeud : %s\n", (char *)node->content);
	printf("Adresse du noeud : %p\n", (void *)node);
	printf("Adresse du next : %p\n", (void *)node->next);

	free(str);
	free(node);
	return (0);
}*/
