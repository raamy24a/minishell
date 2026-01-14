/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:36:10 by radib             #+#    #+#             */
/*   Updated: 2026/01/14 15:15:37 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

char	*get_pwd(void)
{
	char	*buffer;

	buffer = malloc (sizeof(char) * 4096 + 1);
	buffer[4096] = '\0';
	if (getcwd(buffer, 4096) != NULL)
	{
		return (buffer);
	}
	free(buffer);
	perror("rien pour l'instant");
	return (NULL);
}

int	call_pwd(void)
{
	char	buffer[4096 + 1];

	buffer[4096] = '\0';
	if (getcwd(buffer, 4096) != NULL)
	{
		printf("%s\n", buffer);
		return (0);
	}
	return (errno);
}
