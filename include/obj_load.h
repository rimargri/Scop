/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_load.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:53:20 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/24 21:57:32 by cvernius         ###   ########.fr       */
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

#define MAX_OBJ 5000000

typedef struct s_vertex
{
	float		position;
	float		text_coord;
	float		normal;
}				t_vertex;

typedef struct	s_obj
{
	int			count_attributes;
	int			count_vertexes;
	int			count_indexes;
	float		*vertex_position;
	float		*vertex_position_indexes;
	t_vertex	*vertexes;
}				t_obj;

void	read_obj(const char *filename, t_obj *obj);
void	validate_vertex(t_obj *obj, char *buf, int start, int finish);
void	validate_index(t_obj *obj, char *buf, int start, int finish);

#endif
