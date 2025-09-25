/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:37:41 by acollon           #+#    #+#             */
/*   Updated: 2025/09/25 11:22:58 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* --INCLUDES-- */
# include "minishell_struct.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

// ENV
/* init_env.c */
t_env	*new_env_var(char *key, char *value);
void	add_to_env(t_env **head, t_env *node);
t_env	*duplicate_env(char *input);
void	free_env(t_env **head);
t_env	*init_env(char **env);

#endif