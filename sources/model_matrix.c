/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:34:08 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 18:36:28 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libmat4/include/libmat4.h"
#include "../libvector/include/libvector.h"

/*
** *********************************** **
** *********************************** **
**           model matrix			   **
**           1. translate			   **
**           2. rotate	    		   **
**           3. scale	    		   **
** *********************************** **
** *********************************** **
*/

void translate(t_vec3 translate_value, t_matrix *matrix)
{
	matrix->translate.value[0] = 1.0f;
	matrix->translate.value[1] = 0.0f;
	matrix->translate.value[2] = 0.0f;
	matrix->translate.value[3] = translate_value.x;

	matrix->translate.value[4] = 0.0f;
	matrix->translate.value[5] = 1.0f;
	matrix->translate.value[6] = 0.0f;
	matrix->translate.value[7] = translate_value.y;

	matrix->translate.value[8] = 0.0f;
	matrix->translate.value[9] = 0.0f;
	matrix->translate.value[10] = 1.0f;
	matrix->translate.value[11] = translate_value.z;

	matrix->translate.value[12] = 0.0f;
	matrix->translate.value[13] = 0.0f;
	matrix->translate.value[14] = 0.0f;
	matrix->translate.value[15] = 1.0f;
}

void scale(t_vec3 scale_value, t_matrix *matrix)
{
	matrix->scale.value[0] = scale_value.x;
	matrix->scale.value[1] = 0.0f;
	matrix->scale.value[2] = 0.0f;
	matrix->scale.value[3] = 0.0f;

	matrix->scale.value[4] = 0.0f;
	matrix->scale.value[5] = scale_value.y;
	matrix->scale.value[6] = 0.0f;
	matrix->scale.value[7] = 0.0f;

	matrix->scale.value[8] = 0.0f;
	matrix->scale.value[9] = 0.0f;
	matrix->scale.value[10] = scale_value.z;
	matrix->scale.value[11] = 0.0f;

	matrix->scale.value[12] = 0.0f;
	matrix->scale.value[13] = 0.0f;
	matrix->scale.value[14] = 0.0f;
	matrix->scale.value[15] = 1.0f;
}

void create_model_matrix(t_matrix *matrix, t_input_transform *val)
{
	translate((t_vec3){val->translate.x, val->translate.y, val->translate.z}, matrix);
	rotate((t_vec3){val->rotate.x, val->rotate.y, val->rotate.z}, matrix);
	scale((t_vec3){val->scale.x, val->scale.y, val->scale.z}, matrix);

	matrix->model = mult_matrix(mult_matrix(matrix->translate, matrix->rotate->xyzrotate), matrix->scale);
}

// SCALE MATRIX.x, .y, .z != 0 								!!!!
