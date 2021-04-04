/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:07:18 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/04 17:26:53 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libvector/include/libvector.h"
#include "../libmat4/include/libmat4.h"

void	rotation_x(float angle_x, t_mat4 *x)
{
	x->value[0] = 1.0f;
	x->value[1] = 0.0f;
	x->value[2] = 0.0f;
	x->value[3] = 0.0f;

	x->value[4] = 0.0f;
	x->value[5] = cos(-angle_x * DEG2RAD);
	x->value[6] = -sin(-angle_x * DEG2RAD);
	x->value[7] = 0.0f;

	x->value[8] = 0.0f;
	x->value[9] = sin(-angle_x * DEG2RAD);
	x->value[10] = cos(-angle_x * DEG2RAD);
	x->value[11] = 0.0f;

	x->value[12] = 0.0f;
	x->value[13] = 0.0f;
	x->value[14] = 0.0f;
	x->value[15] = 1.0f;
}

void	rotation_y(float angle_y, t_mat4 *y)
{
	y->value[0] = cos(-angle_y * DEG2RAD);
	y->value[1] = 0.0f;
	y->value[2] = sin(-angle_y * DEG2RAD);
	y->value[3] = 0.0f;

	y->value[4] = 0.0f;
	y->value[5] = 1.0f;
	y->value[6] = 0.0f;
	y->value[7] = 0.0f;

	y->value[8] = -sin(-angle_y * DEG2RAD);
	y->value[9] = 0.0f;
	y->value[10] = cos(-angle_y * DEG2RAD);
	y->value[11] = 0;

	y->value[12] = 0.0f;
	y->value[13] = 0.0f;
	y->value[14] = 0.0f;
	y->value[15] = 1.0f;
}

void	rotation_z(float angle_z, t_mat4 *z)
{
	z->value[0] = cos(-angle_z * DEG2RAD);
	z->value[1] = -sin(-angle_z * DEG2RAD);
	z->value[2] = 0.0f;
	z->value[3] = 0.0f;

	z->value[4] = sin(-angle_z * DEG2RAD);
	z->value[5] = cos(-angle_z * DEG2RAD);
	z->value[6] = 0.0f;
	z->value[7] = 0.0f;
	
	z->value[8] = 0.0f;
	z->value[9] = 0.0f;
	z->value[10] = 1.0f;
	z->value[11] = 0.0f;
	
	z->value[12] = 0.0f;
	z->value[13] = 0.0f;
	z->value[14] = 0.0f;
	z->value[15] = 1.0f;
}

void	rotation(t_vec3 angle, t_opengl *opengl)
{
	rotation_x(angle.x, &opengl->matrix->rotate->x);
	rotation_y(angle.y, &opengl->matrix->rotate->y);
	rotation_z(angle.z, &opengl->matrix->rotate->z);
	opengl->matrix->rotate->xyzrotate = mult_matrix(mult_matrix(opengl->matrix->rotate->x, opengl->matrix->rotate->y), opengl->matrix->rotate->z);
}
