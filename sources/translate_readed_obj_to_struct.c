/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_readed_obj_to_struct.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:45:56 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/11 13:21:55 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_load.h"
#include "scop.h"

// obj->count_faces - количество атрибутов в массиве
// obj->faces_array - массив с vertex_id, расположенные в правильном порядке

// obj->count_vertexes - количество вертексов
// obj->vertex_position - массив с вертексами



void full_coords_vertex_one_by_one(t_obj *obj, int i, int index_coord)
{
	obj->final_vertexes[i] = obj->vertex_position[index_coord];
	obj->final_vertexes[i + 1] = obj->vertex_position[index_coord + 1];
	obj->final_vertexes[i + 2] = obj->vertex_position[index_coord + 2];
	// printf("%f %f %f\n", obj->final_vertexes[i], obj->final_vertexes[i_array_coord_vertex + 1], obj->final_vertexes[i_array_coord_vertex + 2]);
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
	gl->count_vertexes = obj->count_coord_vertexes;
	printf("gl->count_vertexes = %d\n", gl->count_vertexes);
	obj->final_vertexes = malloc(sizeof(float) * obj->count_coord_vertexes);
	if (!(obj->final_vertexes))
		exit(99);
}


// void translate_readed_obj_to_struct(t_obj *obj, t_gl *gl)
// {
// 	gl->count_vertexes = obj->count_faces * 3;
// 	int i = 0;

// 	printf("count vet = %d\n", gl->count_vertexes);
// 	obj->final_vertexes = malloc(sizeof(float) * gl->count_vertexes);
// 	if (!(obj->final_vertexes))
// 		exit(88);
// 	int j = 0;
// 	while (i < gl->count_vertexes)
// 	{
// 		// printf("i = %d\n", i);
// 		int number_face = obj->faces_array[j];
// 		int vertex_index = (number_face - 1) * 3;

// 		obj->final_vertexes[i] = obj->vertex_position[vertex_index];
// 		obj->final_vertexes[i + 1] = obj->vertex_position[vertex_index + 1];
// 		obj->final_vertexes[i + 2] = obj->vertex_position[vertex_index + 2];
// 		printf("%f %f %f\n", obj->final_vertexes[i], obj->final_vertexes[i + 1], obj->final_vertexes[i + 2]);
// 		i += 3;
// 		j++;
// 	}
// }



void translate_readed_obj_to_struct(t_obj *obj, t_gl *gl)
{
	int i = 0;
	int i_face = 0;
	int index = 0;
	int tmp = 0;
	// int j = 0;
	int face;
	int fist_coord_array_vertex;

	get_count_coord_vertexes(obj, gl);
	printf("obj->count_coord_vertexes = %d\n", obj->count_coord_vertexes);
	while (i < obj->count_coord_vertexes)
	{
		int count_faces_on_line = obj->count_faces_on_line[index];
		printf("i = %d\nindex = %d\n", i, index);
		if (count_faces_on_line == 3)
		{

			
			// int tmp = i_face + count_faces_on_line;
			// while (i_face < tmp)
			// {
			// 	face = obj->faces_array[i_face];
			// 	fist_coord_array_vertex = (face - 1) * 3;
			// 	full_coords_vertex_one_by_one(obj, i, fist_coord_array_vertex);
			// 	i += 3;
			// 	// printf("i_face = %d\nface = %d\n", i_face, face);
			// 	i_face++;
			// }
		
			face = obj->faces_array[i_face];
			fist_coord_array_vertex = (face - 1) * 3;
			obj->final_vertexes[i] = obj->vertex_position[fist_coord_array_vertex];
			obj->final_vertexes[i + 1] = obj->vertex_position[fist_coord_array_vertex + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[fist_coord_array_vertex + 2];
			
			i_face++;
			i += 3;
			face = obj->faces_array[i_face];
			fist_coord_array_vertex = (face - 1) * 3;
			obj->final_vertexes[i] = obj->vertex_position[fist_coord_array_vertex];
			obj->final_vertexes[i + 1] = obj->vertex_position[fist_coord_array_vertex + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[fist_coord_array_vertex + 2];
			
			i_face++;
			i += 3;
			face = obj->faces_array[i_face];
			fist_coord_array_vertex = (face - 1) * 3;
			obj->final_vertexes[i] = obj->vertex_position[fist_coord_array_vertex];
			obj->final_vertexes[i + 1] = obj->vertex_position[fist_coord_array_vertex + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[fist_coord_array_vertex + 2];
			
			i_face++;
			i += 3;
		
		}

		else if (count_faces_on_line == 4)
		{
			face = obj->faces_array[i_face];
			fist_coord_array_vertex = (face - 1) * 3;
			obj->final_vertexes[i] = obj->vertex_position[fist_coord_array_vertex];
			obj->final_vertexes[i + 1] = obj->vertex_position[fist_coord_array_vertex + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[fist_coord_array_vertex + 2];

			i_face++;
			i += 3;
			face = obj->faces_array[i_face];
			fist_coord_array_vertex = (face - 1) * 3;
			obj->final_vertexes[i] = obj->vertex_position[fist_coord_array_vertex];
			obj->final_vertexes[i+ 1] = obj->vertex_position[fist_coord_array_vertex + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[fist_coord_array_vertex + 2];
			
			i_face++;
			i += 3;
			face = obj->faces_array[i_face];
			fist_coord_array_vertex = (face - 1) * 3;
			obj->final_vertexes[i] = obj->vertex_position[fist_coord_array_vertex];
			obj->final_vertexes[i+ 1] = obj->vertex_position[fist_coord_array_vertex + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[fist_coord_array_vertex + 2];
			
			i += 3;
			obj->final_vertexes[i] = obj->vertex_position[fist_coord_array_vertex];
			obj->final_vertexes[i+ 1] = obj->vertex_position[fist_coord_array_vertex + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[fist_coord_array_vertex + 2];
			
			i_face++;
			i += 3;
			face = obj->faces_array[i_face];
			fist_coord_array_vertex = (face - 1) * 3;
			obj->final_vertexes[i] = obj->vertex_position[fist_coord_array_vertex];
			obj->final_vertexes[i+ 1] = obj->vertex_position[fist_coord_array_vertex + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[fist_coord_array_vertex + 2];
			
			i_face -= 3;
			i += 3;
			face = obj->faces_array[i_face];
			fist_coord_array_vertex = (face - 1) * 3;
			obj->final_vertexes[i] = obj->vertex_position[fist_coord_array_vertex];
			obj->final_vertexes[i+ 1] = obj->vertex_position[fist_coord_array_vertex + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[fist_coord_array_vertex + 2];

			i_face += 4; // or 3?
			i += 3;
		}
		index++;
	}

	for (int i = 0; i < obj->count_coord_vertexes; i++)
	{
		printf("%d %f\n", i, obj->final_vertexes[i]);
	}
	printf("count coord vertexes: %d\n", obj->count_coord_vertexes);
	printf("count vertexes: %d\n", gl->count_vertexes);
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