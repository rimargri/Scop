/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:06:03 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 19:18:48 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef struct	s_shape
// {
// 	float		*array_vertex;
// }				t_shape;

#include "../libmat4/include/mat4.h"

typedef struct	s_mat
{
	t_mat4		projection;
	t_mat4		view;
	t_mat4		model;
	t_mat4		mvp;
}				t_mat;

typedef struct	s_opengl
{
	GLFWwindow	*window;
	GLuint		buffer_vertex;
	GLuint		array_vertex_id;
	// GLuint		ebo;
	GLuint		vert_shader;
	GLuint		fragm_shader;
	GLuint		program_id;
	GLuint		matrix_id;
	float		**mvp;
}				t_opengl;


typedef struct	s_frustum
{
	float		left;
	float		right;
	float		top;
	float		bottom;
}				t_frustum;

typedef struct	s_scop
{
	t_opengl	opengl;
	t_frustum	frustum;
}				t_scop;
