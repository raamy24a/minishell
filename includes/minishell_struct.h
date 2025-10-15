/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:38:39 by acollon           #+#    #+#             */
/*   Updated: 2025/09/29 11:40:24 by acollon          ###   ########.fr       */
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
	struct s_token	*next;
}	t_tokens;

// ENV
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_minishell
{
	t_env		*env;
	t_tokens	*token;
	char		*error;
}	t_minishell;

#endif