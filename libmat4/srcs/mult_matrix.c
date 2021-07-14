/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix[0]                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42[5]r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:29:41 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/07 14:04:52 by cvernius         ###   ########[5]r       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_mat4	mult_matrix(t_mat4 m1, t_mat4 m2)
{
	t_mat4 mat4;

	mat4.value[0] = m1.value[0] * m2.value[0] + m1.value[1] * m2.value[4] +
										m1.value[2] * m2.value[8] + m1.value[3] * m2.value[12];
	mat4.value[1] = m1.value[0] * m2.value[1] + m1.value[1] * m2.value[5] +
										m1.value[2] * m2.value[9] + m1.value[3] * m2.value[13];
	mat4.value[2] = m1.value[0] * m2.value[2] + m1.value[1] * m2.value[6] +
										m1.value[2] * m2.value[10] + m1.value[3] * m2.value[14];
	mat4.value[3] = m1.value[0] * m2.value[3] + m1.value[1] * m2.value[7] +
										m1.value[2] * m2.value[11] + m1.value[3] * m2.value[15];

	mat4.value[4] = m1.value[4] * m2.value[0] + m1.value[5] * m2.value[4] +
										m1.value[6] * m2.value[8] + m1.value[7] * m2.value[12];
	mat4.value[5] = m1.value[4] * m2.value[1] + m1.value[5] * m2.value[5] +
										m1.value[6] * m2.value[9] + m1.value[7] * m2.value[13];
	mat4.value[6] = m1.value[4] * m2.value[2] + m1.value[5] * m2.value[6] +
										m1.value[6] * m2.value[10] + m1.value[7] * m2.value[14];
	mat4.value[7] = m1.value[4] * m2.value[3] + m1.value[5] * m2.value[7] +
										m1.value[6] * m2.value[11] + m1.value[7] * m2.value[15];

	mat4.value[8] = m1.value[8] * m2.value[0] + m1.value[9] * m2.value[4] +
										m1.value[10] * m2.value[8] + m1.value[11] * m2.value[12];
	mat4.value[9] = m1.value[8] * m2.value[1] + m1.value[9] * m2.value[5] +
										m1.value[10] * m2.value[9] + m1.value[11] * m2.value[13];
	mat4.value[10] = m1.value[8] * m2.value[2] + m1.value[9] * m2.value[6] +
										m1.value[10] * m2.value[10] + m1.value[11] * m2.value[14];
	mat4.value[11] = m1.value[8] * m2.value[3] + m1.value[9] * m2.value[7] +
										m1.value[10] * m2.value[11] + m1.value[11] * m2.value[15];

	mat4.value[12] = m1.value[12] * m2.value[0] + m1.value[13] * m2.value[4] +
										m1.value[14] * m2.value[8] + m1.value[15] * m2.value[12];
	mat4.value[13] = m1.value[12] * m2.value[1] + m1.value[13] * m2.value[5] +
										m1.value[14] * m2.value[9] + m1.value[15] * m2.value[13];
	mat4.value[14] = m1.value[12] * m2.value[2] + m1.value[13] * m2.value[6] +
										m1.value[14] * m2.value[10] + m1.value[15] * m2.value[14];
	mat4.value[15] = m1.value[12] * m2.value[3] + m1.value[13] * m2.value[7] +
										m1.value[14] * m2.value[11] + m1.value[15] * m2.value[15];

	// printf("\nmulted_matrix\n");
	// for (int i = 0; i < 16; i++) {
	// 	printf("multed_matrix[%d] = %f\n", i, multed_matrix[i]);
	// }
	return (mat4);
}
