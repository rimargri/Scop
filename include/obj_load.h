/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_load.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:53:20 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/07 18:08:23 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_LOAD_H
# define OBJ_LOAD_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#include "../libft/libft.h"
#include <stdlib.h>

// #include "structures.h"

#define MAX_OBJ 5000000

// typedef struct s_vertex
// {
// 	float		position;
// 	float		text_coord;
// 	float		normal;
// }				t_vertex;

typedef struct	s_obj
{
	int			count_faces;
	int			count_vertexes;
	int			count_indexes;
	int			*count_digit_on_face_line;
	float		*vertex_position;
	int			*faces_vertexes;
	float		*final_vertexes;
	int			count_final_vertexes;
	// t_vertex	*vertexes;
}				t_obj;

// void	read_obj(const char *filename, t_obj *obj, t_gl *gl);
void	validate_vertex(t_obj *obj, char *buf, int start, int finish);
void	validate_faces(t_obj *obj, char *buf, int start, int finish);
int		get_count_attr_in_line(t_obj *obj, char *buf, int start, int finish);
int		get_count_indexes(t_obj *obj, char *buf, int start, int finish);

#endif
