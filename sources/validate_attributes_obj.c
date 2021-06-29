/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_attributes_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:13:21 by cvernius          #+#    #+#             */
/*   Updated: 2021/06/29 20:28:09 by cvernius         ###   ########.fr       */
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

int		get_count_indexes(t_obj *obj, char *buf, int start, int finish)
{
	int			i;
	float		index;
	static int	j = 0;
	int			counter_faces = 0;
	int			count_space;

	i = start;
	while (i < finish)
	{
		if (buf[i] == ' ')
		{
			index = atof(&buf[i]);
			if (index)
				counter_faces++;
			j++;
		}
		i++;
	}
	return (counter_faces);
}

void	validate_index(t_obj *obj, char *buf, int start, int finish)
{
	int			i;
	float		index;
	static int	j = 0;
	static int	counter_faces;
	int			count_space;

	i = start;
	printf("start = %d\n", i);
	printf("finish = %d\n", finish);
	while (i < finish)
	{
		if (buf[i] == ' ')
		{
			printf("buf[%d] = %c\n", i, buf[i + 1]);
			index = atof(&buf[i + 1]);
			obj->faces_vertexes[j] = index;
			j++;
			// printf("index[%d] = %f\n", j, obj->faces_vertexes[j]);
		}
		i++;
	}
}
