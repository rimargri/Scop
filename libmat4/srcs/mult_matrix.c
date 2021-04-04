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

float	*mult_matrix(float *mat1, float *mat2)
{
	float multed_matrix[16];

	printf("\nmat1\n");
	for (int i = 0; i < 16; i++) {
		printf("mat1[%d] = %f\n", i, mat1[i]);
	}

	multed_matrix[0] = mat1[0] * mat2[0] + mat1[1] * mat2[4] +
										mat1[2] * mat2[8] + mat1[3] * mat2[12];
	multed_matrix[1] = mat1[0] * mat2[1] + mat1[1] * mat2[5] +
										mat1[2] * mat2[9] + mat1[3] * mat2[13];
	multed_matrix[2] = mat1[0] * mat2[2] + mat1[1] * mat2[6] +
										mat1[2] * mat2[10] + mat1[3] * mat2[14];
	multed_matrix[3] = mat1[0] * mat2[3] + mat1[1] * mat2[7] +
										mat1[2] * mat2[11] + mat1[3] * mat2[15];

	multed_matrix[4] = mat1[4] * mat2[0] + mat1[5] * mat2[4] +
										mat1[6] * mat2[8] + mat1[7] * mat2[12];
	multed_matrix[5] = mat1[4] * mat2[1] + mat1[5] * mat2[5] +
										mat1[6] * mat2[9] + mat1[7] * mat2[13];
	multed_matrix[6] = mat1[4] * mat2[2] + mat1[5] * mat2[6] +
										mat1[6] * mat2[10] + mat1[7] * mat2[14];
	multed_matrix[7] = mat1[4] * mat2[3] + mat1[5] * mat2[7] +
										mat1[6] * mat2[11] + mat1[7] * mat2[15];

	multed_matrix[8] = mat1[8] * mat2[0] + mat1[9] * mat2[4] +
										mat1[10] * mat2[8] + mat1[11] * mat2[12];
	multed_matrix[9] = mat1[8] * mat2[1] + mat1[9] * mat2[5] +
										mat1[10] * mat2[9] + mat1[11] * mat2[13];
	multed_matrix[10] = mat1[8] * mat2[2] + mat1[9] * mat2[6] +
										mat1[10] * mat2[10] + mat1[11] * mat2[14];
	multed_matrix[11] = mat1[8] * mat2[3] + mat1[9] * mat2[7] +
										mat1[10] * mat2[11] + mat1[11] * mat2[15];

	multed_matrix[12] = mat1[12] * mat2[0] + mat1[13] * mat2[4] +
										mat1[15] * mat2[8] + mat1[15] * mat2[12];
	multed_matrix[13] = mat1[12] * mat2[1] + mat1[13] * mat2[5] +
										mat1[15] * mat2[9] + mat1[15] * mat2[13];
	multed_matrix[14] = mat1[12] * mat2[2] + mat1[13] * mat2[6] +
										mat1[15] * mat2[10] + mat1[15] * mat2[14];
	multed_matrix[15] = mat1[12] * mat2[3] + mat1[13] * mat2[7] +
										mat1[15] * mat2[11] + mat1[15] * mat2[15];


	printf("\nmulted_matrix\n");
	for (int i = 0; i < 16; i++) {
		printf("multed_matrix[%d] = %f\n", i, multed_matrix[i]);
	}
	return (multed_matrix);
}
