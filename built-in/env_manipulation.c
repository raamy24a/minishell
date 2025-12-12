/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 07:23:43 by radib             #+#    #+#             */
/*   Updated: 2025/09/27 07:25:09 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

t_env	*ft_lstlast_env(t_env *lst)
{
	size_t	i;
	t_env	*last;

	i = 0;
	last = lst;
	if (last == NULL)
		return (NULL);
	while (last -> next)
	{
		last = last -> next;
		i++;
	}
	return (last);
}
void	ft_lstadd_back_env(t_env *lst, t_env *new)
{
	t_env	*temp;

	if (!lst || !new)
		return ;
	temp = ft_lstlast_env(lst);
	if (!temp)
	{
		lst = new;
		return ;
	}
	temp -> next = new;
}