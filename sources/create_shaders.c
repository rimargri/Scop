/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shaders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:21:26 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/11 18:05:56 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_vertex_shader(t_scop *scop)
{
	const char* vertex_shader =
	"#version 400\n"
	"layout (location = 0) in vec3 vp;"
	"uniform mat4 mvp;"
	"void main() {"
	"  gl_Position = mvp * vec4(vp, 1.0);"
	"}";

	scop->opengl->vert_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(scop->opengl->vert_shader, 1, &vertex_shader, NULL);
	glCompileShader(scop->opengl->vert_shader);
}

void	create_fragment_shader(t_scop *scop)
{
	const char* fragment_shader =
	"#version 400\n"
	"out vec4 frag_colour;"
	"void main() {"
	"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
	"}";

	scop->opengl->fragm_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(scop->opengl->fragm_shader, 1, &fragment_shader, NULL);
	glCompileShader(scop->opengl->fragm_shader);
}

void	create_shaders(t_scop *scop)
{
	create_vertex_shader(scop);
	create_fragment_shader(scop);
}
