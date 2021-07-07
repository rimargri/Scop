/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_readed_obj_to_struct.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:45:56 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/07 16:02:39 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_load.h"
#include "scop.h"

// obj->count_faces - количество атрибутов в массиве
// obj->faces_vertexes - массив с vertex_id, расположенные в правильном порядке

// obj->count_vertexes - количество вертексов
// obj->vertex_position - массив с вертексами

void translate_readed_obj_to_struct(t_obj *obj, t_gl *gl)
{
	gl->count_vertexes = obj->count_faces * 3;
	int i = 0;
	int j = 0;
	int k = 0;

	// printf("%d\n", count_vertexes);
	obj->final_vertexes = malloc(sizeof(float) * gl->count_vertexes);
	if (!(obj->final_vertexes))
		exit(88);
	while (i < gl->count_vertexes)		// идём по финальному массиву вертексов и заполняем его
	{
		int count_faces_on_line = obj->count_digit_on_face_line[k];
		
			// printf("i = %d\n", i);
			int number_face = obj->faces_vertexes[j];		// получаем номер вертекса, который нужно добавить
			int vertex_index = (number_face - 1) * 3;		// получаем индекс вертекса в массиве вертексов

			obj->final_vertexes[i] = obj->vertex_position[vertex_index];
			obj->final_vertexes[i + 1] = obj->vertex_position[vertex_index + 1];
			obj->final_vertexes[i + 2] = obj->vertex_position[vertex_index + 2];
			printf("%f %f %f\n", obj->final_vertexes[i], obj->final_vertexes[i + 1], obj->final_vertexes[i + 2]);
			
			// если текущая строка содержит три вертекса, то:
				// obj->final_vertexes[i] = obj->vertex_position[vertex_index];
				// obj->final_vertexes[i + 1] = obj->vertex_position[vertex_index + 1];
				// obj->final_vertexes[i + 2] = obj->vertex_position[vertex_index + 2];
				// i += 3;
			// если текущая строка содержит четыре вертекса, то:
				
			
			i += 3;
			j++;
		
		printf("k = %d\tcount_faces_on_line = %d\n", k, count_faces_on_line);
	}
}























// 16		17

// 2		3












// 0	1	2	3



// 0	1	2
// 2	3	0



// ----------------
// 16	2	3	17
// ----------------



// ----------
// 2		16

// 3		17
// ----------

// ----------
// 16	2	3

// 3	17	16
// ----------