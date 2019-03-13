# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 09:49:18 by mdchane           #+#    #+#              #
#    Updated: 2019/03/13 08:31:41 by mdchane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

HEADER_NAME = libpush.h

CC = gcc

FLAGS = -Wall -Werror -Wextra

HEADER_PATH = includes

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

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

all: $(NAME) $(NAME2)

$(NAME): $(OBJ_PATH) $(OBJ) $(HEADER)
	@make -j -C libft/
	@$(info $(NAME) : Sources compiling...)
	@$(CC) $(FLAGS) $(OBJ) -o $@ -Llibft -lft
	@$(info Executable $(NAME) made)

$(NAME2): $(OBJ_PATH2) $(OBJ2) $(HEADER)
	@make -j -C libft/
	@$(info $(NAME2) : Sources compiling...)
	@$(CC) $(FLAGS) $(OBJ2) -o $@ -Llibft -lft
	@$(info Executable $(NAME2) made)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -I $(HEADER_PATH) -I libft/includes -o $@ -c $<

$(OBJ_PATH2)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -I $(HEADER_PATH) -I libft/includes -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $@

$(OBJ_PATH2):
	@mkdir -p $@

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

.PHONY: all lib clean fclean re
