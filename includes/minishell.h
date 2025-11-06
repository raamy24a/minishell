/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:37:41 by acollon           #+#    #+#             */
/*   Updated: 2025/11/06 11:17:10 by acollon          ###   ########.fr       */
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
t_env			*new_env_var(char *key, char *value);
void			add_to_env(t_env **head, t_env *node);
t_env			*duplicate_env(char *input);
void			free_env(t_env **head);
t_env			*init_env(char **env);

// LEXER
/* lexer.c */
t_shell			*new_node(t_tokens *tok);
int				append_node(t_shell **head, t_tokens *tok);
void			free_token_list(t_shell **head);
t_tokens		*alloc_token(void);
int				lexer(const char *input, t_shell **out_list);

/* token_manager.c */
t_token_type	redir_append_heredoc(const char *input, char c, size_t *size,
					t_shell *sh);
t_token_type	get_token_type(const char *input, char c, size_t *size,
					t_shell *sh);
t_token_type	quoted_token(const char *input, size_t *size, t_tokens *token);
int				parse_token(const char *input, size_t i,
					t_tokens **tok_out, size_t *size_out);
int				process_token_at(const char *input, size_t i,
					t_shell **out_list, size_t *size_out);
t_token_type	single_quoted_token(const char *input, size_t *size,
					t_tokens *token);

/* lexer_utils.c */
int				ft_isspace(char c);
int				ft_istoken(char c);

// ERROR_MANAGER
/* syntax_error.c */
void			syntax_error(char *token, t_shell *sh);

#endif