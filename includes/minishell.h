/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:37:41 by acollon           #+#    #+#             */
/*   Updated: 2025/09/29 11:43:06 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* --INTERNAL_INCLUDES-- */
# include "minishell_struct.h"
# include "../libft/libft.h"

/* --EXTERNAL_INCLUDES-- */
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>

// ENV
/* init_env.c */
t_env	*new_env_var(char *key, char *value);
void	add_to_env(t_env **head, t_env *node);
t_env	*duplicate_env(char *input);
void	free_env(t_env **head);
t_env	*init_env(char **env);


// LEXER
/* lexer_utils.c */
int		ft_isspace(char c);
int		ft_istoken(char c);

// ERROR_MANAGER
/* syntax_error.c */
void	syntax_error(char *token, t_minishell *sh);

#endif