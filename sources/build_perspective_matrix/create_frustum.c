/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frustum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:42:03 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 19:23:31 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_perspective_parameters(void)
{
	// aspect
	// fov
	// near
	// far
	if ((FAR >= NEAR) || (FAR <= 0)|| (NEAR <= 0))
		exit(99);

}

t_mat4	move_frustum_apex_to_origin(t_frustum frustum)
{
	t_ivec2	mid;
	t_mat4	mat_apex;

	mid.x = (frustum.left + frustum.right) * 0.5;
	mid.y = (frustum.bottom + frustum.top) * 0.5;
	mat_apex.a = 1.0f;
	mat_apex.b = 0.0f;
	mat_apex.c = 0.0f;
	mat_apex.d = -mid.x;

	mat_apex.e = 0.0f;
	mat_apex.f = 1.0f;
	mat_apex.g = 0.0f;
	mat_apex.h = -mid.y;

	mat_apex.i = 0.0f;
	mat_apex.j = 0.0f;
	mat_apex.k = 1.0f;
	mat_apex.l = 0.0f;

	mat_apex.m = 0.0f;
	mat_apex.n = 0.0f;
	mat_apex.o = 0.0f;
	mat_apex.p = 1.0f;
	return (mat_apex);
}

t_mat4	create_frustum(t_frustum frustum)
{
	t_mat4 mat_apex;

	// if (frustum.left == frustum.right || frustum.top == frustum.bottom || NEAR == FAR)
	// 	// exit(99);
	// 	*perspective_matrix = identity_matrix();

	mat_apex = move_frustum_apex_to_origin(frustum);
	return (mat_apex);
}
