# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 19:22:37 by f0rsunka          #+#    #+#              #
#    Updated: 2020/10/04 20:38:08 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m
RED = \033[38;2;200;30;70m
YELLOW = \033[38;2;200;200;50m
GREEN = \033[38;2;0;200;0m


NAME = scop

SRC_DIR = ./sources

OBJ_DIR = ./obj

INCL_DIR = ./include

INCLUDES = -I $(INCL_DIR)

C_FILES =	main.c \
			opengl_inside.c \
			create_triangle.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

CFLAGS = -Wall -Wextra 

# CFLAGS += -Werror

OS = $(shell uname -s)

ifeq ($(OS),Linux)
	LIBS	:= -lGL -lglfw -lepoxy
else
	LIBS	:= -lm -L ~/.brew/lib -lglfw -lglew -framework OpenGL
	INCLUDES += -I ~/.brew/include
endif


all: $(OBJ_DIR) $(NAME) 

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)
	@gcc $(RAW_OBJ_FILES) $(LIBS) -o $(NAME)
	@echo "$(PINK)(*≧ω≦*)  $(BLUE)Mama, ya peresobralsya  $(PINK)(*≧ω≦*)\033[0m"

#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/*.h
	@gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all


