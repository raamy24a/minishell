/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:37:41 by acollon           #+#    #+#             */
/*   Updated: 2025/12/15 16:34:52 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* --INTERNAL_INCLUDES-- */
# include "minishell_struct.h"
# include "../libft/libft.h"

/* --EXTERNAL_INCLUDES-- */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>

/* --BUILTINS-- */
int				call_cd(t_env *env, char *string_after_cd);
int				echobuiltin(char **string, t_env *env, int newline, int x);
int				exit_call(int x);
int				export_builtin(t_env *environement, char **command);
int				call_pwd(void);
char			**ft_split(char *str, char *charset);
void			ft_lstadd_back_env(t_env *lst, t_env *new);
char			*get_value_of_key(t_env *env, char *key);
char			*get_pwd(void);
int				builtin_unset(t_env *env, char **to_unset, t_env *temp, int x);
int				export_with_args(t_env *environement, char **command, int i);


// CORE
/* init_shell.c */
t_env			*init_shell(char **envp);

/* interactive_shell.c */
int				interactive_shell(t_env *env);

/* prompt_execution.c */
int				prompt_execution(char *user_input, t_env *env);

/* quit_shell.c */
void			quit_shell(int exit_status, t_env *env);

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
int				parse_token(const char *input, size_t i,
					t_tokens **tok_out, size_t *size_out);
int				process_token_at(const char *input, size_t i,
					t_shell **out_list, size_t *size_out);

/* lexer_utils.c */
int				ft_isspace(char c);
int				ft_istoken(char c);
int				ft_isquote(char c);

// PARSER
/* Core parsing functions */
int				parser(t_shell *tokens, t_command **out);

/* Token handling */
int				handle_token(t_shell **node, t_command **head, t_command **tail,
					t_command **current, bool *pipe_pending);
int				handle_redirection(t_command *current, t_shell **token_node, t_token_type type);
int				ensure_command(t_command **head, t_command **tail,
					t_command **current, bool pipe_before);

/* Command management */
t_command		*command_new(void);
int				command_add_word(t_command *cmd, const t_tokens *token);

/* List operations */
void			command_add_back(t_command **head, t_command *node);
void			free_command_list(t_command **head);

/* Redirection handling */
int				command_add_redir(t_command *cmd, t_token_type type,
					  const t_tokens *token);
void			free_redir_list(t_redir *redir);

/* Parser utils */
char			*parser_token_value(const t_tokens *token);

// ERROR_MANAGER
/* syntax_error.c */
void			syntax_error(char *token, t_shell *sh);

// EXECUTION
/* pipex.c */
int				pipex(int ac, char **av, char **envp);

/* pipex_utils.c */
void			free_split(char **array);
char			*px_find_path(char *cmd, char **envp);

/* pipex_exec.c */
int				px_exec(char *cmd, char **envp);

#endif
