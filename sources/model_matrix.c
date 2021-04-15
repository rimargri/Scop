/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:34:08 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/15 17:05:44 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libmat4/include/libmat4.h"
#include "../libvector/include/libvector.h"

// model matrix:
// 1. translate
// 2. rotate
// 3. scale

void translate(t_vec3 translate_value, t_matrix *matrix)
{
	matrix->translate.value[0] = 1;
	matrix->translate.value[1] = 0;
	matrix->translate.value[2] = 0;
	matrix->translate.value[3] = translate_value.x;

	matrix->translate.value[4] = 0;
	matrix->translate.value[5] = 1;
	matrix->translate.value[6] = 0;
	matrix->translate.value[7] = translate_value.y;

	matrix->translate.value[8] = 0;
	matrix->translate.value[9] = 0;
	matrix->translate.value[10] = 1;
	matrix->translate.value[11] = translate_value.z;

	matrix->translate.value[12] = 0;
	matrix->translate.value[13] = 0;
	matrix->translate.value[14] = 0;
	matrix->translate.value[15] = 1;
}

void scale(t_vec3 scale_value, t_matrix *matrix)
{
	matrix->scale.value[0] = scale_value.x;
	matrix->scale.value[1] = 0;
	matrix->scale.value[2] = 0;
	matrix->scale.value[3] = 0;

	matrix->scale.value[4] = 0;
	matrix->scale.value[5] = scale_value.y;
	matrix->scale.value[6] = 0;
	matrix->scale.value[7] = 0;

	matrix->scale.value[8] = 0;
	matrix->scale.value[9] = 0;
	matrix->scale.value[10] = scale_value.z;
	matrix->scale.value[11] = 0;

	matrix->scale.value[12] = 0;
	matrix->scale.value[13] = 0;
	matrix->scale.value[14] = 0;
	matrix->scale.value[15] = 1;
}

void create_model_matrix(t_matrix *matrix)
{
	static float alpha = 0.0f;
	alpha += 1.0f;
	translate((t_vec3){0.0, 0.0, 1.0}, matrix);
	rotate((t_vec3){0, alpha, 0}, matrix);
	scale((t_vec3){1, 1, 1}, matrix);
	
	matrix->model = mult_matrix(mult_matrix(matrix->translate, matrix->rotate->xyzrotate), matrix->scale);
}

// SCALE MATRIX.x, .y, .z != 0 								!!!!
// SOLUTION: add indentity matrix to mult.
