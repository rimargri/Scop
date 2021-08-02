/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:12:11 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 18:42:16 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "log_scop.h"

void	init_vertex_array_object(t_gl *gl, float *array_vertex)
{
	glGenBuffers(1, &gl->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	glBufferData(GL_ARRAY_BUFFER, gl->count_vertexes * sizeof(float), array_vertex, GL_STATIC_DRAW);
}

void	init_vertex_buffer_object(t_gl *gl)
{
	glGenVertexArrays(1, &gl->vao);
	glBindVertexArray(gl->vao);
}

void	init_vertex_attrib(void)
{
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void	create_mesh(t_scop *s)
{
	init_vertex_array_object(s->gl, s->obj.final_vertexes);
	init_vertex_buffer_object(s->gl);
	init_vertex_attrib();
}
