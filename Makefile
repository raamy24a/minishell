# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollon <acollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 16:37:52 by acollon           #+#    #+#              #
#    Updated: 2025/09/25 17:15:38 by acollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INC_DIR = includes
LIBFT_DIR = libft
LOGDIR = .logs
LOG = $(LOGDIR)/minishell.logs
LIBFT_LOG = $(LOGDIR)/libft.log
SRCS	= \
		env/init_env.c

OBJS	= $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@ mkdir -p $(LOGDIR)
	@ echo "Building minishell..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I $(INC_DIR) -o $(NAME) >$(LOG) 2>&1 \
	&& echo "Minishell created"

$(LIBFT):
	@ mkdir -p $(LOGDIR)
	@ echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) >$(LIBFT_LOG) 2>&1 \
	&& echo "Libft Compiled"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null
	@ echo "Cleaning libft..."
	@rm -f $(OBJS)
	@ echo "cleaning minishell .o ..."

fclean: clean
	@echo "Cleaning static library..."
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null
	@echo "Binary cleaned"
	@rm -f $(NAME)
	@ rm -rf $(LOGDIR)

re: fclean all

.PHONY: all clean fclean re