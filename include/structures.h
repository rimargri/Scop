/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:06:03 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/03 19:12:39 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_triangle
{
	float		*array_vertex;
}				t_triangle;

typedef struct	s_rotate
{
	float		x[16];
	float		y[16];
	float		z[16];
	GLfloat		*xyzrotate;
}				t_rotate;

typedef struct	s_matrix
{
	// GLfloat		model_matrix[16];
	GLfloat		*model_matrix;
	GLfloat		scale[16];
	GLfloat		translate[16];
	t_rotate	*rotate;
}				t_matrix;


// need to be upgraded
// typedef struct	s_shader
// {
// 	GLuint		vertex;
// 	GLuint		fragment;
// }				t_shader;
// 

typedef struct	s_opengl
{
	GLFWwindow	*window;
	GLuint		vbo;
	GLuint		vao;
	GLuint		vert_shader;
	GLuint		fragm_shader;
	// t_shader 	shader;
	t_matrix	*matrix;
	GLuint		program_id;
	GLint 		scale_location;
	GLint 		translate_location;
	GLint		model_location;
	GLint		rotate_location;
}				t_opengl;

typedef struct	s_scop
{
	t_opengl	*opengl;
}				t_scop;
