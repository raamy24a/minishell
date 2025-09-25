/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:21:26 by acollon           #+#    #+#             */
/*   Updated: 2025/04/19 15:21:27 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>
#include <string.h>

void	del_content(void *content)
{
	printf("Suppression du contenu : %s\n", (char *)content);
	free(content);
}

int	main(void)
{
	t_list	*node = ft_lstnew(strdup("À supprimer"));

	ft_lstdelone(node, del_content);

	// À ce stade, node est free (mais on ne touche pas à node->next ici)

	return (0);
}
*/
