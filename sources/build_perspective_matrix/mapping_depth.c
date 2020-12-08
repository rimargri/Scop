/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_depth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:09:25 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/08 21:03:09 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// mapping - отображение. В результате него была перевёрнута ориентация z-оси

t_mat4	mapping_depth(void)
{
	t_ivec2	constant;
	t_mat4	mapping_depth_mat;

	constant.x = (2 * FAR * NEAR) / (NEAR - FAR);
	constant.y = (FAR + NEAR) / (FAR - NEAR);
	mapping_depth_mat.a = 1.0f;
	mapping_depth_mat.b = 0.0f;
	mapping_depth_mat.c = 0.0f;
	mapping_depth_mat.d = 0.0f;

	mapping_depth_mat.e = 0.0f;
	mapping_depth_mat.f = 1.0f;
	mapping_depth_mat.g = 0.0f;
	mapping_depth_mat.h = 0.0f;

	mapping_depth_mat.i = 0.0f;
	mapping_depth_mat.j = 0.0f;
	mapping_depth_mat.k = -constant.y;
	mapping_depth_mat.l = constant.x;

	mapping_depth_mat.m = 0.0f;
	mapping_depth_mat.n = 0.0f;
	mapping_depth_mat.o = -1.0f;
	mapping_depth_mat.p = 0.0f;
	return (mapping_depth_mat);
}
