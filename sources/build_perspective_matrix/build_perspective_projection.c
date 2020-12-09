/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_perspective_projection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:26:42 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 19:24:15 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// t_mat4	build_perspective_projection_transform(t_vec4 vertex)
t_mat4	build_perspective_projection(t_scop *s)
{
	t_mat4 frustum_mat;
	t_mat4 mapping_mat;
	t_mat4 perspective_calculation_mat;
	t_mat4 scale_mat;
	t_mat4 perspective_mat;
	t_vec4 transform_vec;

	s->frustum = (t_frustum){-1.0f, 1.0f, -1.0f, 1.0f};
	frustum_mat = create_frustum(s->frustum);
	mapping_mat = mapping_depth();
	perspective_calculation_mat = perspective_calculation();
	scale_mat = scale_view_window(s->frustum);

	perspective_mat = mult_matrix(
								mult_matrix(
											mult_matrix(frustum_mat, mapping_mat),
											perspective_calculation_mat),
								scale_mat);

	// transform_vec = mult_matrix_on_vertex(
	// 										mult_matrix(
	// 											mult_matrix(
	// 												mult_matrix(frustum_mat, mapping_mat),
	// 												perspective_mat),
	// 											scale_mat),
	// 										vertex);
	
	return (perspective_mat);
}
