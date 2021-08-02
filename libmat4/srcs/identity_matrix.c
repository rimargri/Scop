/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:13:15 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/04 19:04:25 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_mat4	identity_matrix(void)
{
	t_mat4 identity;

	identity.value[0] = 1.0f;
	identity.value[1] = 0.0f;
	identity.value[2] = 0.0f;
	identity.value[3] = 0.0f;

	identity.value[4] = 0.0f;
	identity.value[5] = 1.0f;
	identity.value[6] = 0.0f;
	identity.value[7] = 0.0f;

	identity.value[8] = 0.0f;
	identity.value[9] = 0.0f;
	identity.value[10] = 1.0f;
	identity.value[11] = 0.0f;

	identity.value[12] = 0.0f;
	identity.value[13] = 0.0f;
	identity.value[14] = 0.0f;
	identity.value[15] = 1.0f;
	return (identity);
}
