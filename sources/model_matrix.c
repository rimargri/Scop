/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:34:08 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/04 19:08:55 by cvernius         ###   ########.fr       */
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
	opengl->matrix->translate.value[0] = 1;
	opengl->matrix->translate.value[1] = 0;
	opengl->matrix->translate.value[2] = 0;
	opengl->matrix->translate.value[3] = translate_value.x;

	opengl->matrix->translate.value[4] = 0;
	opengl->matrix->translate.value[5] = 1;
	opengl->matrix->translate.value[6] = 0;
	opengl->matrix->translate.value[7] = translate_value.y;

	opengl->matrix->translate.value[8] = 0;
	opengl->matrix->translate.value[9] = 0;
	opengl->matrix->translate.value[10] = 1;
	opengl->matrix->translate.value[11] = translate_value.z;

	opengl->matrix->translate.value[12] = 0;
	opengl->matrix->translate.value[13] = 0;
	opengl->matrix->translate.value[14] = 0;
	opengl->matrix->translate.value[15] = 1;
}

void scale(t_vec3 scale_value, t_opengl *opengl)
{
	opengl->matrix->scale.value[0] = scale_value.x;
	opengl->matrix->scale.value[1] = 0;
	opengl->matrix->scale.value[2] = 0;
	opengl->matrix->scale.value[3] = 0;

	opengl->matrix->scale.value[4] = 0;
	opengl->matrix->scale.value[5] = scale_value.y;
	opengl->matrix->scale.value[6] = 0;
	opengl->matrix->scale.value[7] = 0;

	opengl->matrix->scale.value[8] = 0;
	opengl->matrix->scale.value[9] = 0;
	opengl->matrix->scale.value[10] = scale_value.z;
	opengl->matrix->scale.value[11] = 0;

	opengl->matrix->scale.value[12] = 0;
	opengl->matrix->scale.value[13] = 0;
	opengl->matrix->scale.value[14] = 0;
	opengl->matrix->scale.value[15] = 1;
}

void create_model_matrix(t_opengl *opengl)
{
	translate((t_vec3){0.0, 0.0, 0.0}, opengl);
	rotation((t_vec3){0, 0, 0}, opengl);
	scale((t_vec3){1, 1, 1}, opengl);
	
	opengl->matrix->model = mult_matrix(mult_matrix(opengl->matrix->translate, opengl->matrix->rotate->xyzrotate), opengl->matrix->scale);
}


// SCALE MATRIX.x, .y, .z != 0 								!!!!
// SOLUTION: add indentity matrix to mult.
