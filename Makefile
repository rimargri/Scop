# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 19:22:37 by f0rsunka          #+#    #+#              #
#    Updated: 2021/04/03 18:54:38 by cvernius         ###   ########.fr        #
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
			opengl_init.c \
			create_shaders.c \
			opengl_main_loop.c \
			create_triangle.c \
			model_matrix.c \
			projection_matrix.c \
			add_matrix_to_opengl.c \
			rotate.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

CFLAGS = -Wall -Wextra 

# CFLAGS += -Werror

LIBVECTOR_FLAGS = -L ./libvector -lvector

LMAT4_FLAGS = -L ./libmat4 -lmat4

OS = $(shell uname -s)

ifeq ($(OS),Linux)
	GL_LIBS	:= -lepoxy -lGL -lglfw `pkg-config --static --libs glfw3` `pkg-config --static --libs gl`
else
	GL_LIBS	:= -lm -L ~/.brew/lib -lglfw -framework OpenGL
	INCLUDES += -I ~/.brew/include
endif


all: $(OBJ_DIR) $(NAME) 

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)
	@gcc $(RAW_OBJ_FILES) $(GL_LIBS) $(LIBVECTOR_FLAGS) $(LMAT4_FLAGS) -o $(NAME)
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
