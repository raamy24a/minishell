/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:12:00 by acollon           #+#    #+#             */
/*   Updated: 2026/01/16 05:02:33 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_split(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*get_underscore_value(char **envp)
{
	size_t	len;
	size_t	i;

	if (!envp)
		return (NULL);
	len = ft_strlen("_");
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "_", len) == 0)
			return (/*envp[i] + len*/NULL);
		i++;
	}
	return (NULL);
}

char	*get_path_value(char **envp)
{
	size_t	len;
	size_t	i;

	if (!envp)
		return (NULL);
	len = ft_strlen("PATH=");
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", len) == 0)
			return (envp[i] + len);
		i++;
	}
	return (NULL);
}

char	*build_path(const char *dir, const char *cmd)
{
	char	*joined;
	char	*full;

	joined = ft_strjoin(dir, "/");
	if (!joined)
		return (NULL);
	full = ft_strjoin(joined, cmd);
	free(joined);
	return (full);
}

char	*absolute_or_relative(const char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}
