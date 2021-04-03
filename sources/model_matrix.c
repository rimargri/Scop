/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:34:08 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/03 14:15:19 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libmat4/include/libmat4.h"

// model matrix == translation * rotation * scaling

void translation()
{

}

// void rotation()
// {
// 	rotation_x();
// 	rotation_y();
// 	rotation_z();
// }

void scale(t_vec3 scale_value, t_opengl *opengl)
{
	if (!(opengl->matrix = malloc(sizeof(t_matrix))))
		exit(99);

	opengl->matrix->scale[0] = 2;
	opengl->matrix->scale[1] = 0;
	opengl->matrix->scale[2] = 0;
	opengl->matrix->scale[3] = 0;

	opengl->matrix->scale[4] = 0;
	opengl->matrix->scale[5] = 2;
	opengl->matrix->scale[6] = 0;
	opengl->matrix->scale[7] = 0;

	opengl->matrix->scale[8] = 0;
	opengl->matrix->scale[9] = 0;
	opengl->matrix->scale[10] = 2;
	opengl->matrix->scale[11] = 0;

	opengl->matrix->scale[12] = 0;
	opengl->matrix->scale[13] = 0;
	opengl->matrix->scale[14] = 0;
	opengl->matrix->scale[15] = 1;

}

// void create_model_matrix(t_vec3 v)
// {
// 	// float *model_matrix;
// 	// get_memory_mat4(model_matrix);
// }
