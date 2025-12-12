/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 03:04:19 by radib             #+#    #+#             */
/*   Updated: 2025/10/05 00:46:58 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

int echoafaireplutardlol(char *s, int x, t_env *env)
{
	int i;
	char	*temp;
	t_env	*tmp;

	i = x;
	while (s[x] >= '0' && s[x] <= '9' || s[x] >= 'A' 
		&& s[x] <= 'Z' || s[x] >= 'a' && s[x] <= 'z' || s[x] == '_')
		x++;
	temp = malloc(sizeof(char) * (x - i + 1));
	x = i;
	while (s[x] >= '0' && s[x] <= '9' || s[x] >= 'A' 
		&& s[x] <= 'Z' || s[x] >= 'a' && s[x] <= 'z' || s[x] == '_')
	{
		temp[x] = s[x];
		x++;
	}
		while (tmp->next && ft_strcmp(temp, tmp->key) != 0)
			temp = tmp->next;
		if (ft_strcmp(temp, tmp->key))
			printf("%s", tmp->value);
		free(temp);
	return (i);
}
void	echobuiltin(char **string, t_env *env)
{
	int x;
	int i;
	int newline;

	newline = 1;
	x = -1;
	if (string[0][0] == '-' && string[0][1] == 'n')
	{
		newline = 0;
		x = 0;
	}
	while (string[++x])
	{
		while (string[x][i])
		{
		i = 0;
		if (string[x][i] == '$')
			i = echoafaireplutardlol(string[x][i], i, env);
		else
			write(1, string[x][i], 1);
		}
	}
	if (newline == 1)
		printf("\n");
}
