/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:11:37 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/07 16:59:45 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_vec4	scale_matrix(t_vec3 scale_value, t_vec4 vertex)
{
	t_vec4 transform_vec;
	t_mat4 scale_matrix;

	scale_matrix.a = scale_value.x;
	scale_matrix.b = 0.0f;
	scale_matrix.c = 0.0f;
	scale_matrix.d = 0.0f;

	scale_matrix.e = 0.0f;
	scale_matrix.f = scale_value.y;
	scale_matrix.g = 0.0f;
	scale_matrix.h = 0.0f;

	scale_matrix.i = 0.0f;
	scale_matrix.j = 0.0f;
	scale_matrix.k = scale_value.z;
	scale_matrix.l = 0.0f;

	scale_matrix.m = 0.0f;
	scale_matrix.n = 0.0f;
	scale_matrix.o = 0.0f;
	scale_matrix.p = 1.0f;
	transform_vec = mult_matrix_on_vertex(scale_matrix, vertex);
	return (transform_vec);
}
