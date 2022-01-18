/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:34:22 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/03 15:33:04 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

void	rotation_x(float angle_x, t_mat4 *rotate_x)
{
	rotate_x->value[0] = 1.0f;
	rotate_x->value[1] = 0.0f;
	rotate_x->value[2] = 0.0f;
	rotate_x->value[3] = 0.0f;

	rotate_x->value[4] = 0.0f;
	rotate_x->value[5] = cos(-angle_x);
	rotate_x->value[6] = -sin(-angle_x);
	rotate_x->value[7] = 0.0f;

	rotate_x->value[8] = 0.0f;
	rotate_x->value[9] = sin(-angle_x);
	rotate_x->value[10] = cos(-angle_x);
	rotate_x->value[11] = 0.0f;

	rotate_x->value[12] = 0.0f;
	rotate_x->value[13] = 0.0f;
	rotate_x->value[14] = 0.0f;
	rotate_x->value[15] = 1.0f;
}

void	rotation_y(float angle_y, t_mat4 *rotate_y)
{
	rotate_y->value[0] = cos(-angle_y);
	rotate_y->value[1] = 0.0f;
	rotate_y->value[2] = sin(-angle_y);
	rotate_y->value[3] = 0.0f;

	rotate_y->value[4] = 0.0f;
	rotate_y->value[5] = 1.0f;
	rotate_y->value[6] = 0.0f;
	rotate_y->value[7] = 0.0f;
	
	rotate_y->value[8] = -sin(-angle_y);
	rotate_y->value[9] = 0.0f;
	rotate_y->value[10] = cos(-angle_y);
	rotate_y->value[11] = 0;
	
	rotate_y->value[12] = 0.0f;
	rotate_y->value[13] = 0.0f;
	rotate_y->value[14] = 0.0f;
	rotate_y->value[15] = 1.0f;
}

void	rotation_z(float angle_z, t_mat4 *rotate_z)
{
	rotate_z->value[0] = cos(-angle_z);
	rotate_z->value[1] = -sin(-angle_z);
	rotate_z->value[2] = 0.0f;
	rotate_z->value[3] = 0.0f;

	rotate_z->value[4] = sin(-angle_z);
	rotate_z->value[5] = cos(-angle_z);
	rotate_z->value[6] = 0.0f;
	rotate_z->value[7] = 0.0f;
	
	rotate_z->value[8] = 0.0f;
	rotate_z->value[9] = 0.0f;
	rotate_z->value[10] = 1.0f;
	rotate_z->value[11] = 0.0f;
	
	rotate_z->value[12] = 0.0f;
	rotate_z->value[13] = 0.0f;
	rotate_z->value[14] = 0.0f;
	rotate_z->value[15] = 1.0f;
}

t_vec4	rotation_matrix(t_vec3 angle, t_vec4 vertex)
{
	t_mat4 rotation_mat;
	t_vec4 transform_vec;

	t_mat4 rotate_x;
	t_mat4 rotate_y;
	t_mat4 rotate_z;

	rotation_x(angle.x, &rotate_x);
	rotation_y(angle.y, &rotate_y);
	rotation_z(angle.z, &rotate_z);
	rotation_mat = mult_matrix(mult_matrix(rotate_x, rotate_y), rotate_z);
	transform_vec = mult_matrix_on_vertex(rotation_mat, vertex);
	return (transform_vec);
}
