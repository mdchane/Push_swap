# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 09:49:18 by mdchane           #+#    #+#              #
#    Updated: 2019/02/25 17:25:35 by mdchane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

CC = gcc

FLAGS = -g -Wall -Werror -Wextra

SRC_PATH = src

SRC_NAME = init.c checker.c stack.c utils.c commands.c print.c read.c \
	stk_utils.c

SRC_NAME2 = init.c push_swap.c stack.c utils.c command_buff.c print.c sort.c \
	read.c commands.c quicksort.c min_sort.c minmax.c stk_utils.c

OBJ_PATH = obj

OBJ_PATH2 = obj2

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_NAME2 = $(SRC_NAME2:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC2 = $(addprefix $(SRC_PATH)/,$(SRC_NAME2))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))

all: libft obj_dir $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(FLAGS) $^ -o $@ -Llibft -lft
	@echo "Executable "$(NAME)" made"

$(NAME2): $(OBJ2)
	@echo $(NAME2) ": Sources compiling..."
	@$(CC) $(FLAGS) $^ -o $@ -Llibft -lft
	@echo "Executable "$(NAME2)" made"

libft:
	@make -C libft/

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -I. -I libft/includes -o $@ -c $<

$(OBJ_PATH2)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -I. -I libft/includes -o $@ -c $<

obj_dir:
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH2)

clean:
	@make -C libft/ fclean
	@rm -rf $(OBJ_PATH) || true
	@rm -rf $(OBJ_PATH2) || true
	@echo $(OBJ_PATH)", "$(OBJ_PATH2)" deleted"

fclean: clean
	@rm -f $(NAME) $(NAME2)
	@echo "Executable "$(NAME)", "$(NAME2)" deleted"

re: fclean all
	@echo "Make re done"

.PHONY: all libft clean fclean re obj_dir
