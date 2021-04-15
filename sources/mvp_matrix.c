/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:15:00 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/15 17:23:09 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// look_at doesn't added

void	create_mvp_matrix(t_matrix *matrix)
{
	create_model_matrix(matrix);
	// get_camera_values(&scop->camera);								// will be input from keyboard in future
	// create_view_matrix(scop->matrix, gl->camera);
	create_projection_matrix(matrix);
	matrix->mvp = mult_matrix(matrix->projection, matrix->model);
}
