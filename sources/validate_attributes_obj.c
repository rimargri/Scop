/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_attributes_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:13:21 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/24 21:54:07 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_load.h"

void	validate_vertex(t_obj *obj, char *buf, int start, int finish)
{
	int			i;
	float		point;
	static int	j = 0;

	i = start;
	while (i < finish)
	{
		if (buf[i] == ' ')
		{
			point = atof(&buf[i]);
			obj->vertex_position[j] = point;
			j++;
		}
		i++;
	}
}

void	validate_index(t_obj *obj, char *buf, int start, int finish)
{
	int			i;
	float		index;
	static int	j = 0;
	int			count_space;
	char		*cur_ptr;

	i = start;
	count_space = 0;
	cur_ptr = buf[start];
	while (i < finish)
	{
		if (buf[i] == ' ')
		{
			index = atof(&buf[i]);
			obj->vertex_position_indexes[j] = index;
			j++;
		}
		i++;
	}
}
