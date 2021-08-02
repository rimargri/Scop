/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube_skybox.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:23:37 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 18:33:55 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void create_cube_skybox(t_scop *s)
{
	float points[] = {
	  -1.0f,  1.0f, -1.0f,
	  -1.0f, -1.0f, -1.0f,
	   1.0f, -1.0f, -1.0f,
	   1.0f, -1.0f, -1.0f,
	   1.0f,  1.0f, -1.0f,
	  -1.0f,  1.0f, -1.0f,
	  
	  -1.0f, -1.0f,  1.0f,
	  -1.0f, -1.0f, -1.0f,
	  -1.0f,  1.0f, -1.0f,
	  -1.0f,  1.0f, -1.0f,
	  -1.0f,  1.0f,  1.0f,
	  -1.0f, -1.0f,  1.0f,
	  
	   1.0f, -1.0f, -1.0f,
	   1.0f, -1.0f,  1.0f,
	   1.0f,  1.0f,  1.0f,
	   1.0f,  1.0f,  1.0f,
	   1.0f,  1.0f, -1.0f,
	   1.0f, -1.0f, -1.0f,
	   
	  -1.0f, -1.0f,  1.0f,
	  -1.0f,  1.0f,  1.0f,
	   1.0f,  1.0f,  1.0f,
	   1.0f,  1.0f,  1.0f,
	   1.0f, -1.0f,  1.0f,
	  -1.0f, -1.0f,  1.0f,
	  
	  -1.0f,  1.0f, -1.0f,
	   1.0f,  1.0f, -1.0f,
	   1.0f,  1.0f,  1.0f,
	   1.0f,  1.0f,  1.0f,
	  -1.0f,  1.0f,  1.0f,
	  -1.0f,  1.0f, -1.0f,
	  
	  -1.0f, -1.0f, -1.0f,
	  -1.0f, -1.0f,  1.0f,
	   1.0f, -1.0f, -1.0f,
	   1.0f, -1.0f, -1.0f,
	  -1.0f, -1.0f,  1.0f,
	   1.0f, -1.0f,  1.0f
	};
	glGenBuffers(1, &s->skybox.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, s->skybox.vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * 36 * sizeof(float), &points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &s->skybox.vao);
	glBindVertexArray(s->skybox.vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, s->skybox.vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}
