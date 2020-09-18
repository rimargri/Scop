# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 19:22:37 by f0rsunka          #+#    #+#              #
#    Updated: 2020/09/17 19:32:35 by f0rsunka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m
RED = \033[38;2;200;30;70m
YELLOW = \033[38;2;200;200;50m
GREEN = \033[38;2;0;200;0m

NAME = test_openGL

SRC_DIR = ./sources

OBJ_DIR = ./obj

INCL_DIR = ./include

C_FILES = main.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

# MLX_FLAGS = -L ./MinilibX -lm -lmlx -framework OpenGL -framework AppKit

# LIBFT_FLAGS = -L libft/ -lft

# NON_EXISTET	= tfbil

CFLAGS = -Wall -Wextra -Werror

all: $(OBJ_DIR) $(NAME)  #$(NON_EXISTET)

# $(NON_EXISTET):
# 	@make -C ./libft

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)
	# @make -C ./MinilibX
	# @make -sC ./libft
	# @gcc $(RAW_OBJ_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	# @echo "$(PINK)(*≧ω≦*)  $(BLUE)Mama, ya peresobralsya  $(PINK)(*≧ω≦*)\033[0m"

	@gcc $(RAW_OBJ_FILES) -lGL -lglfw -lepoxy -o $(NAME)
	@echo "$(PINK)(*≧ω≦*)  $(BLUE)Mama, ya peresobralsya  $(PINK)(*≧ω≦*)\033[0m"


#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/*.h
	@gcc $(CFLAGS) -I $(INCL_DIR) -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES)
	# @rm -rf ./MinilibX/*.o
	# @rm -rf ./libft/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	# @rm -rf ./MinilibX/libmlx.a
	# @rm -rf ./libft/libft.a

re: fclean all