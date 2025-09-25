/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:21:38 by acollon           #+#    #+#             */
/*   Updated: 2025/04/19 15:21:40 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
/*
#include <stdio.h>
#include <string.h>

void	del_content(void *content)
{
	printf("Suppression : %s\n", (char *)content);
	free(content);
}

int	main(void)
{
	t_list	*head = NULL;

	t_list	*node1 = ft_lstnew(strdup("A"));
	t_list	*node2 = ft_lstnew(strdup("B"));
	t_list	*node3 = ft_lstnew(strdup("C"));

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	ft_lstclear(&head, del_content);

	if (head == NULL)
		printf("Liste vidée avec succès.\n");

	return (0);
}*/
