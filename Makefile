# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollon <acollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 16:37:52 by acollon           #+#    #+#              #
#    Updated: 2025/11/06 11:08:10 by acollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell

INC_DIR     = includes
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

LOGDIR      = .logs
LOG         = $(LOGDIR)/minishell.log
LIBFT_LOG   = $(LOGDIR)/libft.log

SRCS        = \
		env/init_env.c \
		lexer/lexer.c \
		lexer/lexer_utils.c \
		lexer/token_manager.c

OBJS        = $(SRCS:.c=.o)

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@mkdir -p $(LOGDIR)
	@echo "Building minishell..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I $(INC_DIR) -o $(NAME) >$(LOG) 2>&1 \
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
