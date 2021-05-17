/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:12:11 by cvernius          #+#    #+#             */
/*   Updated: 2021/05/17 19:32:36 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "log_scop.h"

int		get_vertex_triangle(t_triangle  *triangle)
{
	if (!(triangle->array_vertex = malloc(sizeof(float) * COUNT_VERTEX * 3)))
		log_scop("Shape::Malloc can't allocate memory\n", (enum errors)malloc_error);

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

void	init_vertex_array_object(t_gl *gl, float *array_vertex)
{
	glGenBuffers(1, &gl->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	glBufferData(GL_ARRAY_BUFFER, COUNT_VERTEX * 3 * sizeof(float), array_vertex, GL_STATIC_DRAW);
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
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
}

void	create_triangle(t_scop *s)
{
	t_triangle  triangle;

	get_vertex_triangle(&triangle);
	init_vertex_array_object(s->gl, triangle.array_vertex);
	init_vertex_buffer_object(s->gl);
	init_vertex_attrib();
}


// !!!
// !!!
// CHECK THE VALID WITH SUCCESS AND OUTPUT:
// https://learnopengl.com/Getting-started/Hello-Triangle
