/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:38:39 by acollon           #+#    #+#             */
/*   Updated: 2025/11/14 23:56:00 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# include <stddef.h>
# include <stdbool.h>

// LEXER
typedef enum e_token_type
{
        TOK_WORD,
        TOK_PIPE,
        TOK_HEREDOC,
        TOK_REDIR_IN,
        TOK_APPEND,
        TOK_REDIR_OUT,
        TOK_ERROR,
        TOK_EOF
}       t_token_type;

typedef struct s_tokens
{
        t_token_type    type;
        int                             quote;
        char                    *token;
}       t_tokens;

// ENV
typedef struct s_env
{
        char                    *key;
        char                    *value;
        struct s_env    *next;
}       t_env;

typedef enum e_redir_type
{
        REDIR_IN,
        REDIR_OUT,
        REDIR_APPEND,
        REDIR_HEREDOC
}       t_redir_type;

typedef struct s_redir
{
        t_redir_type    type;
        int                             quoted;
        char                    *target;
        struct s_redir  *next;
}       t_redir;

typedef enum e_command_type
{
        CMD_SIMPLE
}       t_command_type;

typedef struct s_command
{
        char                            **argv;
        size_t                          argc;
        t_redir                         *redirs;
        bool                            pipe_before;
        bool                            pipe_after;
        t_command_type          type;
        struct s_command        *next;
}               t_command;

typedef struct s_shell
{
        t_env                   *env;
        t_tokens                *token;
        char                    *error;
        struct s_shell  *next;
}               t_shell;

typedef struct s_pipex
{
        int                             infile;
        int                             outfile;
        int                             prev_fd;
        char                            **envp;
}               t_pipex;

#endif
