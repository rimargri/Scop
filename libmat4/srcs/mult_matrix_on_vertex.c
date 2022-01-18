/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix_on_vertex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:14:03 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/03 15:33:22 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_vec4	mult_matrix_on_vertex(t_mat4 matrix, t_vec4 vertex)
{
	t_vec4 transform_vertex;

	transform_vertex.x = matrix.value[0] * vertex.x +
						matrix.value[1] * vertex.y +
						matrix.value[2] * vertex.z +
						matrix.value[3] * vertex.w;
	transform_vertex.y = matrix.value[4] * vertex.x +
						matrix.value[5] * vertex.y +
						matrix.value[6] * vertex.z +
						matrix.value[7] * vertex.w;
	transform_vertex.z = matrix.value[8] * vertex.x +
						matrix.value[9] * vertex.y +
						matrix.value[10] * vertex.z +
						matrix.value[11] * vertex.w;
	transform_vertex.w = matrix.value[12] * vertex.x +
						matrix.value[13] * vertex.y +
						matrix.value[14] * vertex.z +
						matrix.value[15] * vertex.w;
	return (transform_vertex);
}
