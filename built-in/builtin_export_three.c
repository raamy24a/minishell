/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:14:18 by radib             #+#    #+#             */
/*   Updated: 2026/01/19 18:27:15 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	export_old_var(t_env *temp, char *to_export, int equal)
{
	free(temp->value);
	temp->value = to_export;
	printf("%s", temp->value);
	if (temp->value == NULL)
	{
		printf("connard\n");
		temp->status = equal_choice(equal, NULL);
	}
	else
		temp->status = equal_choice(equal, to_export);
}