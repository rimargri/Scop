/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shaders_skybox.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:01:52 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/13 19:59:06 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_shader(GLuint *id, char *shader, char *shader_name, int gl_shader_type)
{
	*id = glCreateShader(gl_shader_type);
	glShaderSource(*id, 1, (const GLchar *const *)&shader, NULL);	
	glCompileShader(*id);
	validate_compilation(*id, shader_name);
}

void create_shaders_skybox(t_shader *shader, int *id_shader)
{
	*id_shader = glCreateProgram();
	shader->vertex_shader_skybox = read_shader("shaders/vertex_shader_skybox.vert", NULL);
	shader->fragment_shader_skybox = read_shader("shaders/fragment_shader_skybox.frag", NULL);	
	create_shader(&shader->vert_skybox_id, shader->vertex_shader_skybox, "skybox: vertex shader:\0", GL_VERTEX_SHADER);
	create_shader(&shader->fragm_skybox_id, shader->fragment_shader_skybox, "skybox: fragment shader\0", GL_FRAGMENT_SHADER);
	glAttachShader(*id_shader, shader->vert_skybox_id);
	glAttachShader(*id_shader, shader->fragm_skybox_id);
	glLinkProgram(*id_shader);
}

void test_create_s(char *shader_string, int id_shader_program, int id_shader, char *filepath, int gl_shader_type)
{
	char *shader_name;
	shader_string = read_shader(filepath, NULL);
	if (gl_shader_type == GL_VERTEX_SHADER)
		*shader_name = "skybox: vertex shader\0";
	if (gl_shader_type == GL_FRAGMENT_SHADER)
		*shader_name = "skybox: fragment shader\0";
	create_shader(&id_shader, shader_string, shader_name, GL_VERTEX_SHADER);
	glAttachShader(id_shader_program, id_shader);
}
