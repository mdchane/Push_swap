# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 09:49:18 by mdchane           #+#    #+#              #
#    Updated: 2019/01/31 13:53:38 by mdchane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC_PATH = src_check

SRC_PATH2 = src_push

SRC_NAME = checker.c get_next_line.c stack.c utils.c commands.c

SRC_NAME2 =

OBJ_PATH = obj

OBJ_PATH2 = obj2

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_NAME2 = $(SRC_NAME2:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC2 = $(addprefix $(SRC_PATH)/,$(SRC_NAME2))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@ -Llibft -lft

libft:
	make -C libft/

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) -I . -I libft/ -o $@ -c $<

$(OBJ_PATH2)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(OBJ_PATH2) 2> /dev/null || true
	$(CC) $(FLAGS) -I . -I libft/ -o $@ -c $<

clean:
	make -C libft/ clean
	rm -f $(OBJ) $(OBJ2)
	@rm -rf $(OBJ_PATH) || true
	@rm -rf $(OBJ_PATH2) || true

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all libft clean fclean re
