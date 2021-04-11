/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:06:03 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/11 18:13:48 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmat4/include/libmat4.h"

typedef struct			s_triangle
{
	float				*array_vertex;
}						t_triangle;

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
	t_matrix	*matrix;
	GLuint				program_id;
	GLint				mvp_location;
	t_camera			camera;
}						t_opengl;

typedef struct			s_scop
{
	t_opengl			*opengl;
}						t_scop;
