/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shaders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:21:26 by cvernius          #+#    #+#             */
/*   Updated: 2021/08/02 15:46:11 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libft/libft.h"
#include "log_scop.h"
#include "shader_load.h"

void	validate_compilation(GLint shader, const char *shader_name)
{
	int success;
	char *info;
	int length;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!(success))
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		info = malloc(sizeof(char) * (length + 1));
		if (!(info))
			log_scop("Shader::Malloc can't allocate memory\0", (enum errors)malloc_error);
		glGetShaderInfoLog(shader, length, NULL, info);
		ft_putstr_fd(shader_name, 2);
		ft_putstr_fd((const char*)info, 2);
	}
}

void	create_vertex_shader(t_shader *shader)
{
	shader->vert_id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader->vert_id, 1, (const GLchar *const *)&shader->vertex_shader, NULL);	
	glCompileShader(shader->vert_id);
	validate_compilation(shader->vert_id, "vertex shader\n");
}

void	create_fragment_shader(t_shader *shader)
{
	shader->fragm_id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader->fragm_id, 1, (const GLchar *const *)&shader->fragment_shader, NULL);
	glCompileShader(shader->fragm_id);
	validate_compilation(shader->fragm_id, "fragm shader\n");
}

void	create_shaders(t_shader *shader, GLuint *program_id)
{
	*program_id = glCreateProgram();
	shader->vertex_shader = read_shader("shaders/vertex_shader.vert");
	shader->fragment_shader = read_shader("shaders/fragment_shader.frag");
	create_vertex_shader(shader);
	create_fragment_shader(shader);
	glAttachShader(*program_id, shader->vert_id);
	glAttachShader(*program_id, shader->fragm_id);
	glLinkProgram(*program_id);
}
