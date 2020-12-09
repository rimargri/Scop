/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:32:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 19:02:12 by cvernius         ###   ########.fr       */
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


	// mat[0][0]
	// mat[0][1]
	// mat[0][2]
	// mat[0][3]

	// mat[1][0]
	// mat[1][1]
	// mat[1][2]
	// mat[1][3]

	// mat[2][0]
	// mat[2][1]
	// mat[2][2]
	// mat[2][3]

	// mat[3][0]
	// mat[3][1]
	// mat[3][2]
	// mat[3][3]

typedef struct		s_mat4
{
	// float			mat[4][4];
	float			a;
	float			b;
	float			c;
	float			d;

	float			e;
	float			f;
	float			g;
	float			h;

	float			i;
	float			j;
	float			k;
	float			l;

	float			m;
	float			n;
	float			o;
	float			p;
}					t_mat4;

typedef struct		s_ivec4
{
	int				x;
	int				y;
	int				z;
	int				w;
}					t_ivec4;


/*
** *********************************** **
** *********************************** **
**            matrix operation         **
** *********************************** **
** *********************************** **
*/

t_vec4	mult_matrix_on_vertex(t_mat4 matrix, t_vec4 vertex);
t_mat4	mult_matrix(t_mat4 mat1, t_mat4 mat2);
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

t_vec4	scale_matrix(t_vec3 scale_value, t_vec4 vertex);
t_vec4	rotation_matrix(t_vec3 angle, t_vec4 vertex);
t_vec4	translate_matrix(t_vec3 shift, t_vec4 vertex);



#endif
