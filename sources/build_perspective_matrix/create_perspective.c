/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_perspective.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:57:02 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/08 21:27:08 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat4	perspective_calculation(void)
{
	t_mat4 perspective_mat;

	perspective_mat.a = NEAR;
	perspective_mat.b = 0.0f;
	perspective_mat.c = 0.0f;
	perspective_mat.d = 0.0f;

	perspective_mat.e = 0.0f;
	perspective_mat.f = NEAR;
	perspective_mat.g = 0.0f;
	perspective_mat.h = 0.0f;

	perspective_mat.i = 0.0f;
	perspective_mat.j = 0.0f;
	perspective_mat.k = 1.0f;
	perspective_mat.l = 0.0f;

	perspective_mat.m = 0.0f;
	perspective_mat.n = 0.0f;
	perspective_mat.o = 1.0f;
	perspective_mat.p = 0.0f;
	return (perspective_mat);
}
