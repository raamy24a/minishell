/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:36:10 by radib             #+#    #+#             */
/*   Updated: 2025/10/01 01:09:42 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

int	call_pwd(t_env *environement)
{
	char buffer[BUFFER_SIZE];
	if (getcwd(buffer, BUFFER_SIZE) != NULL)
	{
		printf("%s\n", buffer);
		return (0);
	}
	return (errno);
}
