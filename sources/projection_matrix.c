/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:44:47 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/07 15:58:29 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libmat4/include/libmat4.h"

float	create_value_to_scaling_coodrinate(void)
{
	float scale_value_projction;

	scale_value_projction = 1 / (tan(FOV / 2.0f) * (M_PI / 180));
	return (scale_value_projction);
}

t_mat4 create_projection_matrix(t_opengl *opengl)
{
	float scale_value;
	float near = 0.1f;
	float far = 100.0f;

	// scale_value = create_value_to_scaling_coodrinate();
	// opengl->matrix->projection.value[0] = scale_value;
	// opengl->matrix->projection.value[1] = 0;
	// opengl->matrix->projection.value[2] = 0;
	// opengl->matrix->projection.value[3] = 0;

	// opengl->matrix->projection.value[4] = 0;
	// opengl->matrix->projection.value[5] = scale_value;
	// opengl->matrix->projection.value[6] = 0;
	// opengl->matrix->projection.value[7] = 0;

	// opengl->matrix->projection.value[8] = 0;
	// opengl->matrix->projection.value[9] = 0;
	// opengl->matrix->projection.value[10] = - (f / (f - n));
	// opengl->matrix->projection.value[11] = - 1.0f;

	// opengl->matrix->projection.value[12] = 0;
	// opengl->matrix->projection.value[13] = 0;
	// opengl->matrix->projection.value[14] = - (f * n / (f - n));
	// opengl->matrix->projection.value[15] = 0;



    float scale = 1 / tan(FOV * 0.5 * M_PI / 180); 
    // M[0][0] = scale; // scale the x coordinates of the projected point 


    // M[1][1] = scale; // scale the y coordinates of the projected point 


    // M[2][2] = -far / (far - near); // used to remap z to [0,1] 

    // M[2][3] = -1; // set w = -z 

    // M[3][2] = -far * near / (far - near); // used to remap z [0,1] 
    // M[3][3] = 0;


	opengl->matrix->projection.value[0] = scale;
	opengl->matrix->projection.value[1] = 0;
	opengl->matrix->projection.value[2] = 0;
	opengl->matrix->projection.value[3] = 0;

	opengl->matrix->projection.value[4] = 0;
	opengl->matrix->projection.value[5] = scale;
	opengl->matrix->projection.value[6] = 0;
	opengl->matrix->projection.value[7] = 0;

	opengl->matrix->projection.value[8] = 0;
	opengl->matrix->projection.value[9] = 0;
	opengl->matrix->projection.value[10] = - far / (far - near);
	opengl->matrix->projection.value[11] = - far * near / (far - near);

	opengl->matrix->projection.value[12] = 0;
	opengl->matrix->projection.value[13] = 0;
	opengl->matrix->projection.value[14] = - 1.0f;
	opengl->matrix->projection.value[15] = 0;

}

// try to https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/opengl-perspective-projection-matrix
// In all OpenGL books and references, the perspective projection matrix used in OpenGL is defined as:

