/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:32:28 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/04 19:04:24 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H
# include <math.h>
#include "../../libvector/include/libvector.h"

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

typedef struct		s_ivec4
{
	int				x;
	int				y;
	int				z;
	int				w;
}					t_ivec4;

typedef struct		s_mat4
{
	float			value[16];
}					t_mat4;

/*
** *********************************** **
** *********************************** **
**            matrix operation         **
** *********************************** **
** *********************************** **
*/

t_vec4	mult_matrix_on_vertex(t_mat4 matrix, t_vec4 vertex);
t_mat4	mult_matrix(t_mat4 m1, t_mat4 m2);
t_mat4	identity_matrix(void);

/*
** *********************************** **
** *********************************** **
**         perspective matrix          **
** *********************************** **
** *********************************** **
*/



/*
** *********************************** **
** *********************************** **
**           transform matrix          **
** *********************************** **
** *********************************** **
*/


#endif
