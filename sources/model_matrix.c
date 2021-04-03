/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:34:08 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/03 19:09:33 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libmat4/include/libmat4.h"
#include "../libvector/include/libvector.h"

// model matrix:
// 1. translate
// 2. rotate
// 3. scale

void translate(t_vec3 translate_value, t_opengl *opengl)
{
	opengl->matrix->translate[0] = 1;
	opengl->matrix->translate[1] = 0;
	opengl->matrix->translate[2] = 0;
	opengl->matrix->translate[3] = translate_value.x;

	opengl->matrix->translate[4] = 0;
	opengl->matrix->translate[5] = 1;
	opengl->matrix->translate[6] = 0;
	opengl->matrix->translate[7] = translate_value.y;

	opengl->matrix->translate[8] = 0;
	opengl->matrix->translate[9] = 0;
	opengl->matrix->translate[10] = 1;
	opengl->matrix->translate[11] = translate_value.z;

	opengl->matrix->translate[12] = 0;
	opengl->matrix->translate[13] = 0;
	opengl->matrix->translate[14] = 0;
	opengl->matrix->translate[15] = 1;
}

void scale(t_vec3 scale_value, t_opengl *opengl)
{
	opengl->matrix->scale[0] = scale_value.x;
	opengl->matrix->scale[1] = 0;
	opengl->matrix->scale[2] = 0;
	opengl->matrix->scale[3] = 0;

	opengl->matrix->scale[4] = 0;
	opengl->matrix->scale[5] = scale_value.y;
	opengl->matrix->scale[6] = 0;
	opengl->matrix->scale[7] = 0;

	opengl->matrix->scale[8] = 0;
	opengl->matrix->scale[9] = 0;
	opengl->matrix->scale[10] = scale_value.z;
	opengl->matrix->scale[11] = 0;

	opengl->matrix->scale[12] = 0;
	opengl->matrix->scale[13] = 0;
	opengl->matrix->scale[14] = 0;
	opengl->matrix->scale[15] = 1;
}

void create_model_matrix(t_opengl *opengl)
{

	// rotation((t_vec3){30, 30, 30}, opengl);

	// opengl->matrix->model_matrix = mult_matrix(opengl->matrix->scale, opengl->matrix->translate);
	// opengl->matrix->model_matrix = mult_matrix(opengl->matrix->translate, opengl->matrix->scale);
	// for (int i = 0; i < 16; i++) {
	// 	printf("%f\n", opengl->matrix->model_matrix[i]);
	// }
}
