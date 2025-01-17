# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 19:22:37 by f0rsunka          #+#    #+#              #
#    Updated: 2021/08/02 15:45:19 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PINK="\033[38;2;200;150;200m"
LIGHT_PIRPLE="\033[38;2;200;200;250m"
DEFAULT="\033[0m"
GREEN="\033[0;32m"
DEEP_BLUE="\033[0;34m"


TURQUOISE="\033[0;36m"
PINKNESS="\033[38;2;130;50;250m"

LIGHT_BLUE="\033[38;2;10;130;220m"

NAME = scop

SRC_DIR = ./sources

OBJ_DIR = ./obj

INCL_DIR = ./include

INCLUDES = -I $(INCL_DIR)

C_FILES =	main.c \
			init_glfw.c \
			create_shaders.c \
			render.c \
			create_mesh.c \
			rotate.c \
			model_matrix.c \
			mvp_matrix.c \
			projection_matrix.c \
			read_shader.c \
			read_bmp.c \
			texture.c \
			log.c \
			read_obj.c \
			validate_attributes_obj.c \
			translate_readed_obj_to_struct.c \
			events.c \
			cubemap.c \
			create_shaders_skybox.c \
			create_cube_skybox.c \
			print_micro_menu.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

CFLAGS = -Wall -Wextra -g

# CFLAGS += -Werror

LIBVECTOR_FLAGS = -L ./libvector -lvector

LMAT4_FLAGS = -L ./libmat4 -lmat4

LIBFT_FLAGS = -L ./libft -lft

OS = $(shell uname -s)

ifeq ($(OS),Linux)
	GL_LIBS	:= -lepoxy -lGL -lglut -lGLEW -lm -lglfw `pkg-config --static --libs glfw3` `pkg-config --static --libs gl`
else
	GL_LIBS	:= -lm -L ~/.brew/lib -lglfw -framework OpenGL -lglew
	INCLUDES += -I ~/.brew/include
endif

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(LIGHT_PIRPLE) "				Making libvector	" $(DEFAULT)
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(TURQUOISE)
	$(MAKE) -C ./libvector
	@echo $(DEFAULT)

	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(LIGHT_PIRPLE) "				Making libmat4		" $(DEFAULT)
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(TURQUOISE)
	$(MAKE) -C ./libmat4
	@echo $(DEFAULT)

	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(LIGHT_PIRPLE) "				Making libft		" $(DEFAULT)
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(TURQUOISE)
	$(MAKE) -C ./libft
	@echo $(DEFAULT)

	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(LIGHT_PIRPLE) "				Making scop			" $(DEFAULT)
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(LIGHT_BLUE)
	gcc $(RAW_OBJ_FILES) $(GL_LIBS) $(LIBVECTOR_FLAGS) $(LMAT4_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
	@echo $(PINK)
	@echo "(*≧ω≦*)  "$(LIGHT_PIRPLE)"Mama, ya peresobralsya  "$(PINK)"(*≧ω≦*)"
	@echo $(DEFAULT)

#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/*.h
	@echo $(LIGHT_PIRPLE)
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo $(DEFAULT)

clean: clean_self clean_libs

clean_libs:
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(LIGHT_PIRPLE) "				Clean libs" $(DEFAULT)
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(PINKNESS)
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./libvector clean
	$(MAKE) -C ./libmat4 clean
	@echo $(DEFAULT)

clean_self:
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(LIGHT_PIRPLE) "				Clean self" $(DEFAULT)
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(PINKNESS)
	rm -rf $(RAW_OBJ_FILES)
	@echo $(DEFAULT)

fclean: clean
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(LIGHT_PIRPLE) "				Fclean" $(DEFAULT)
	@echo $(LIGHT_PIRPLE)"*	*	*	*	*	*	*	*	*	*"$(DEFAULT)
	@echo $(PINKNESS)
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./libvector fclean
	$(MAKE) -C ./libmat4 fclean
	@echo $(DEFAULT)

re: fclean all
