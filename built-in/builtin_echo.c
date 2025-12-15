/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 03:04:19 by radib             #+#    #+#             */
/*   Updated: 2025/12/15 16:25:34 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/minishell_struct.h"
#include "../libft/libft.h"

int	echo_dollars(char *s, int x, t_env *env)
{
	char	*temp;
	t_env	*tmp;

	tmp = env;
	while (s[x] >= '0' && (s[x] <= '9' || s[x] >= 'A')
		&& (s[x] <= 'Z' || s[x] >= 'a') && (s[x] <= 'z' || s[x] == '_'))
		x++;
	temp = malloc(sizeof(char) * (x + 1));
	x = 0;
	while (s[x] >= '0' && (s[x] <= '9' || s[x] >= 'A')
		&& (s[x] <= 'Z' || s[x] >= 'a') && (s[x] <= 'z' || s[x] == '_'))
	{
		temp[x] = s[x];
		x++;
	}
	temp[x] = '\0';
	while (tmp->next && ft_strcmp(temp, tmp->key) != 0)
		tmp = tmp->next;
	if (ft_strcmp(temp, tmp->key) == 0)
		printf("%s", tmp->value);
	free(temp);
	return (x + 1);
}
//newline = 1
//x = -1

int	echo_write(char **string, t_env *env, int x, int i)
{
	while (string[++x])
	{
		i = 0;
		while (string[x][i])
		{
			if (string[x][i] == '$')
				i += echo_dollars(&string[x][i + 1], 0, env);
			else
				write(1, &string[x][i++], 1);
		}
	}
	return (i);
}

int	echobuiltin(char **string, t_env *env, int newline, int x)
{
	int	i;
	int	j;
	int	jump;

	jump = 1;
	j = -1;
	while (jump || string[j][0] == '-')
	{
		j++;
		i = 1;
		while (string[j][i] && string[j][i] == 'n')
			i++;
		if (!string[j][i])
			newline = 0;
		else
			break ;
		jump = 0;
	}
	echo_write(&string[j - 1], env, x, 0);
	if (newline == 1)
		printf("\n");
	return (0);
}

t_env	*new_env_varr(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	print_env(t_env *env)
{
	while (env)
	{
		if (env->value != NULL)
			ft_printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (0);
}
