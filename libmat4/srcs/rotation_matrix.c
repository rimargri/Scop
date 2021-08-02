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
	rotate_x->a = 1.0f;
	rotate_x->b = 0.0f;
	rotate_x->c = 0.0f;
	rotate_x->d = 0.0f;

	rotate_x->e = 0.0f;
	rotate_x->f = cos(-angle_x);
	rotate_x->g = -sin(-angle_x);
	rotate_x->h = 0.0f;

	rotate_x->i = 0.0f;
	rotate_x->j = sin(-angle_x);
	rotate_x->k = cos(-angle_x);
	rotate_x->l = 0.0f;

	rotate_x->m = 0.0f;
	rotate_x->n = 0.0f;
	rotate_x->o = 0.0f;
	rotate_x->p = 1.0f;
}

void	rotation_y(float angle_y, t_mat4 *rotate_y)
{
	rotate_y->a = cos(-angle_y);
	rotate_y->b = 0.0f;
	rotate_y->c = sin(-angle_y);
	rotate_y->d = 0.0f;

	rotate_y->e = 0.0f;
	rotate_y->f = 1.0f;
	rotate_y->g = 0.0f;
	rotate_y->h = 0.0f;
	
	rotate_y->i = -sin(-angle_y);
	rotate_y->j = 0.0f;
	rotate_y->k = cos(-angle_y);
	rotate_y->l = 0;
	
	rotate_y->m = 0.0f;
	rotate_y->n = 0.0f;
	rotate_y->o = 0.0f;
	rotate_y->p = 1.0f;
}

void	rotation_z(float angle_z, t_mat4 *rotate_z)
{
	rotate_z->a = cos(-angle_z);
	rotate_z->b = -sin(-angle_z);
	rotate_z->c = 0.0f;
	rotate_z->d = 0.0f;

	rotate_z->e = sin(-angle_z);
	rotate_z->f = cos(-angle_z);
	rotate_z->g = 0.0f;
	rotate_z->h = 0.0f;
	
	rotate_z->i = 0.0f;
	rotate_z->j = 0.0f;
	rotate_z->k = 1.0f;
	rotate_z->l = 0.0f;
	
	rotate_z->m = 0.0f;
	rotate_z->n = 0.0f;
	rotate_z->o = 0.0f;
	rotate_z->p = 1.0f;
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
