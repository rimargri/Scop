/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:29:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/07 13:52:07 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_vec4	translate_matrix(t_vec3 shift, t_vec4 vertex)
{
	t_mat4 translate_mat;
	t_vec4 transform_vec;

	translate_mat.a = 1.0f;
	translate_mat.b = 0.0f;
	translate_mat.c = 0.0f;
	translate_mat.d = shift.x;
	translate_mat.e = 0.0f;
	translate_mat.f = 1.0f;
	translate_mat.g = 0.0f;
	translate_mat.h = shift.y;
	translate_mat.i = 0.0f;
	translate_mat.j = 0.0f;
	translate_mat.k = 1.0f;
	translate_mat.l = shift.z;
	translate_mat.m = 0.0f;
	translate_mat.n = 0.0f;
	translate_mat.o = 0.0f;
	translate_mat.p = 1.0f;
	transform_vec = mult_matrix_on_vertex(translate_mat, vertex);
	return (transform_vec);
}
