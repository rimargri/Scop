/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_matrix_to_opengl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:06:50 by cvernius          #+#    #+#             */
/*   Updated: 2021/03/14 20:53:47 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#include <stdio.h>

void add_matrix_to_opengl(t_opengl *opengl)
{
	opengl->program_id = glCreateProgram();
	unsigned int scale_location = glGetUniformLocation(opengl->program_id, "scale");
	printf("id == %d\n", opengl->program_id);
	// printf("scale_location = %d\n", scale_location);

	glUniformMatrix4fv(scale_location, 1, GL_FALSE, opengl->matrix.scale);

}
