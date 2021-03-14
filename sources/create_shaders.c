/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shaders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:21:26 by cvernius          #+#    #+#             */
/*   Updated: 2021/03/14 20:46:11 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

	// "#version 400\n"
	// "layout (location = 0) in vec3 vp;"
	// "layout (location = 1) in vec2 text_coord;"
	// // "in vec3 vp;"
	// "void main() {"
	// "  gl_Position = vec4(vp, 1.0);"
	// "}";

void	create_vertex_shader(t_scop *scop)
{
	const char* vertex_shader =
	"#version 400\n"
	"layout (location = 0) in vec3 vp;"
	"uniform mat4 scale;"
	"void main() {"
	"  gl_Position = scale * vec4(vp, 1.0);"
	// "  gl_Position = vec4(vp, 1.0);"
	"}";

	scop->opengl.vert_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(scop->opengl.vert_shader, 1, &vertex_shader, NULL);
	glCompileShader(scop->opengl.vert_shader);

}

void	create_fragment_shader(t_scop *scop)
{
	const char* fragment_shader =
	"#version 400\n"
	"out vec4 frag_colour;"
	"void main() {"
	"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
	"}";

	scop->opengl.fragm_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(scop->opengl.fragm_shader, 1, &fragment_shader, NULL);
	glCompileShader(scop->opengl.fragm_shader);

}

void	create_shaders(t_scop *scop)
{
	create_vertex_shader(scop);
	create_fragment_shader(scop);
	
	// scop->opengl.program_id = glCreateProgram();
	// glAttachShader(scop->opengl.program_id, scop->opengl.fragm_shader);
	// glAttachShader(scop->opengl.program_id, scop->opengl.vert_shader);
	// glLinkProgram(scop->opengl.program_id);
}
