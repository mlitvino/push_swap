# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 13:22:45 by mlitvino          #+#    #+#              #
#    Updated: 2025/02/20 14:39:53 by mlitvino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLD_DIR) -I$(LIBFT_DIR)/includes

NAME = push_swap
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./sources
OBJ_DIR = ./objects
LIBFT_DIR = ./libft
INCLD_DIR = ./includes

SRC = \
	checks.c ft_sort.c main.c operations_1.c operations_2.c \
	operations_3.c push_swap.c stk_alloc.c stk_manip.c utils.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
SRCS =  $(addprefix $(SRC_DIR)/, $(SRC))
INCLD = $(INCLD_DIR)/push_swap.h

.SECONDARY: $(OBJ)

all: $(LIBFT) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLD)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all
	make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT) | $(OBJ_DIR)
	$(CC) $(OBJ) $(LIBFT) -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
