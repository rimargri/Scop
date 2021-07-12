/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:54:55 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/12 15:00:34 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_color_buffer(t_scop *s)
{
	glGenBuffers(1, &s->gl->color_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, s->gl->color_buffer);
	glBufferData(GL_ARRAY_BUFFER, s->gl->count_vertexes * sizeof(float), s->gl->vertex_color, GL_STATIC_DRAW);
}

void init_attribute_col_buf(t_scop *s)
{
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, s->gl->color_buffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void	create_colors(t_scop *s)
{
	int i;

	i = 0;
	s->gl->vertex_color = malloc(sizeof(float) * s->gl->count_vertexes);
	if(!(s->gl->vertex_color))
		exit(99);
	while (i < s->gl->count_vertexes)
	{
		// float scale = rand() / (float) RAND_MAX
		s->gl->vertex_color[i] = (float)rand()/(float)(RAND_MAX);
		printf("[%d]   %f\n", i, s->gl->vertex_color[i]);
		i++;
	}
	init_color_buffer(s);
	
}
