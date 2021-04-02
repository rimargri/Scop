/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:34:08 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/02 21:12:44 by cvernius         ###   ########.fr       */
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

	// opengl->matrix.scale = {scale_value.x, 0, 0, 0,
	// 				0, scale_value.y, 0, 0,
	// 				0, 0, scale_value.z, 0,
	// 				0, 0, 0, 1};
	

void scale(t_vec3 scale_value, t_opengl *opengl)
{
	float scale[16];

	scale[0] = scale_value.x;
	scale[1] = 0;
	scale[2] = 0;
	scale[3] = 0;

	scale[4] = 0;
	scale[5] = scale_value.y;
	scale[6] = 0;
	scale[7] = 0;

	scale[8] = 0;
	scale[9] = 0;
	scale[10] = scale_value.z;
	scale[11] = 1;

	scale[12] = 0;
	scale[13] = 0;
	scale[14] = 0;
	scale[15] = 1;

	opengl->scale_location = glGetUniformLocation(opengl->program_id, "scale");

	printf("opengl->scale_location = %d\n", opengl->scale_location);
}

// void create_model_matrix(t_vec3 v)
// {
// 	// float *model_matrix;
// 	// get_memory_mat4(model_matrix);
// }
