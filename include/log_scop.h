/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_scop.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:45:35 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/20 18:00:09 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_SCOP_H
# define LOG_SCOP_H

#include "../libvector/include/libvector.h"

/*
** *********************************** **
** *********************************** **
**           	code error	           **
** *********************************** **
** *********************************** **
*/

enum errors
{
	malloc_error,
	glfw_not_init,
	window_not_open,
	bmp_file_not_open,
	image_is_not_bmp,
	color_depth_not_24,
	not_a_file,
	giant_file,
	empty_data_tex
};

void	log_scop(const char *error, enum errors code);

#endif