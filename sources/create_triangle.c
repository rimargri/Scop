/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:12:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/05 18:18:13 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	sc_get_vertex_triangle(t_triangle  *triangle)
{
	if (!(triangle->array_vertex = malloc(sizeof(float) * COUNT_VERTEX)))
		return (0);
	triangle->array_vertex[0] = -1.0f;
	triangle->array_vertex[1] = -1.0f;
	triangle->array_vertex[2] = 0.0f;
	triangle->array_vertex[3] = 1.0f;
	triangle->array_vertex[4] = -1.0f;
	triangle->array_vertex[5] = 0.0f;
	triangle->array_vertex[6] = 0.0f;
	triangle->array_vertex[7] = 1.0f;
	triangle->array_vertex[8] = 0.0f;
	return (1);
}

void	init_vertex_array_object(t_opengl *gl, float *array_vertex)
{
	glGenBuffers(1, &gl->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	glBufferData(GL_ARRAY_BUFFER, COUNT_VERTEX * sizeof(float), array_vertex, GL_STATIC_DRAW);
}

void	init_vertex_buffer_object(t_opengl *gl)
{
	glGenVertexArrays(1, &gl->vao);
	glBindVertexArray(gl->vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void	create_triangle(t_scop *s)
{
	t_triangle  triangle;

	sc_get_vertex_triangle(&triangle);		
	init_vertex_array_object(&s->opengl, triangle.array_vertex);
	init_vertex_buffer_object(&s->opengl);
}
