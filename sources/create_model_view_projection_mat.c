/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model_view_projection_mat.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:41:33 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/08 22:22:15 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat4	create_model_view_projection_mat()
{
	t_mat4 projection_mat;
	t_mat4 view_mat;
	t_mat4 model_mat;
	t_mat4 transform_mat;

	projection_mat = build_perspective_projection((t_vec3){4, 3, 3}, (t_vec3){0, 0, 0}, (t_vec3){0, 1, 0});
	view_mat = create_view_mat();
	model_mat = create_model_mat();
	transform_mat = mult_matrix(
								mult_matrix(projection_mat, view_mat), model_mat);
	return (transform_mat);
}
