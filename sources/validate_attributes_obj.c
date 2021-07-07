/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_attributes_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:13:21 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/07 18:10:03 by cvernius         ###   ########.fr       */
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
	// printf("get_count_indexes:: count faces = %d\n", counter_faces);
	//! if (counter_faces > 4 || counter_faces < 3)
		//! log_scop("Count faces is error");
	return (counter_faces);
}

int		get_count_faces_on_line(t_obj *obj, char *buf, int start, int finish)
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
	// printf("get_count_indexes:: count faces = %d\n", counter_faces);
	//! if (counter_faces > 4 || counter_faces < 3)
		//! log_scop("Count faces is error");
	return (counter_faces);
}

void	validate_faces(t_obj *obj, char *buf, int start, int finish)
{
	int			i;
	float		face;
	static int	j = 0;
	// static int	counter_faces;

	i = start;
	while (i < finish)
	{
		if (buf[i] == ' ')
		{
			face = atof(&buf[i + 1]);
			obj->faces_vertexes[j] = face;
			j++;
			// printf("face[%d] = %f\n", j, obj->faces_vertexes[j]);
		}
		i++;
	}
}
