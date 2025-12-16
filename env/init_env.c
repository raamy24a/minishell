/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:15:57 by acollon           #+#    #+#             */
/*   Updated: 2025/12/16 14:08:52 by radib            ###   ########.fr       */
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

void	free_env(t_env **head)
{
	t_env	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->key);
		free((*head)->value);
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}

t_env	*init_env(char **env)
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
		add_to_env(&head, node);
		env++;
	}
	return (head);
}

/*  main de test local */

// int print_env(t_env *env)
// {
//     while (env)
//     {
//         if (env->value != NULL)
//             ft_printf("%s=%s\n", env->key, env->value);
//         env = env->next;
//     }
// 	return (0);
// }

// int	main(int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)av;

// 	t_env	*env_list = init_env(envp);
// 	if (!env_list)
// 	{
// 		ft_printf("%s\n", "init env failed");
// 		return (1);
// 	}
// 	print_env(env_list);
// 	free_env(&env_list);
// 	return (0);
// }
