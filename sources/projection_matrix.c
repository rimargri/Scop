/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:44:47 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/11 18:09:32 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libmat4/include/libmat4.h"

float	create_value_to_scaling_coodrinate(void)
{
	float scale_value_projection;

	scale_value_projection = 1.0f / (tan(FOV / 2.0f) * (M_PI / 180.0f));
	return (scale_value_projection);
}

void	create_projection_matrix(t_opengl *opengl)
{
	float near = 0.1f;
	float far = 1000.0f;

	opengl->matrix->projection.value[0] = 1.0f / (ASPECT * tan(FOV * DEG2RAD / 2.0f));
	opengl->matrix->projection.value[1] = 0.0f;
	opengl->matrix->projection.value[2] = 0.0f;
	opengl->matrix->projection.value[3] = 0.0f;

	opengl->matrix->projection.value[4] = 0.0f;
	opengl->matrix->projection.value[5] = 1.0f / tan(FOV * DEG2RAD / 2.0f);
	opengl->matrix->projection.value[6] = 0.0f;
	opengl->matrix->projection.value[7] = 0.0f;

	opengl->matrix->projection.value[8] = 0.0f;
	opengl->matrix->projection.value[9] = 0.0f;
	opengl->matrix->projection.value[10] = (near + far) / (far - near);
	opengl->matrix->projection.value[11] = (2.0f * far * near) / (far - near);

	opengl->matrix->projection.value[12] = 0.0f;
	opengl->matrix->projection.value[13] = 0.0f;
	opengl->matrix->projection.value[14] = 1.0f;
	opengl->matrix->projection.value[15] = 1.0f;
}

// try to https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/opengl-perspective-projection-matrix
// In all OpenGL books and references, the perspective projection matrix used in OpenGL is defined as:
