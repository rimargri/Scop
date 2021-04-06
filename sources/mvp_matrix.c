/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:15:00 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/06 19:17:55 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_mvp_matrix(t_opengl *opengl)
{
	opengl->matrix->mvp = mult_matrix(opengl->matrix->look_at, opengl->matrix->model);
}
