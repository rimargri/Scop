/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shaders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:21:26 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/17 19:22:26 by f0rsunka         ###   ########.fr       */
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
	scop->opengl.shader_programme = glCreateProgram();
	glAttachShader(scop->opengl.shader_programme, scop->opengl.fragm_shader);
	glAttachShader(scop->opengl.shader_programme, scop->opengl.vert_shader);
	glLinkProgram(scop->opengl.shader_programme);
	glDeleteShader(scop->opengl.vert_shader);
	glDeleteShader(scop->opengl.fragm_shader);
	glGetShaderiv(scop->opengl.shader_programme, GL_LINK_STATUS, &lparams);
	// printf("%u %d\n", GL_TRUE, lparams);
	// if (GL_TRUE != lparams)
		// error_processing(LINK_ERROR, &scop->opengl.shader_programme);
}

void	create_shaders(t_scop *scop)
{
	const char* vertex_shader =
	"#version 400\n"
	"in vec3 vp;"
	"void main() {"
	"  gl_Position = vec4(vp, 1.0);"
	"}";

	const char* fragment_shader =
	"#version 400\n"
	"out vec4 frag_colour;"
	"void main() {"
	"  frag_colour = vec4(0.5, 0.4, 0.5, 1.0);"
	"}";

	scp_create_vertex_shader(scop, vertex_shader);
	scp_create_fragment_shader(scop, fragment_shader);
	scp_create_program(scop);
}
