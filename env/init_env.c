/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:15:57 by acollon           #+#    #+#             */
/*   Updated: 2026/01/19 17:33:38 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*new_env_var(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->status = 1;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_env(t_env **head, t_env *node)
{
	t_env	*current;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->status = 1;
	current->next = node;
}

t_env	*duplicate_env(char *input)
{
	char	*sep;
	char	*key;
	char	*value;

	sep = ft_strchr(input, '=');
	if (!sep)
	{
		key = ft_strdup(input);
		if (!key)
			return (NULL);
		value = NULL;
	}
	else
	{
		key = ft_substr(input, 0, sep - input);
		if (!key)
			return (NULL);
		value = ft_strdup(sep + 1);
		if (!value)
			return (free(key), NULL);
	}
	return (new_env_var(key, value));
}

void	free_env(t_env **env)
{
	t_env	*tmp;

	tmp = (*env);
	while (tmp->next)
	{
		tmp = (*env);
		tmp = tmp->next;
		free((*env)->key);
		printf("%s <--\n", (*env)->value);
		if ((*env)->value)
			free((*env)->value);
		free(*env);
		(*env) = tmp;
	}
	free((*env)->key);
	free((*env)->value);
	free(*env);
	env = NULL;
}

t_env	*default_env(char **env)
{
	t_env	*head;
	t_env	*node;

	head = NULL;
	while (*env)
	{
		node = duplicate_env(*env);
		if (!node)
		{
			free_env(&head);
			return (NULL);
		}
		if (!ft_strcmp(node->key, "OLDPWD"))
			node->status = 0;
		add_to_env(&head, node);
		env++;
	}
	return (head);
}
