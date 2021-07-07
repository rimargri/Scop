/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_readed_obj_to_struct.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:45:56 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/07 18:31:49 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_load.h"
#include "scop.h"

// obj->count_faces - количество атрибутов в массиве
// obj->faces_vertexes - массив с vertex_id, расположенные в правильном порядке

// obj->count_vertexes - количество вертексов
// obj->vertex_position - массив с вертексами

void full_vertices_one_by_one(t_obj *obj, int i, int vertex_number)
{
	int first_vertex_index = (vertex_number - 1) * 3;		// получаем индекс первой точки нужного вертекса в массиве вертексов
	obj->final_vertexes[i] = obj->vertex_position[first_vertex_index];
	obj->final_vertexes[i + 1] = obj->vertex_position[first_vertex_index + 1];
	obj->final_vertexes[i + 2] = obj->vertex_position[first_vertex_index + 2];
	// printf("%f %f %f\n", obj->final_vertexes[i], obj->final_vertexes[i + 1], obj->final_vertexes[i + 2]);	
}

void translate_readed_obj_to_struct(t_obj *obj, t_gl *gl)
{
	for (int i = 0; i < obj->count_indexes; i++)
	{
		gl->count_vertexes += obj->count_digit_on_face_line[i] * 3;
	}
	printf("gl->count_vertexes final = %d\n", gl->count_vertexes);
	
	int i = 0;
	int j = 0;
	int k = 0;

	obj->final_vertexes = malloc(sizeof(float) * gl->count_vertexes);
	if (!(obj->final_vertexes))
		exit(88);

	while (i < gl->count_vertexes)											// идём по финальному массиву вертексов и заполняем его
	{
		int count_faces = j + obj->count_digit_on_face_line[k];
		printf("%d %d\n", k, obj->count_digit_on_face_line[k]);
		while (j < count_faces)												// проверяем, сколько в одной строчке фейсов, и разбиваем квадрат на тр-ик, если нужно
		{
			if (obj->count_digit_on_face_line[k] == 3)
			{
				while (j < count_faces)
				{
					int vertex_number = obj->faces_vertexes[j];				// получаем номер вертекса, который нужно добавить
					full_vertices_one_by_one(obj, i, vertex_number);
					j++;
					i += 3;
				}
			}

			else if (obj->count_digit_on_face_line[k] == 4)
			{
				// int vertex_number = obj->faces_vertexes[j]; 		// 16
				// int vertex_number = obj->faces_vertexes[j + 1];	// 2
				// int vertex_number = obj->faces_vertexes[j + 2];	// 3
				// int vertex_number = obj->faces_vertexes[j + 3];	// 17



				// int vertex_number = obj->faces_vertexes[j];		// 16
				// int vertex_number = obj->faces_vertexes[j + 1];	// 2
				// int vertex_number = obj->faces_vertexes[j + 2];	// 3
				int i_1 = j + 3;
				while (j < i_1)
				{
					int vertex_number = obj->faces_vertexes[j]; 		// 16
					full_vertices_one_by_one(obj, i, vertex_number);
					j++;
					i += 3;
				}
				
				
				// int vertex_number = obj->faces_vertexes[j + 2];	// 3
				// int vertex_number = obj->faces_vertexes[j + 3];	// 17
				// int vertex_number = obj->faces_vertexes[j];		// 16
				int i_2 = j + 2;
				while (j < i_2)
				{
					int vertex_number = obj->faces_vertexes[j]; 		// 3
					full_vertices_one_by_one(obj, i, vertex_number);
					j++;
					i += 3;
				}
				int vertex_number = obj->faces_vertexes[j - 3];
				full_vertices_one_by_one(obj, i, vertex_number);
				// i += 3;
			}
			// i += 3;											// 3, потому что в каждом вертексе по 3 точки
			// j++;
		}
		k++;
		printf("i = %d gl->count_vertexes = %d\n", i, gl->count_vertexes);
	}
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