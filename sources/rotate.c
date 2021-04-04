/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:07:18 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/04 14:55:53 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libvector/include/libvector.h"
#include "../libmat4/include/libmat4.h"

void	rotation_x(float angle_x, float *rotate_x)
{
	rotate_x[0] = 1.0f;
	rotate_x[1] = 0.0f;
	rotate_x[2] = 0.0f;
	rotate_x[3] = 0.0f;

	rotate_x[4] = 0.0f;
	rotate_x[5] = cos(-angle_x * DEG2RAD);
	rotate_x[6] = -sin(-angle_x * DEG2RAD);
	rotate_x[7] = 0.0f;

	rotate_x[8] = 0.0f;
	rotate_x[9] = sin(-angle_x * DEG2RAD);
	rotate_x[10] = cos(-angle_x * DEG2RAD);
	rotate_x[11] = 0.0f;

	rotate_x[12] = 0.0f;
	rotate_x[13] = 0.0f;
	rotate_x[14] = 0.0f;
	rotate_x[15] = 1.0f;
}

void	rotation_y(float angle_y, float *rotate_y)
{
	rotate_y[0] = cos(-angle_y * DEG2RAD);
	rotate_y[1] = 0.0f;
	rotate_y[2] = sin(-angle_y * DEG2RAD);
	rotate_y[3] = 0.0f;

	rotate_y[4] = 0.0f;
	rotate_y[5] = 1.0f;
	rotate_y[6] = 0.0f;
	rotate_y[7] = 0.0f;

	rotate_y[8] = -sin(-angle_y * DEG2RAD);
	rotate_y[9] = 0.0f;
	rotate_y[10] = cos(-angle_y * DEG2RAD);
	rotate_y[11] = 0;

	rotate_y[12] = 0.0f;
	rotate_y[13] = 0.0f;
	rotate_y[14] = 0.0f;
	rotate_y[15] = 1.0f;
}

void	rotation_z(float angle_z, float *rotate_z)
{
	rotate_z[0] = cos(-angle_z * DEG2RAD);
	rotate_z[1] = -sin(-angle_z * DEG2RAD);
	rotate_z[2] = 0.0f;
	rotate_z[3] = 0.0f;

	rotate_z[4] = sin(-angle_z * DEG2RAD);
	rotate_z[5] = cos(-angle_z * DEG2RAD);
	rotate_z[6] = 0.0f;
	rotate_z[7] = 0.0f;
	
	rotate_z[8] = 0.0f;
	rotate_z[9] = 0.0f;
	rotate_z[10] = 1.0f;
	rotate_z[11] = 0.0f;
	
	rotate_z[12] = 0.0f;
	rotate_z[13] = 0.0f;
	rotate_z[14] = 0.0f;
	rotate_z[15] = 1.0f;
}

void	rotation(t_vec3 angle, t_opengl *opengl)
{
	if (!(opengl->matrix->rotate->xyzrotate = malloc(sizeof(GLfloat) * 16)))
		exit(11);

	rotation_x(angle.x, opengl->matrix->rotate->x);
	rotation_y(angle.y, opengl->matrix->rotate->y);
	rotation_z(angle.z, opengl->matrix->rotate->z);
	opengl->matrix->rotate->xyzrotate = mult_matrix(opengl->matrix->rotate->x, opengl->matrix->rotate->y);
	printf("scop\n\n");
	for (int i = 0; i < 16; i++) {
		printf("i = %f\n", opengl->matrix->rotate->xyzrotate[i]);
	}
	// opengl->matrix->rotate->xyzrotate = mult_matrix(mult_matrix(rotation_x, rotation_y), rotation_z);
}
