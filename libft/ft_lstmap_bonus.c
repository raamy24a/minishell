/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:21:58 by acollon           #+#    #+#             */
/*   Updated: 2025/04/19 15:22:00 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>

void	*add_exclamation(void *content)
{
	char	*str = (char *)content;
	char	*new = malloc(strlen(str) + 2);
	if (!new)
		return (NULL);
	strcpy(new, str);
	strcat(new, "!");
	return (new);
}

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*original = NULL;
	t_list	*new = NULL;

	t_list	*node1 = ft_lstnew(strdup("Salut"));
	t_list	*node2 = ft_lstnew(strdup("à"));
	t_list	*node3 = ft_lstnew(strdup("toi"));

	ft_lstadd_back(&original, node1);
	ft_lstadd_back(&original, node2);
	ft_lstadd_back(&original, node3);

	new = ft_lstmap(original, add_exclamation, del_content);

	t_list *tmp = new;
	while (tmp)
	{
		printf("Contenu : %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	// Nettoyage des deux listes
	ft_lstclear(&original, del_content);
	ft_lstclear(&new, del_content);

	return (0);
}*/
