/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:38:39 by acollon           #+#    #+#             */
/*   Updated: 2025/10/24 00:51:08 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

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
}	t_token_type;

typedef struct s_tokens
{
	t_token_type	type;
	int				quote;
	char			*token;
}	t_tokens;

// ENV
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	t_env			*env;
	t_tokens		*token;
	char			*error;
	struct	s_shell	*next;
}	t_shell;

#endif