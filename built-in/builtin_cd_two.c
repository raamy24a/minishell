/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:28:38 by radib             #+#    #+#             */
/*   Updated: 2026/01/19 14:25:14 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*cd_last(t_env *env)
{
	if (get_value_of_key(env, "OLDPWD") == NULL)
	{
		ft_printf("minishell: cd: OLDPWD not set\n");
		return (NULL);
	}
	return (get_value_of_key(env, "OLDPWD"));
}

int	wich_cd(t_env *env, char *string_after_cd, int x, char *old_pwd)
{
	if (!string_after_cd)
	{
		x = chdir(cd_home(env));
		if (x == 0)
		{
			printf("%s\n", get_pwd());
			return (swap_env(env, old_pwd, get_pwd(), 1));
		}
	}
	if (ft_strlen(string_after_cd) == 1 && string_after_cd[0] == '-')
	{
		x = chdir(cd_last(env));
		if (x == 0)
		{
			printf("%s\n", get_pwd());
			return (swap_env(env, "PWD", "OLDPWD", 0));
		}
		else
			return (-2);
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
	if (x == 0 || x == -2)
		return (x);
	if ((chdir(cd_builtin(buffer, string_after_cd, 0)) != 0))
	{
		perror("rien pour le moment");
		return (errno);
	}
	return (swap_env(env, "OLDPWD", get_pwd(), 1));
}
