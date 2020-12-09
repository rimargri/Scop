/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_view_mat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:57:43 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 17:58:58 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#include "../libvector/include/libvector.h"

// https://stackoverflow.com/questions/21830340/understanding-glmlookat

t_mat4	create_view_mat(t_vec3 eye, t_vec3 center, t_vec3 up)
{
	t_mat4 view_mat;
	t_vec3 x_axis;
	t_vec3 y_axis;
	t_vec3 z_axis;

	z_axis = vec_diff(eye, center);
	vec_normalize(z_axis);
	y_axis = up;
	x_axis = cross(y_axis, z_axis);
	y_axis = cross(z_axis, x_axis);
	vec_normalize(x_axis);
	vec_normalize(y_axis);
	view_mat.a = x_axis.x;
	view_mat.b = y_axis.x;
	view_mat.c = z_axis.x;
	view_mat.d = 0.0f;

	view_mat.e = x_axis.y;
	view_mat.f = y_axis.y;
	view_mat.g = z_axis.y;
	view_mat.h = 0.0f;

	view_mat.i = x_axis.z;
	view_mat.j = y_axis.z;
	view_mat.k = z_axis.z;
	view_mat.l = 0.0f;

	view_mat.m = dot_product(mult_vec_const(x_axis, -1), eye);
	view_mat.n = dot_product(mult_vec_const(y_axis, -1), eye);
	view_mat.o = dot_product(mult_vec_const(z_axis, -1), eye);
	view_mat.p = 1.0f;
	return (view_mat);
}