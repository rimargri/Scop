/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shape.c                                  :+:      :+:    :+:   	  */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:12:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/17 19:23:48 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scp_create_vertex_array_object(t_opengl *gl)
{
	glGenVertexArrays(1, &gl->array_vertex_id);
	glBindVertexArray(gl->array_vertex_id);
}

void	scp_create_vertex_buffer(t_opengl *gl)
{
	float array_vertex[COUNT_VERTEX * 3] = {0.583f,  0.771f,  0.014f,
											0.609f,  0.115f,  0.436f,
											0.327f,  0.483f,  0.844f,
											0.822f,  0.569f,  0.201f,
											0.435f,  0.602f,  0.223f,
											0.310f,  0.747f,  0.185f,
											0.597f,  0.770f,  0.761f,
											0.559f,  0.436f,  0.730f,
											0.359f,  0.583f,  0.152f,
											0.483f,  0.596f,  0.789f,
											0.559f,  0.861f,  0.639f,
											0.195f,  0.548f,  0.859f,
											0.014f,  0.184f,  0.576f,
											0.771f,  0.328f,  0.970f,
											0.406f,  0.615f,  0.116f,
											0.676f,  0.977f,  0.133f,
											0.971f,  0.572f,  0.833f,
											0.140f,  0.616f,  0.489f,
											0.997f,  0.513f,  0.064f,
											0.945f,  0.719f,  0.592f,
											0.543f,  0.021f,  0.978f,
											0.279f,  0.317f,  0.505f,
											0.167f,  0.620f,  0.077f,
											0.347f,  0.857f,  0.137f,
											0.055f,  0.953f,  0.042f,
											0.714f,  0.505f,  0.345f,
											0.783f,  0.290f,  0.734f,
											0.722f,  0.645f,  0.174f,
											0.302f,  0.455f,  0.848f,
											0.225f,  0.587f,  0.040f,
											0.517f,  0.713f,  0.338f,
											0.053f,  0.959f,  0.120f,
											0.393f,  0.621f,  0.362f,
											0.673f,  0.211f,  0.457f,
											0.820f,  0.883f,  0.371f,
											0.982f,  0.099f,  0.879f};

	// float array_vertex[9] = {-0.5f, -0.5f, 0.0f,
	// 						0.5f, -0.5f, 0.0f,
	// 						-0.5, 0.5f, 0.0f};

	glGenBuffers(1, &gl->buffer_vertex);
	glBindBuffer(GL_ARRAY_BUFFER, gl->buffer_vertex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(array_vertex), array_vertex, GL_STATIC_DRAW);
}

// void	scp_init_vertex_buffer_object(t_opengl *gl)
// {
// 	float array_vertex[36] = {0.232406, -1.216630, 1.133818,
// 							0.232406, -0.745504, 2.843098,
// 							-0.227475, -0.745504, 2.843098,
// 							-0.227475, -1.216630, 1.133818,
// 							0.232407, 1.119982, 1.133819,
// 							0.232406, 1.119982, 1.602814,
// 							-0.227475, 1.119982, 1.602813,
// 							-0.227475, 1.119982, 1.133818,
// 							0.232406, -0.340316, 2.843098,
// 							-0.227475, -0.340316, 2.843098,
// 							0.232407, -0.305193, 1.133819,
// 							0.232407, -0.294496, 2.297937,
// 							-0.227475, -0.305193, 1.133818,
// 							-0.227475, -0.294496, 2.297937,
// 							0.232406, -1.222569, 1.497195,
// 							0.232406, -0.745504, 1.477731,
// 							-0.227475, -0.745504, 1.477731,
// 							-0.227475, -1.222569, 1.497194,
// 							-0.227403, -0.731178, 0.901477,
// 							-0.227403, -0.731178, -0.037620,
// 							0.223704, -0.731178, -0.037620,
// 							0.223704, -0.731178, 0.901477,
// 							-0.227403, 1.119377, 0.901477,
// 							-0.227403, 1.119377, -0.037620,
// 							0.223704, 1.119377, -0.037620,
// 							0.223704, 1.119377, 0.901477,
// 							-0.227403, -0.129772, 0.901477,
// 							-0.227403, 0.551492, 0.384487,
// 							-0.227403, 1.104268, 0.408501,
// 							-0.227403, 0.507336, 0.901477,
// 							0.223704, 0.507336, 0.901477,
// 							0.223704, 1.104269, 0.408501,
// 							0.223704, 0.551492, 0.384487,
// 							0.223704, -0.129772, 0.901477,
// 							-0.227403, 0.634134, -0.037620,
// 							-0.227403, -0.066768, 0.398575,
// 							-0.227403, -0.684649, 0.389681,
// 							-0.227403, -0.075523, -0.037620,
// 							0.223704, 0.634134, -0.037620,
// 							0.223704, -0.066768, 0.398575,
// 							0.223704, -0.684649, 0.389681,
// 							0.223704, -0.075523, -0.037620};


// 	glGenBuffers(1, &gl->buffer_vertex);
// 	glBindBuffer(GL_ARRAY_BUFFER, gl->buffer_vertex);
// 	glBufferData(GL_ARRAY_BUFFER, COUNT_VERTEX * sizeof(float), array_vertex, GL_STATIC_DRAW);
// }

// void	scp_init_vertex_array_object(t_opengl *gl)
// {
// 	glGenVertexArrays(1, &gl->array_vertex_id);
// 	glBindVertexArray(gl->array_vertex_id);
// 	glEnableVertexAttribArray(0);
// 	glBindBuffer(GL_ARRAY_BUFFER, gl->buffer_vertex);
// 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
// }

void	create_shape(t_scop *s)
{
	scp_create_vertex_array_object(&s->opengl);
	scp_create_vertex_buffer(&s->opengl);
	// glEnableVertexAttribArray(0);
	// glBindBuffer(GL_ARRAY_BUFFER, s->opengl.buffer_vertex);
	// glVertexAttribPointer(0, COUNT_VERTEX, GL_FLOAT, GL_FALSE, 0, NULL);





	// t_shape  shape;

	// sc_get_vertex_shape(&shape);

	// scp_init_vertex_buffer_object(&s->opengl);
	// scp_init_vertex_array_object(&s->opengl);
	
	
	// Create an element array

    // glGenBuffers(1, &s->opengl.ebo);

    // GLuint elements[] = {
    //     0, 1, 2,
    //     2, 1, 3
    // };

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->opengl.ebo);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}
