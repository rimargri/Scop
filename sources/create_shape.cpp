/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shape.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:12:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/05 18:39:08 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.hpp"

void	sc_get_vertex_shape(t_shape  *shape)
{
	shape->array_vertex = new float(COUNT_VERTEX);
	printf("sc_get_vertex_shape\n");
	if (!(shape->array_vertex))
		error_processing(MALLOC_ERROR, 0);
	printf("1\n");
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

void	init_vertex_buffer_object(t_opengl *gl, float *array_vertex)
{
	printf("inside\n");

	glGenBuffers(1, &gl->vbo);
	printf("glGenBuffers\n");
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	printf("glBindBuffer\n");
	glBufferData(GL_ARRAY_BUFFER, COUNT_VERTEX * sizeof(float), array_vertex, GL_STATIC_DRAW);
	printf("glBufferData\n");
}

void	init_vertex_array_object(t_opengl *gl)
{
	printf("inside x2\n");
	glGenVertexArrays(1, &gl->vao);
	printf("glGenVertexArrays\n");

	glBindVertexArray(gl->vao);
	printf("glBindVertexArray\n");
	glEnableVertexAttribArray(0);
	printf("glEnableVertexAttribArray\n");
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	printf("glBindBuffer\n");
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	printf("glVertexAttribPointer\n");
}

void	create_shape(t_scop *s)
{
	t_shape  shape;

	sc_get_vertex_shape(&shape);		
	init_vertex_buffer_object(&s->opengl, shape.array_vertex);
	init_vertex_array_object(&s->opengl);
	printf("wtf\n");
	// Create an element array

    glGenBuffers(1, &s->opengl.ebo);
    GLuint elements[] = {
        0, 1, 2,
        2, 1, 3
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->opengl.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}
