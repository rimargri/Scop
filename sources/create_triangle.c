/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:12:11 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/15 17:23:09 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	sc_get_vertex_triangle(t_triangle  *triangle)
{
	// positions          // colors           // texture coords
	
	if (!(triangle->array_vertex = malloc(sizeof(float) * COUNT_POINTS)))
		exit(88); // ERROR: MALLOC

	// triangle->array_vertex = {0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
    //  0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    // -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    // -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	// };
	
	triangle->array_vertex[0] = -1.0f;
	triangle->array_vertex[1] = -1.0f;
	triangle->array_vertex[2] = 0.0f;
	
	triangle->array_vertex[3] = 1.0f;
	triangle->array_vertex[4] = -1.0f;
	triangle->array_vertex[5] = 0.0f;
	
	triangle->array_vertex[6] = 0.0f;
	triangle->array_vertex[7] = 1.0f;
	triangle->array_vertex[8] = 0.0f;
	
	// triangle->array_vertex[9] = -1.0f;
	// triangle->array_vertex[10] = -1.0f;
	// triangle->array_vertex[11] = 0.0f;
	
	// triangle->array_vertex[12] = 1.0f;
	// triangle->array_vertex[13] = -1.0f;
	// triangle->array_vertex[14] = 0.0f;
	
	// triangle->array_vertex[15] = 0.0f;
	// triangle->array_vertex[16] = 1.0f;
	// triangle->array_vertex[17] = 0.0f;
	
	// triangle->array_vertex[18] = -1.0f;
	// triangle->array_vertex[19] = -1.0f;
	// triangle->array_vertex[20] = 0.0f;
	
	// triangle->array_vertex[21] = 0.0f;
	// triangle->array_vertex[22] = 1.0f;
	// triangle->array_vertex[23] = -1.0f;
	
	// triangle->array_vertex[24] = 0.0f;
	// triangle->array_vertex[25] = 0.0f;
	// triangle->array_vertex[26] = 1.0f;
	
	// triangle->array_vertex[27] = 0.0f;
	// triangle->array_vertex[28] = -1.0f;
	// triangle->array_vertex[29] = -1.0f;
	
	// triangle->array_vertex[30] = 0.0f;
	// triangle->array_vertex[31] = 0.0f;
	// triangle->array_vertex[32] = 1.0f;
	return (1);
}

void	init_vertex_array_object(t_gl *gl, float *array_vertex)
{
	glGenBuffers(1, &gl->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	glBufferData(GL_ARRAY_BUFFER, COUNT_POINTS * sizeof(float), array_vertex, GL_STATIC_DRAW);
}

void	init_vertex_buffer_object(t_gl *gl)
{
	glGenVertexArrays(1, &gl->vao);
	glBindVertexArray(gl->vao);
}

void	init_vertex_attrib(void)
{
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
}

void	create_triangle(t_scop *s)
{
	t_triangle  triangle;

	sc_get_vertex_triangle(&triangle);		
	init_vertex_array_object(s->gl, triangle.array_vertex);
	init_vertex_buffer_object(s->gl);
	init_vertex_attrib();
}
