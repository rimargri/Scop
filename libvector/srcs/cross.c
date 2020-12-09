/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:53:45 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 15:57:05 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vec3	cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3 cross_vec;

	cross_vec.x = v1.y * v2.z - v1.z * v2.y;
	cross_vec.y = v1.z * v2.x - v1.x * v2.z;
	cross_vec.z = v1.x * v2.y - v1.y * v2.x;
	return (cross_vec);
}
