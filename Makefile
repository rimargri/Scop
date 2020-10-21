# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 19:22:37 by f0rsunka          #+#    #+#              #
#    Updated: 2020/10/21 13:33:28 by f0rsunka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m
RED = \033[38;2;200;30;70m
YELLOW = \033[38;2;200;200;50m
GREEN = \033[38;2;0;200;0m


NAME = scop

SRC_DIR =	./sources

OBJ_DIR = ./obj

INCL_DIR = ./includes

INCLUDES = -I $(INCL_DIR)

C_FILES =	Errors.cpp \
			GLContext.cpp \
			GLObject.cpp \
			Shader.cpp \
			Shape.cpp \
			main.cpp

OBJ_FILES = $(C_FILES:.cpp=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

CFLAGS = -Wall -Wextra

# CFLAGS += -Werror

DEBUG_FLAG = -fsanitize=address

OS = $(shell uname -s)

ifeq ($(OS),Linux)
	# LIBS	:= -lGL -lglfw -lglut -lGLU
	# LIBS	:= -lepoxy -lGL -lglfw -lglut -lGLU `pkg-config --static --libs glfw3` `pkg-config --static --libs gl`


# without glut
	# LIBS	:= -lepoxy -lGL -lglfw `pkg-config --static --libs glfw3` `pkg-config --static --libs gl`
	LIBS	:=  -lGLEW -lepoxy -lGL -lglfw `pkg-config --static --libs glfw3`


	# LIBS := -lglut -lGLU -lGL
else
	LIBS	:= -lm -L ~/.brew/lib -lglfw -lglew -framework OpenGL
	INCLUDES += -I ~/.brew/include
endif


all: $(OBJ_DIR) $(NAME) 

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)
	@g++ -std=c++17 $(RAW_OBJ_FILES) $(LIBS) -o $(NAME)
	@echo "$(PINK)(*≧ω≦*)  $(BLUE)Mama, ya sobralsya  $(PINK)(*≧ω≦*)\033[0m"

#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCL_DIR)/*.hpp
	@g++ $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all


