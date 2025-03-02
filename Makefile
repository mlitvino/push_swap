# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 13:22:45 by mlitvino          #+#    #+#              #
#    Updated: 2025/03/02 03:20:34 by mlitvino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -I$(INCLD_DIR) -I$(LIBFT_DIR)/includes
# -Wall -Wextra -Werror

NAME = push_swap
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./sources
OBJ_DIR = ./objects
LIBFT_DIR = ./libft
INCLD_DIR = ./includes

SRC = \
	checks.c ft_sort.c main.c stk_ops1.c stk_ops2.c \
	stk_ops3.c push_swap.c stk_alloc.c stk_manip.c utils.c \
	sort_arr.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
INCLD = $(INCLD_DIR)/push_swap.h

.SECONDARY: $(OBJ)

all: $(LIBFT) $(NAME) delete_obj_dir

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
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

delete_obj_dir:
	@if [ -z "$$(ls -A $(OBJ_DIR))" ]; then \
	rm -rf $(OBJ_DIR); \
	fi

re: fclean all

.PHONY: all clean fclean re delete_obj_dir
