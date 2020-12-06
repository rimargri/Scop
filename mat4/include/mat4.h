/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:32:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/06 20:42:58 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H
# include <math.h>

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

typedef struct		s_mat4
{
	float			a;
	float			b;
	float			c;
	float			d;
	float			e;
	float			f;
	float			g;
	float			h;
	float			i;
	float			g;
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

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_vec2
{
	float			x;
	float			y;
}					t_vec2;

typedef struct		s_ivec2
{
	int				x;
	int				y;
}					t_ivec2;

/*
** *********************************** **
** *********************************** **
**            vector_operations        **
** *********************************** **
** *********************************** **
*/

t_vec4	mult_matrix_vertex(t_mat4 matrix, t_vec4 vertex);

#endif
