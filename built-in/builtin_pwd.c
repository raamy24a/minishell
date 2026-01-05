/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:36:10 by radib             #+#    #+#             */
/*   Updated: 2026/01/05 10:39:32 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

char	*get_pwd(void)
{
	char	*buffer;

	buffer = malloc (sizeof(char) * BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	if (getcwd(buffer, BUFFER_SIZE) != NULL)
	{
		return (buffer);
	}
	free(buffer);
	perror("rien pour l'instant");
	return (NULL);
}

int	call_pwd(void)
{
	char	buffer[BUFFER_SIZE + 1];

	buffer[BUFFER_SIZE] = '\0';
	if (getcwd(buffer, BUFFER_SIZE) != NULL)
	{
		printf("%s\n", buffer);
		return (0);
	}
	return (errno);
}
