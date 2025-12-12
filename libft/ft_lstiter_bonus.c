/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:21:49 by acollon           #+#    #+#             */
/*   Updated: 2025/04/19 15:21:52 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void	to_uppercase(void *content)
{
	char	*str = (char *)content;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int	main(void)
{
	t_list	*head = NULL;

	t_list	*node1 = ft_lstnew(strdup("bonjour"));
	t_list	*node2 = ft_lstnew(strdup("tout"));
	t_list	*node3 = ft_lstnew(strdup("le monde"));

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	ft_lstiter(head, to_uppercase);

	t_list *tmp = head;
	while (tmp)
	{
		printf("Contenu : %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	// Libération mémoire
	ft_lstclear(&head, free);

	return (0);
}
*/
