/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:18:57 by radib             #+#    #+#             */
/*   Updated: 2026/01/15 15:31:01 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*px_find_path(char *cmd, char **envp, int i, char *path_value)
{
	char	**paths;
	char	*candidate;

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
	while (paths[++i])
	{
		candidate = build_path(paths[i], cmd);
		if (candidate && access(candidate, X_OK) == 0)
		{
			free_split(paths);
			return (candidate);
		}
		free(candidate);
	}
	free_split(paths);
	return (get_underscore_value(envp));
}
