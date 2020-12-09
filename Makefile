# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 19:22:37 by f0rsunka          #+#    #+#              #
#    Updated: 2020/12/09 18:05:45 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NORMAL = \033[0m
PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m

NAME = scop

SRC_DIR = ./sources

OBJ_DIR = ./obj

INCL_DIR = ./include

INCLUDES = -I $(INCL_DIR) -I ./libmat4/include

C_FILES =	main.c \
			opengl_init.c \
			create_shaders.c \
			opengl_main_loop.c \
			create_shape.c \
			error_processing.c \
			create_model_mat.c \
			create_model_view_projection_mat.c \
			create_view_mat.c

C_FILES_PERSPECTIVE_MAT =   build_perspective_projection.c \
							create_frustum.c \
							create_perspective.c \
							mapping_depth.c \
							scale_view_window.c 

OBJ_FILES = $(C_FILES:.c=.o)
OBJ_FILES_PERSPECTIVE = $(C_FILES_PERSPECTIVE_MAT:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/all_,$(OBJ_FILES))
RAW_OBJ_FILES_PERSPECTIVE = $(addprefix $(OBJ_DIR)/persp_,$(OBJ_FILES_PERSPECTIVE))

# DEPS = $(RAW_OBJ_FILES:.o =.d)
# DEPS_PERSPECTIVE = $(RAW_OBJ_FILES_PERSPECTIVE:.o =.d)

CFLAGS = -Wall -Wextra 

# CFLAGS += -Werror

LIBVECTOR_FLAGS = -L ./libvector -lvector

MAT4_FLAGS = -L ./libmat4 -lmat4

OS = $(shell uname -s)

ifeq ($(OS),Linux)
	LIBS	:= -lepoxy -lGL -lglfw `pkg-config --static --libs glfw3` `pkg-config --static --libs gl`
else
	LIBS	:= -lm -L ~/.brew/lib -lglfw -framework OpenGL
	INCLUDES += -I ~/.brew/include
endif


all: $(OBJ_DIR) $(NAME) 

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES) $(RAW_OBJ_FILES_PERSPECTIVE)
	@make -C ./libvector
	@echo "$(BLUE)(*≧ω≦*) $(PINK)Libvector's build was done $(BLUE)(*≧ω≦*) $(NORMAL)"
	@make -C ./libmat4
	@echo "$(BLUE)(*≧ω≦*) $(PINK)Mat4's build was done $(BLUE)(*≧ω≦*) $(NORMAL)"
	# @gcc $(RAW_OBJ_FILES) $(LIBS) $(LIBVECTOR_FLAGS) $(MAT4_FLAGS) -o $(NAME)
	@gcc $(RAW_OBJ_FILES) $(RAW_OBJ_FILES_PERSPECTIVE) $(LIBS) $(MAT4_FLAGS) $(LIBVECTOR_FLAGS) -o $(NAME)
	@echo "$(BLUE)(*≧ω≦*) $(PINK)Build was done $(BLUE)(*≧ω≦*) $(NORMAL)"

#### К о м п и л я ц и я ####

$(OBJ_DIR)/all_%.o: $(SRC_DIR)/%.c $(INCL_DIR)/*.h
	@gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/persp_%.o: $(SRC_DIR)/build_perspective_matrix/%.c $(INCL_DIR)/*.h
	@gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES) $(RAW_OBJ_FILES_PERSPECTIVE)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C ./libvector fclean
	$(MAKE) -C ./libmat4 fclean

re: fclean all


