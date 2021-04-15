/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shaders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:21:26 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/15 16:41:57 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_vertex_shader(t_shader *shader)
{
	shader->vert_id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader->vert_id, 1, &shader->vertex_shader, NULL);	
	glCompileShader(shader->vert_id);
}

void	create_fragment_shader(t_shader *shader)
{
	shader->fragm_id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader->fragm_id, 1, &shader->fragment_shader, NULL);
	glCompileShader(shader->fragm_id);
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
