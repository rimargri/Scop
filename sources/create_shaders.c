/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shaders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:21:26 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/19 18:29:24 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libft/libft.h"

void	validate_compilation(GLint shader, const char *shader_name)
{
	int success;
	char *info;
	int length;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!(success))
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		info = malloc(sizeof(char) * length + 1);
		if (!(info))
			exit(88); // ERROR: MALLOC
		glGetShaderInfoLog(shader, length, NULL, info);
		ft_putstr_fd(shader_name, 2);
		for (int i = 0; i < length; i++)
		{
			ft_putstr_fd((const char*)info, 2);
		}
	}
}

void	create_vertex_shader(t_shader *shader)
{
	shader->vert_id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader->vert_id, 1, &shader->vertex_shader, NULL);	
	glCompileShader(shader->vert_id);
	validate_compilation(shader->vert_id, "vertex shader\n");
}

void	create_fragment_shader(t_shader *shader)
{
	shader->fragm_id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader->fragm_id, 1, &shader->fragment_shader, NULL);
	glCompileShader(shader->fragm_id);
	validate_compilation(shader->fragm_id, "fragm shader\n");
}

void	create_shaders(t_shader *shader, int program_id)
{
	shader->vertex_shader = read_shader("shaders/vertex_shader.vert", shader->vertex_shader);
	shader->fragment_shader = read_shader("shaders/fragment_shader.frag", shader->fragment_shader);
	create_vertex_shader(shader);
	create_fragment_shader(shader);
	glAttachShader(program_id, shader->vert_id);
	glAttachShader(program_id, shader->fragm_id);
}
