/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:05:43 by acollon           #+#    #+#             */
/*   Updated: 2025/12/19 15:25:40 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char *str, char *charset, int i)
{
	int	a;

	a = 0;
	if (charset == NULL && str[i] != '\0')
		return (0);
	if (str[i] == '\0')
		return (2);
	while (charset[a])
	{
		if (charset[a] == str[i])
			return (1);
		else if (str[i] == '\0')
			return (2);
		a++;
	}
	return (0);
}

char	**strs_alloc(char **strs, char *str, char *charset, int i)
{
	int	k;
	int	j;

	k = 0;
	while (is_sep(str, charset, i) != 2)
	{
		while (is_sep(str, charset, i) == 1)
			i++;
		j = i;
		while (is_sep(str, charset, j) == 0 && str[j])
			j++;
		if (is_sep(str, charset, i) == 2)
		{
			strs[k] = malloc(sizeof(char) * (j - i + 1));
			if (!strs[k])
				return (NULL);
			break ;
		}
		strs[k] = malloc(sizeof(char) * (j - i + 1));
		if (!strs[k])
			return (NULL);
		k++;
		i = j;
	}
	return (strs);
}

char	**strs_write(char **strs, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	while (is_sep(str, charset, i) != 2)
	{
		j = 0;
		while (is_sep(str, charset, i) == 1)
			i++;
		l = i;
		while (is_sep(str, charset, i) == 0 && str[i] != '\0')
		{
			strs[k][j] = str[i];
			i++;
			j++;
		}
		strs[k][j] = '\0';
		if (i != l)
			k++;
	}
	strs[k] = NULL;
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		k;
	char	**strs;
	int		j;

	i = 0;
	k = 0;
	while (is_sep(str, charset, i) != 2)
	{
		while (is_sep(str, charset, i) == 1)
			i++;
		j = i;
		while (is_sep(str, charset, i) == 0 && str[i] != '\0')
			i++;
		if (j != i)
			k++;
		if (is_sep(str, charset, i) == 2)
			break ;
	}
	strs = malloc(sizeof(char *) * (k + 1));
	strs_alloc(strs, str, charset, 0);
	strs_write(strs, str, charset);
	return (strs);
}
