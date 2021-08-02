/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_load.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:29:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/20 17:43:43 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_LOAD_H
#define BMP_LOAD_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE_BMP_HEADER 54
#define COLOR_DEPTH 24

typedef struct		s_bmp
{
	unsigned char	info[54];
	int				offset_to_start_pixel_data;
	int				width;
	int				height;
	int				size;
	unsigned char	*data;
}					t_bmp;

void	read_bmp(char *filename, t_bmp *bmp);

#endif
