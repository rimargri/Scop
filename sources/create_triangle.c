/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:12:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/04 20:45:06 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_vertex_triangle(t_triangle  *triangle)
{
	if (!(triangle->array_vertex = malloc(sizeof(float) * COUNT_VERTEX)))
		return ;
	triangle->array_vertex[0] = -1.0f;
	triangle->array_vertex[0] = -1.0f;
	triangle->array_vertex[0] = 0.0f;
	triangle->array_vertex[0] = 1.0f;
	triangle->array_vertex[0] = -1.0f;
	triangle->array_vertex[0] = 0.0f;
	triangle->array_vertex[0] = 0.0f;
	triangle->array_vertex[0] = 1.0f;
	triangle->array_vertex[0] = 0.0f;
}

void	create_triangle(t_scop *s)
{
	t_triangle  triangle;

	get_vertex_triangle(&triangle);
	glGenBuffers(1, &s->vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, s->vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle.array_vertex), triangle.array_vertex, GL_STATIC_DRAW);
}
