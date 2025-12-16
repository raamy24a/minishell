/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:12:00 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:10:06 by radib            ###   ########.fr       */
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

static char	*get_path_value(char **envp)
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

static char	*build_path(const char *dir, const char *cmd)
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

static char	*absolute_or_relative(const char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*px_find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*candidate;
	char	*path_value;
	size_t	i;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (absolute_or_relative(cmd));
	path_value = get_path_value(envp);
	if (!path_value)
		return (NULL);
	paths = ft_split(path_value, ":");
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		candidate = build_path(paths[i], cmd);
		if (candidate && access(candidate, X_OK) == 0)
		{
			free_split(paths);
			return (candidate);
		}
		free(candidate);
		i++;
	}
	free_split(paths);
	return (NULL);
}
