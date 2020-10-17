/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:06:03 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/17 19:24:22 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_shape
{
	float		*array_vertex;
}				t_shape;

typedef struct	s_opengl
{
	GLFWwindow	*window;
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;
	GLuint		vert_shader;
	GLuint		fragm_shader;
	GLuint		shader_programme;
}				t_opengl;

typedef struct	s_scop
{
	t_opengl	opengl;
	GLuint		vertex_buffer;
}				t_scop;
