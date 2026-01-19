/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 03:04:19 by radib             #+#    #+#             */
/*   Updated: 2026/01/19 14:20:09 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
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

char	*cd_builtin(char *path, char *string_after_cd, int x)
{
	char	**split;

	if (string_after_cd[0] == '/')
		return (string_after_cd);
	split = ft_split(string_after_cd, "/");
	if (split[0][0] == '\0')
		return (string_after_cd);
	while (split[x])
	{
		if ((split[x][0] == '.' && split[x][1] == '.') && split[x][2] == '\0')
		{
			remove_last(path);
			x++;
		}
		else if (ft_strcmp(split[x], "."))
		{
			add_word(path, split[x]);
			x++;
		}
		else
			x++;
	}
	return (path);
}

int	swap_env(t_env *env, char *a, char *b, int mode)
{
	char	*c;

	c = ft_strdup(get_value_of_key(env, a));
	if (mode == 1)
	{
		change_value_of_key(env, "PWD", b);
		change_value_of_key(env, a, c);
	}
	else
	{
		change_value_of_key(env, a, get_value_of_key(env, b));
		change_value_of_key(env, b, c);
	}
	free(c);
	return (0);
}

char	*cd_home(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp->next && ft_strcmp ("HOME", temp->key) != 0)
		temp = temp->next;
	if (ft_strcmp ("HOME", temp->key) != 0)
	{
		ft_printf("minishell: cd: HOME not set\n");
		return (NULL);
	}
	swap_env(env, "HOME", "PWD", 0);
	return (temp->value);
}
