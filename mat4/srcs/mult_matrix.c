/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:14:03 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/06 20:42:44 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_vec4	mult_matrix_vertex(t_mat4 matrix, t_vec4 vertex)
{
	t_vec4 transform_vertex;

	transform_vertex.x = matrix.a * vertex.x +
						matrix.b * vertex.y +
						matrix.c * vertex.z +
						matrix.d * vertex.w;
	transform_vertex.y = matrix.e * vertex.x +
						matrix.f * vertex.y +
						matrix.g * vertex.z +
						matrix.h * vertex.w;
	transform_vertex.z = matrix.i * vertex.x +
						matrix.g * vertex.y +
						matrix.k * vertex.z +
						matrix.l * vertex.w;
	transform_vertex.w = matrix.m * vertex.x +
						matrix.n * vertex.y +
						matrix.o * vertex.z +
						matrix.p * vertex.w;
	return (transform_vertex);
}
