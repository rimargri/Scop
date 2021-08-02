/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_readed_obj_to_struct.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:45:56 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 18:45:59 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_load.h"
#include "scop.h"


/*
** ************************************************************************** **
** ************************************************************************** **
** obj->count_faces - количество атрибутов в массиве ************************ **
** obj->faces_array - массив с vertex_id, расположенные в правильном порядке  **
** obj->count_vertexes - количество вертексов ******************************* **
** obj->vertex_position - массив с вертексами ******************************* **
** ************************************************************************** **
** ************************************************************************** **
*/

void get_count_coord_vertexes(t_obj *obj, t_gl *gl)
{
	gl->count_vertexes = 0;
	int i = 0;
	while (i < obj->count_indexes)
	{
		if (obj->count_faces_on_line[i] == 3)
			gl->count_vertexes += obj->count_faces_on_line[i];
		if (obj->count_faces_on_line[i] == 4)
			gl->count_vertexes += 6;
		i++;
	}
	obj->count_coord_vertexes = gl->count_vertexes * 3;
	gl->count_vertexes = obj->count_coord_vertexes;
	obj->final_vertexes = malloc(sizeof(float) * obj->count_coord_vertexes);
	if (!(obj->final_vertexes))
		exit(99);
}

void full_array_coord_vertex(int i, int i_face, t_obj *obj)
{
	int face;
	int first_coord_array_vertex;

	face = obj->faces_array[i_face];
	first_coord_array_vertex = (face - 1) * 3;
	obj->final_vertexes[i] = obj->vertex_position[first_coord_array_vertex];
	obj->final_vertexes[i + 1] = obj->vertex_position[first_coord_array_vertex + 1];
	obj->final_vertexes[i + 2] = obj->vertex_position[first_coord_array_vertex + 2];
}

void translate_readed_obj_to_struct(t_obj *obj, t_gl *gl)
{
	int i = 0;
	int i_face = 0;
	int index = 0;
	int j = 0;

	get_count_coord_vertexes(obj, gl);
	while (i < obj->count_coord_vertexes)
	{
		int count_faces_on_line = obj->count_faces_on_line[index];
		j = 0;
		if (count_faces_on_line == 3)
		{
			while (j < 3)
			{
				full_array_coord_vertex(i, i_face, obj);
				i += 3;
				i_face++;
				j++;
			}
		}
		else if (count_faces_on_line == 4)
		{
			while (j < 6)
			{
				full_array_coord_vertex(i, i_face, obj);
				i += 3;
				if (j != 2 && j != 4 && j != 5)
					i_face++;
				else if (j == 4)
					i_face -= 3;
				else if (j == 5)
					i_face += 4;
				j++;
			}
		}
		index++;
	}
}
