/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:14:18 by radib             #+#    #+#             */
/*   Updated: 2026/01/19 19:48:42 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	export_old_var(t_env *temp, char *to_export, int equal)
{
	if (temp->value)
		free(temp->value);
	temp->value = ft_strdup(to_export);
	if (temp->value == NULL && temp->status == 2)
		return ;
	else
		temp->status = equal_choice(equal, to_export);
}

void	export_new_var(t_env *temp, char **to_export, int equal)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = ft_strdup(to_export[0]);
	new->value = ft_strdup(to_export[1]);
	new->status = equal_choice(equal, temp->value);
	new->next = NULL;
	temp->next = new;
}