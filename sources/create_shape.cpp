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

void	init_vertex_array_object(t_opengl *gl)
{
	glGenVertexArrays(1, &gl->vao);
	glBindVertexArray(gl->vao);
}

void	init_vertex_buffer_object(t_opengl *gl, std::array<float, COUNT_VERTEX> array_vertex)
{
	glGenBuffers(1, &gl->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(array_vertex), &array_vertex, GL_STATIC_DRAW);
}

void	create_shape(t_scop *s)
{
	t_shape  shape;

	sc_get_vertex_shape(&shape);		
	init_vertex_array_object(&s->opengl);
	init_vertex_buffer_object(&s->opengl, shape.array_vertex);

    glGenBuffers(1, &s->opengl.ebo);
    GLuint elements[] = {
        0, 1, 2,
        2, 1, 3
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->opengl.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}
