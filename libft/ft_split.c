/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:05:43 by acollon           #+#    #+#             */
/*   Updated: 2025/04/17 14:09:51 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_strdup_split(const char *src, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = src[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_free(char **tab, int index)
{
	while (index--)
		free(tab[index]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i[3];

	i[0] = 0;
	i[2] = 0;
	tab = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i[0]])
	{
		while (s[i[0]] == c && s[i[0]])
			i[0]++;
		i[1] = i[0];
		while (s[i[0]] != c && s[i[0]])
			i[0]++;
		if (i[1] < i[0])
		{
			tab[i[2]] = ft_strdup_split(s, i[1], i[0]);
			if (!tab[i[2]])
				return (ft_free(tab, i[2]), NULL);
			i[2]++;
		}
	}
	tab[i[2]] = 0;
	return (tab);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "  Bonjour   les amis ! Comment ça va ? ";
	char	**split;
	int		i;

	split = ft_split(str, ' ');
	if (!split)
	{
		printf("Erreur d'allocation\n");
		return (1);
	}

	i = 0;
	while (split[i])
	{
		printf("mot[%d] = \"%s\"\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);

	return (0);
}
*/