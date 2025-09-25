/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:21:11 by acollon           #+#    #+#             */
/*   Updated: 2025/04/19 15:21:13 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int	main(void)
{
	t_list	*head = NULL;

	t_list	*node1 = ft_lstnew(strdup("One"));
	t_list	*node2 = ft_lstnew(strdup("Two"));
	t_list	*node3 = ft_lstnew(strdup("Three"));

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	t_list *tmp = head;
	while (tmp)
	{
		printf("Contenu : %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	// Libération mémoire
	free(node1->content);
	free(node2->content);
	free(node3->content);
	free(node1);
	free(node2);
	free(node3);

	return (0);
}*/
