/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_readed_obj_to_struct.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:45:56 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/09 18:38:02 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_load.h"
#include "scop.h"

// obj->count_faces - количество атрибутов в массиве
// obj->faces_array - массив с vertex_id, расположенные в правильном порядке

// obj->count_vertexes - количество вертексов
// obj->vertex_position - массив с вертексами



void full_coords_vertex_one_by_one(t_obj *obj, int index_coord, int i_array_coord_vertex)
{
	obj->final_vertexes[i_array_coord_vertex] = obj->vertex_position[index_coord];
	obj->final_vertexes[i_array_coord_vertex + 1] = obj->vertex_position[index_coord + 1];
	obj->final_vertexes[i_array_coord_vertex + 2] = obj->vertex_position[index_coord + 2];
	// printf("%f %f %f\n", obj->final_vertexes[i_array_coord_vertex], obj->final_vertexes[i_array_coord_vertex + 1], obj->final_vertexes[i_array_coord_vertex + 2]);
}

void get_count_coord_vertexes(t_obj *obj, t_gl *gl)
{
	// gl->count_vertexes = 0;
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
	// gl->count_vertexes = obj->count_coord_vertexes;									//! ATTENSION !!!!!!!!!!!!!!!!!
	printf("gl->count_vertexes = %d\n", gl->count_vertexes);
	obj->final_vertexes = malloc(sizeof(float) * obj->count_coord_vertexes);
	if (!(obj->final_vertexes))
		exit(99);
}


void translate_readed_obj_to_struct(t_obj *obj, t_gl *gl)
{
	int i = 0;
	int i_face = 0;
	int index = 0;
	int tmp = 0;
	int j = 0;

	get_count_coord_vertexes(obj, gl);
	printf("obj->count_coord_vertexes = %d\n", obj->count_coord_vertexes);
	while (i < obj->count_coord_vertexes)
	{
		int count_faces_on_line = obj->count_faces_on_line[index];
		printf("i = %d\nindex = %d\n", i, index);
		if (count_faces_on_line == 3)
		{
			int tmp = i_face + count_faces_on_line;
			while (i_face < tmp)
			{
				int face = obj->faces_array[i_face];
				int fist_coord_array_vertex = (face - 1) * 3;
				full_coords_vertex_one_by_one(obj, fist_coord_array_vertex, i);
				i += 3;
				// printf("i_face = %d\nface = %d\n", i_face, face);
				i_face++;
			}
		}
		if (count_faces_on_line == 4)
		{
			int tmp = i_face + count_faces_on_line;
			float arr1[3];
			float arr2[3];
			while (j < 3)
			{
				arr1[j] = obj->faces_array[i_face];
				j++;
				i_face++;
			}
			j = 0;
			while (j < 2)
			{
				arr2[j] = obj->faces_array[i_face];
				j++;
				i_face++;
			}
		}
		index++;
	}

	// for (int i = 0; i < obj->count_coord_vertexes; i++)
	// {
	// 	printf("%d %f\n", i, obj->final_vertexes[i]);
	// }
}






// 16		17

// 2		3












// 0	1	2	3



// 0	1	2
// 2	3	0


////////////////////
// ----------------
// 16	2	3	17
// ----------------
///////////////////



/////////////
// ----------
// 16	2	3

// 3	17	16
// ----------
/////////////



// ----------
// 2		16

// 3		17
// ----------

// выделить память на вертексы больше