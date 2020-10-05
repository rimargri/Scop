/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:06:03 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/05 18:14:58 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_triangle
{
	float		*array_vertex;
}				t_triangle;

typedef struct	s_opengl
{
	GLFWwindow	*window;
	GLuint		vbo;
	GLuint		vao;
	GLuint		vert_shader;
	GLuint		fragm_shader;
	GLuint		shader_programme;
}				t_opengl;

typedef struct	s_scop
{
	t_opengl	opengl;
	GLuint		vertex_buffer;
}				t_scop;
