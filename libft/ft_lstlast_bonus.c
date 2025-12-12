/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:20:51 by acollon           #+#    #+#             */
/*   Updated: 2025/04/19 15:20:53 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	t_list	*head = NULL;
	t_list	*node1 = ft_lstnew(strdup("First"));
	t_list	*node2 = ft_lstnew(strdup("Middle"));
	t_list	*node3 = ft_lstnew(strdup("Last"));

	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);

	t_list *last = ft_lstlast(head);
	if (last)
		printf("Dernier nœud : %s\n", (char *)last->content);
	else
		printf("Liste vide.\n");

	// Libération mémoire
	free(node1->content);
	free(node2->content);
	free(node3->content);
	free(node1);
	free(node2);
	free(node3);

	return (0);
}*/