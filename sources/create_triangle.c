/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:12:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/17 19:23:48 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	sc_get_vertex_shape(t_shape  *shape)
{
	if (!(shape->array_vertex = malloc(sizeof(float) * COUNT_VERTEX)))
		error_processing(MLX_ERROR, 0);
	shape->array_vertex[0] = -0.5f;
	shape->array_vertex[1] = -0.5f;
	shape->array_vertex[2] = 0.0f;

	shape->array_vertex[3] = 0.5f;
	shape->array_vertex[4] = -0.5f;
	shape->array_vertex[5] = 0.0f;

	shape->array_vertex[6] = -0.5f;
	shape->array_vertex[7] = 0.5f;
	shape->array_vertex[8] = 0.0f;

	shape->array_vertex[9] = 0.5f;
	shape->array_vertex[10] = 0.5f;
	shape->array_vertex[11] = 0.0f;

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

void	create_shape(t_scop *s)
{
	t_shape  shape;

	sc_get_vertex_shape(&shape);		
	init_vertex_array_object(&s->opengl, shape.array_vertex);
	init_vertex_buffer_object(&s->opengl);
	// Create an element array

    glGenBuffers(1, &s->opengl.ebo);

    GLuint elements[] = {
        0, 1, 2,
        2, 1, 3
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->opengl.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}
