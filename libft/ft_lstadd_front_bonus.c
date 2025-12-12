/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:20:24 by acollon           #+#    #+#             */
/*   Updated: 2025/04/19 15:20:26 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	t_list	*head = NULL;
	t_list	*node1 = ft_lstnew(strdup("World"));
	t_list	*node2 = ft_lstnew(strdup("Hello"));

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);

	// Affichage simple
	t_list *tmp = head;
	while (tmp)
	{
		printf("Contenu : %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	// Nettoyage mémoire (important)
	free(node1->content);
	free(node2->content);
	free(node1);
	free(node2);

	return (0);
}*/
