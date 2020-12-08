/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_view_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:04:38 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/08 20:08:48 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat4	scale_view_window(t_frustum frustum)
{
	t_ivec2	scale;
	t_mat4	scale_view_mat;

	scale.x = 2.0f / (frustum.right - frustum.left);
	scale.y = 2.0f / (frustum.top - frustum.bottom);
	scale_view_mat.a = scale.x;
	scale_view_mat.b = 0.0f;
	scale_view_mat.c = 0.0f;
	scale_view_mat.d = 0.0f;

	scale_view_mat.e = 0.0f;
	scale_view_mat.f = scale.y;
	scale_view_mat.g = 0.0f;
	scale_view_mat.h = 0.0f;

	scale_view_mat.i = 0.0f;
	scale_view_mat.j = 0.0f;
	scale_view_mat.k = 1.0f;
	scale_view_mat.l = 0.0f;

	scale_view_mat.m = 0.0f;
	scale_view_mat.n = 0.0f;
	scale_view_mat.o = 0.0f;
	scale_view_mat.p = 1.0f;
	return (scale_view_mat);
}
