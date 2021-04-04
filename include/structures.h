/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:06:03 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/04 16:36:31 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmat4/include/libmat4.h"

typedef struct			s_triangle
{
	float				*array_vertex;
}						t_triangle;

typedef struct			s_rotate
{
	t_mat4				x;
	t_mat4				y;
	t_mat4				z;
	t_mat4				xyzrotate;
}						t_rotate;

typedef struct			s_transform_matrix
{
	t_mat4				model;
	t_mat4				scale;
	t_mat4				translate;
	t_rotate			*rotate;
}						t_transform_matrix;


// need to be upgraded
// typedef struct	s_shader
// {
// 	GLuint		vertex;
// 	GLuint		fragment;
// }				t_shader;
// 

typedef struct			s_opengl
{
	GLFWwindow			*window;
	GLuint				vbo;
	GLuint				vao;
	GLuint				vert_shader;
	GLuint				fragm_shader;
	// t_shader 	shader;
	t_transform_matrix	*matrix;
	GLuint				program_id;
	GLint 				scale_location;
	GLint 				translate_location;
	GLint				model_location;
	GLint				rotate_location;
}						t_opengl;

typedef struct			s_scop
{
	t_opengl			*opengl;
}						t_scop;
