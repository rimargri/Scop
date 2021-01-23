/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shaders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:21:26 by cvernius          #+#    #+#             */
/*   Updated: 2021/01/08 19:08:17 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scp_create_vertex_shader(t_scop *scop, const char *vertex_shader)
{
	int lparams;

	lparams = -1;
	scop->opengl.vert_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(scop->opengl.vert_shader, 1, &vertex_shader, NULL);
	glCompileShader(scop->opengl.vert_shader);
	glGetShaderiv(scop->opengl.vert_shader, GL_COMPILE_STATUS, &lparams);
	if (GL_TRUE != lparams)
		error_processing(ERROR_VERT_SHADER_INDEX, &scop->opengl.vert_shader);
	return (0);
}

int		scp_create_fragment_shader(t_scop *scop, const char *fragment_shader)
{
	int lparams;

	lparams = -1;
	scop->opengl.fragm_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(scop->opengl.fragm_shader, 1, &fragment_shader, NULL);
	glCompileShader(scop->opengl.fragm_shader);
	glGetShaderiv(scop->opengl.fragm_shader, GL_COMPILE_STATUS, &lparams);
	if (GL_TRUE != lparams)
		error_processing(ERROR_FRAGM_SHADER_INDEX, &scop->opengl.fragm_shader);
	return (0);
}

void	scp_create_program(t_scop *scop)
{
	int lparams;

	lparams = -1;
	scop->opengl.program_id = glCreateProgram();
	glAttachShader(scop->opengl.program_id, scop->opengl.fragm_shader);
	glAttachShader(scop->opengl.program_id, scop->opengl.vert_shader);
	glLinkProgram(scop->opengl.program_id);
	glDeleteShader(scop->opengl.vert_shader);
	glDeleteShader(scop->opengl.fragm_shader);
	glGetShaderiv(scop->opengl.program_id, GL_LINK_STATUS, &lparams);
	// printf("%u %d\n", GL_TRUE, lparams);
	// if (GL_TRUE != lparams)
		// error_processing(LINK_ERROR, &scop->opengl.program_id);
}

void	create_shaders(t_scop *scop)
{
	const char* vertex_shader =
	"#version 400\n"
	"layout(location = 0) in vec3 vertex_pos_modelspace;"
	"uniform mat4 mvp;"
	"void main() {"
	"  gl_Position = mvp * vec4(vertex_pos_modelspace, 1.0);"
	// "  gl_Position = vec4(vertex_pos_modelspace, 1.0);"
	"}";

	const char* fragment_shader =
	"#version 400\n"
	"out vec4 frag_colour;"
	"void main() {"
	"  frag_colour = vec4(0.5, 0.4, 0.5, 1.0);"
	"}";

	// scop->opengl.matrix_id = glGetUniformLocation(scop->opengl.program_id, "mvp");
	scp_create_vertex_shader(scop, vertex_shader);
	scp_create_fragment_shader(scop, fragment_shader);
	scp_create_program(scop);
}
