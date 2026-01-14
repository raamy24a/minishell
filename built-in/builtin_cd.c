/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 03:04:19 by radib             #+#    #+#             */
/*   Updated: 2026/01/14 15:16:01 by radib            ###   ########.fr       */
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

int	old_n_pwd(t_env *env, char *old_pwd_value, char *pwd_value)
{
	char	**s;

	s = malloc (sizeof (char *) * 3);
	s[2] = NULL;
	s[0] = ft_strdup("export");
	if (!s[0])
		exit_call(1, env);
	s[1] = ft_strjoin("OLDPWD=", old_pwd_value);
	if (!s[1])
		exit_call(1, env);
	export_with_args(env, s, 0, 0);
	s[1] = ft_strjoin("PWD=", pwd_value);
	if (!s[1])
		exit_call(1, env);
	export_with_args(env, s, 0, 0);
	free(s[0]);
	free(s);
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
	old_n_pwd(env, get_value_of_key(env, "PWD"), get_value_of_key(env, "HOME"));
	return (temp->value);
}

char	*cd_last(t_env *env)
{
	if (get_value_of_key(env, "OLDPWD") == NULL)
	{
		ft_printf("minishell: cd: OLDPWD not set\n");
		return (NULL);
	}
	return (get_value_of_key(env, "OLDPWD"));
}

int wich_cd(t_env *env, char *string_after_cd, int x, char *old_pwd)
{
	if (!string_after_cd)
	{
		x = chdir(cd_home(env));
		if (x == 0)
		{
			printf("%s\n", get_pwd());
			return (old_n_pwd(env, old_pwd, get_pwd()));
		}
	}
	if (ft_strlen(string_after_cd) == 1 && string_after_cd[0] == '-')
	{
		x = chdir(cd_last(env));
		printf("%s\n", get_pwd());
		if (x == 0)
			return (old_n_pwd(env, get_value_of_key(env, "PWD"), get_value_of_key(env, "OLDPWD")));
	}
	return (-1);
}

int	call_cd(t_env *env, char *string_after_cd)
{
	char	buffer[4096 + 1];
	int		x;
	char	*old_pwd;

	old_pwd = get_pwd();
	buffer[4096] = '\0';
	getcwd (buffer, 4096);
	x = wich_cd(env, string_after_cd, -1, old_pwd);
	if (x == 0)
		return (x);
	if ((chdir(cd_builtin(buffer, string_after_cd, 0)) != 0))
	{
		perror("rien pour le moment");
		return (errno);
	}
	return (old_n_pwd(env, old_pwd, get_pwd()));
}
