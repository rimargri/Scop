/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:15:00 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/11 18:11:30 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_mvp_matrix(t_opengl *opengl)
{
	t_mat4 mvp = opengl->matrix->projection;
	// mvp = mult_matrix(opengl->matrix->look_at, mvp);
	mvp = mult_matrix(mvp, opengl->matrix->model);
	opengl->matrix->mvp = mvp;
}
