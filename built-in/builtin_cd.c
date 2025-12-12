/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 03:04:19 by radib             #+#    #+#             */
/*   Updated: 2025/10/01 01:53:08 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

char	*remove_last(char *string)
{
	int	x;

	x = 0;
	while (string[x])
		x++;
	while (string[x] != '/')
	{
		string[x] = '\0';
		x--;
	}
	string[x] = '\0';
	return (string);
}

char	*add_word(char *string, char *word_to_add)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (string[x])
		x++;
	string[x] = '/';
	x++;
	while (word_to_add[i])
	{
		string[x + i] = word_to_add[i];
		i++;
	}
	string[x + i] = '\0';
	return (string);
}
char	*cd_builtin(char *path, char *string_after_cd, int x, int y)
{
	char	**split;

	if (string_after_cd[0] == '/')
		return (string_after_cd);
	ft_split(string_after_cd, '/');
	if (split[0][0] == '\0')
		return (string_after_cd);
	while (split[x])
	{
		if (split[x][0] == '.' || split[x][0] == '.' && split[x][1] == '.')
		{
			if (split[x][1] == '.')
				remove_last(path);
			x++;
		}
		else
		{
			add_word(path, split[x]);
			x++;
		}
	}
	return (path);
}

int	call_cd(t_env *env, char *string_after_cd)
{
	char buffer[BUFFER_SIZE];

	getcwd (buffer, BUFFER_SIZE);
	if (chdir(cd_builtin(buffer ,string_after_cd, 0, 0) != 0))
	{
		perror (errno);
		return (errno);
	}
	return (0);
}
