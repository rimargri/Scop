/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_attributes_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:13:21 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 18:47:35 by cvernius         ###   ########.fr       */
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

int		get_count_faces_on_line(char *buf, int start, int finish)
{
	int			i;
	float		index;
	static int	j = 0;
	int			counter_faces = 0;

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

int		get_count_faces_line(char *buf, int start, int finish)
{
	int			i;
	float		index;
	static int	j = 0;
	int			counter_faces = 0;

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

void	validate_faces(t_obj *obj, char *buf, int start, int finish)
{
	int			i;
	float		face;
	static int	j = 0;

	i = start;
	while (i < finish)
	{
		if (buf[i] == ' ')
		{
			face = atof(&buf[i + 1]);
			obj->faces_array[j] = face;
			j++;
		}
		i++;
	}
}
