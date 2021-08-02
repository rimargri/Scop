/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:15:00 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 18:36:38 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_mvp_matrix(t_matrix *matrix, t_input_transform *val)
{
	create_model_matrix(matrix, val);
	create_projection_matrix(matrix);
	matrix->mvp = mult_matrix(matrix->projection, matrix->model);
}
