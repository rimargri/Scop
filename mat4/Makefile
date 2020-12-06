# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/16 16:38:28 by cvernius          #+#    #+#              #
#    Updated: 2020/06/12 14:50:04 by f0rsunka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvector.a

SRC_DIR = ./srcs

OBJ_DIR = ./obj

INCL_DIR = ./include

C_FILES =   vec_add.c \
			mult_vec_const.c \
			vec_diff.c \
			dot_product.c \
			vec_length.c \
			vec_normalize.c \
			mult_vec.c \
			division_vec.c \
			mult_matrix.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

CFLAGS_FINAL = -Wall -Wextra -Werror

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/*.h
	gcc $(CFLAGS_FINAL) -c $< -I $(INCL_DIR) -o $@

$(NAME): $(RAW_OBJ_FILES)
	ar rc $(NAME) $(RAW_OBJ_FILES)
	ranlib $(NAME)

clean:
	rm -fv $(RAW_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all