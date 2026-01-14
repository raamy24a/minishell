/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 07:23:43 by radib             #+#    #+#             */
/*   Updated: 2026/01/14 10:20:06 by radib            ###   ########.fr       */
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

char	*get_value_of_key(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp->next && ft_strcmp(key, tmp->key) != 0)
	{
		tmp = tmp->next;
	}
	if (ft_strcmp(key, tmp->key) != 0)
		return (NULL);
	return (tmp->value);
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

char	**env_to_char_array(t_env *env)
{
	t_env	*temp;
	int		i;
	char	**array_env;

	i = 0;
	temp = env;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	array_env = malloc (sizeof (char *) * (i + 1));
	temp = env;
	i = 0;
	while (temp->next)
	{
		array_env[i] = ft_strjoin (ft_strjoin(temp->key, "="), temp->value);
		i++;
		temp = temp->next;
	}
	array_env[i] = ft_strjoin (temp->key, temp->value);
	array_env[i + 1] = NULL;
	return (array_env);
}