/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:29:41 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/07 14:04:52 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	mult_matrix(t_mat4 mat1, t_mat4 mat2)
{
	t_mat4 multed_matrix;

	multed_matrix.a = mat1.a * mat2.a + mat1.b * mat2.e +
										mat1.c * mat2.i + mat1.d * mat2.m;
	multed_matrix.b = mat1.a * mat2.b + mat1.b * mat2.f +
										mat1.c * mat2.j + mat1.d * mat2.n;
	multed_matrix.c = mat1.a * mat2.c + mat1.b * mat2.g +
										mat1.c * mat2.k + mat1.d * mat2.o;
	multed_matrix.d = mat1.a * mat2.d + mat1.b * mat2.h +
										mat1.c * mat2.l + mat1.d * mat2.p;

	multed_matrix.e = mat1.e * mat2.a + mat1.f * mat2.e +
										mat1.g * mat2.i + mat1.h * mat2.m;
	multed_matrix.f = mat1.e * mat2.b + mat1.f * mat2.f +
										mat1.g * mat2.j + mat1.h * mat2.n;
	multed_matrix.g = mat1.e * mat2.c + mat1.f * mat2.g +
										mat1.g * mat2.k + mat1.h * mat2.o;
	multed_matrix.h = mat1.e * mat2.d + mat1.f * mat2.h +
										mat1.g * mat2.l + mat1.h * mat2.p;

	multed_matrix.i = mat1.i * mat2.a + mat1.j * mat2.e +
										mat1.k * mat2.i + mat1.l * mat2.m;
	multed_matrix.j = mat1.i * mat2.b + mat1.j * mat2.f +
										mat1.k * mat2.j + mat1.l * mat2.n;
	multed_matrix.k = mat1.i * mat2.c + mat1.j * mat2.g +
										mat1.k * mat2.k + mat1.l * mat2.o;
	multed_matrix.l = mat1.i * mat2.d + mat1.j * mat2.h +
										mat1.k * mat2.l + mat1.l * mat2.p;

	multed_matrix.m = mat1.m * mat2.a + mat1.n * mat2.e +
										mat1.p * mat2.i + mat1.p * mat2.m;
	multed_matrix.n = mat1.m * mat2.b + mat1.n * mat2.f +
										mat1.p * mat2.j + mat1.p * mat2.n;
	multed_matrix.o = mat1.m * mat2.c + mat1.n * mat2.g +
										mat1.p * mat2.k + mat1.p * mat2.o;
	multed_matrix.p = mat1.m * mat2.d + mat1.n * mat2.h +
										mat1.p * mat2.l + mat1.p * mat2.p;
	return (multed_matrix);
}
