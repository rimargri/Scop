/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:13:15 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/03 15:57:42 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

float	*identity_matrix(void)
{
	float identity_mat[16];

	identity_mat[0] = 1.0f;
	identity_mat[1] = 0.0f;
	identity_mat[2] = 0.0f;
	identity_mat[3] = 0.0f;

	identity_mat[4] = 0.0f;
	identity_mat[5] = 1.0f;
	identity_mat[6] = 0.0f;
	identity_mat[7] = 0.0f;

	identity_mat[8] = 0.0f;
	identity_mat[9] = 0.0f;
	identity_mat[10] = 1.0f;
	identity_mat[11] = 0.0f;

	identity_mat[12] = 0.0f;
	identity_mat[13] = 0.0f;
	identity_mat[14] = 0.0f;
	identity_mat[15] = 1.0f;
	return (identity_mat);
}
