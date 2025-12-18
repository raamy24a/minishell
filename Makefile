# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radib <radib@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 16:37:52 by acollon           #+#    #+#              #
#    Updated: 2025/12/18 14:42:23 by radib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell

INC_DIR     = includes
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
READLINE    = -lreadline

LOGDIR      = .logs
LOG         = $(LOGDIR)/minishell.log
LIBFT_LOG   = $(LOGDIR)/libft.log

SRCS        = \
                core/main.c \
                core/init_shell.c \
                core/interactive_shell.c \
                core/prompt_execution.c \
                core/quit_shell.c \
                env/init_env.c \
                lexer/lexer.c \
                lexer/lexer_utils.c \
                lexer/token_manager.c \
                parser/parser_command.c \
                parser/parser_core.c \
                parser/parser_list.c \
                parser/parser_redir.c \
                parser/parser_token.c \
                parser/parser_utils.c \
				built-in/builtin_echo.c \
				built-in/builtin_unset.c \
				built-in/builtin_export.c \
				built-in/builtin_env.c \
				built-in/builtin_cd.c \
				built-in/builtin_exit.c \
				built-in/builtin_pwd.c \
				built-in/env_manipulation.c \
                execution/pipex.c \
                execution/pipex_exec.c \
                execution/pipex_utils.c \
                error_manager/syntax_error.c

OBJS        = $(SRCS:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I $(INC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@mkdir -p $(LOGDIR)
	@echo "Building minishell..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I $(INC_DIR) $(READLINE) -o $(NAME) >$(LOG) 2>&1 \
&& echo "Minishell created"

$(LIBFT):
	@mkdir -p $(LOGDIR)
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) >$(LIBFT_LOG) 2>&1 \
&& echo "Libft compiled"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null
	@echo "Cleaning libft objects..."
	@rm -f $(OBJS)
	@echo "Cleaning minishell .o..."

fclean: clean
	@echo "Cleaning libft archive..."
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null
	@rm -f $(NAME)
	@rm -rf $(LOGDIR)
	@echo "Binary and logs cleaned"

re: fclean all

.PHONY: all clean fclean re
