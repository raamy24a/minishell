/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 03:04:19 by radib             #+#    #+#             */
/*   Updated: 2025/12/15 16:35:38 by radib            ###   ########.fr       */
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
		if ((split[x][0] == '.' || split[x][0] == '.') && split[x][1] == '.')
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

void	old_n_pwd(t_env *env, char *old_pwd_value, char *pwd_value)
{
	char	**s;

	s = malloc (sizeof (char *) * 2);
	s[1] = NULL;
	s[0] = ft_strjoin("OLDPWD=", old_pwd_value);
	if (!s[0])
		exit(1);
	export_with_args(env, s, 0);
	s[0] = ft_strjoin("PWD=", pwd_value);
	if (!s[0])
		exit(1);
	export_with_args(env, s, 0);
	free(s[0]);
	free(s);
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
	char	*temp_str;
	t_env	*temp_pwd;
	t_env	*temp_old_pwd;

	temp_pwd = env;
	temp_old_pwd = env;
	while (temp_pwd->next && ft_strcmp ("PWD", temp_pwd->key) != 0)
		temp_pwd = temp_pwd->next;
	temp_str = temp_pwd->value;
	while (temp_old_pwd->next && ft_strcmp ("OLDPWD", temp_old_pwd->key) != 0)
		temp_old_pwd = temp_old_pwd->next;
	if (ft_strcmp ("OLDPWD", temp_old_pwd->key) != 0)
	{
		ft_printf("minishell: cd: OLDPWD not set\n");
		return (NULL);
	}
	temp_pwd->value = temp_old_pwd->value;
	temp_old_pwd->value = temp_str;
	old_n_pwd(env, temp_old_pwd->value, temp_pwd->value);
	return (temp_pwd->value);
}

int	call_cd(t_env *env, char *string_after_cd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		x;

	buffer[BUFFER_SIZE] = '\0';
	getcwd (buffer, BUFFER_SIZE);
	if (!string_after_cd)
	{
		x = chdir(cd_home(env));
		printf("%s\n", get_pwd());
		
		return (x);
	}
	if (ft_strlen(string_after_cd) == 1 && string_after_cd[0] == '-')
	{
		x = chdir(cd_last(env));
		printf("%s\n", get_pwd());
		return (x);
	}
	if ((chdir(cd_builtin(buffer, string_after_cd, 0)) != 0))
	{
		perror("rien pour le moment");
		return (errno);
	}
	printf("%s\n", get_pwd());
	return (0);
}
