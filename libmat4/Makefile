# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/16 16:38:28 by cvernius          #+#    #+#              #
#    Updated: 2021/04/03 16:43:42 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmat4.a

SRC_DIR = ./srcs

OBJ_DIR = ./obj

INCL_DIR = ./include

C_FILES =   mult_matrix.c \
			identity_matrix.c
			# rotation_matrix.c \

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

CFLAGS_FINAL = -Wall -Wextra
# CFLAGS_FINAL += -Werror

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/*.h
	gcc $(CFLAGS_FINAL) -I ../libvector/include -I $(INCL_DIR) -c $< -o $@

$(NAME): $(RAW_OBJ_FILES)
	ar rc $(NAME) $(RAW_OBJ_FILES)
	ranlib $(NAME)

clean:
	rm -fv $(RAW_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
