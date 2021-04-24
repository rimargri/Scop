/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:06:03 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/24 18:36:52 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "../libmat4/include/libmat4.h"
#include "obj_load.h"

typedef struct			s_texture
{
	int					width;
	int					height;
	unsigned char		*data;
	unsigned int		id;
}						t_texture;

typedef struct			s_camera
{
	t_vec3				pos;
	t_vec3				target;
	t_vec3				reverse_dir;
	t_vec3				right;
	t_vec3				up;
}						t_camera;

typedef struct			s_rotate
{
	t_mat4				x;
	t_mat4				y;
	t_mat4				z;
	t_mat4				xyzrotate;
}						t_rotate;

typedef struct			s_matrix		
{
	t_mat4				model;							// model matrix
	t_mat4				scale;							// model matrix
	t_mat4				translate;						// model matrix
	t_rotate			*rotate;						// model matrix
	t_mat4				look_at;						// view matrix
	t_mat4				projection;
	t_mat4				mvp;
}						t_matrix;

typedef struct			s_shader
{
	GLuint				vert_id;
	GLuint				fragm_id;
	char				*vertex_shader;
	char				*fragment_shader;
}						t_shader;

typedef struct			s_triangle
{
	float				*array_vertex;
	// t_mat32				array_points;
}						t_triangle;

typedef struct			s_gl
{
	GLFWwindow			*window;
	GLuint				vbo;
	GLuint				vao;
	GLuint				program_id;
	GLint				mvp_location;
	GLint				model_location;
	GLint				color_location;
}						t_gl;

typedef struct			s_scop
{
	t_gl				*gl;
	t_matrix			*matrix;
	t_camera			camera;
	t_shader			*shader;
	t_texture			texture;
	t_obj				obj;
}						t_scop;

#endif
