/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:13:15 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 19:02:07 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	identity_matrix(void)
{
	t_mat4 identity_mat;

	identity_mat.a = 1.0f;
	identity_mat.b = 0.0f;
	identity_mat.c = 0.0f;
	identity_mat.d = 0.0f;

	identity_mat.e = 0.0f;
	identity_mat.f = 1.0f;
	identity_mat.g = 0.0f;
	identity_mat.h = 0.0f;

	identity_mat.i = 0.0f;
	identity_mat.j = 0.0f;
	identity_mat.k = 1.0f;
	identity_mat.l = 0.0f;

	identity_mat.m = 0.0f;
	identity_mat.n = 0.0f;
	identity_mat.o = 0.0f;
	identity_mat.p = 1.0f;
	return (identity_mat);
}
