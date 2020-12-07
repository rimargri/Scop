/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:32:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/07 17:00:03 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H
# include <math.h>

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_ivec3
{
	int				x;
	int				y;
	int				z;
}					t_ivec3;

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

t_vec3				vec_diff(t_vec3 v1, t_vec3 v2);
float				dot_product(t_vec3 v1, t_vec3 v2);
t_vec3				vec_add(t_vec3 v1, t_vec3 v2);
t_vec3				vec_normalize(t_vec3 v);
t_vec3				mult_vec_const(t_vec3 v, float n);
float				vec_length(t_vec3 v);
t_vec3				mult_vec(t_vec3 v1, t_vec3 v2);
t_vec3				division_vec(t_vec3 v1, t_vec3 v2);

#endif
