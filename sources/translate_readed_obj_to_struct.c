/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_readed_obj_to_struct.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:45:56 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/02 20:00:45 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_load.h"
#include "scop.h"

// obj->count_attributes - количество атрибутов в массиве
// obj->faces_vertexes - массив с vertex_id, расположенные в правильном порядке

// obj->count_vertexes - количество вертексов
// obj->vertex_position - массив с вертексами

void translate_readed_obj_to_struct(t_obj *obj, t_gl *gl)
{
	gl->count_vertexes = obj->count_attributes * 3;
	int i = 0;

	// printf("%d\n", count_vertexes);
	obj->final_vertexes = malloc(sizeof(float) * gl->count_vertexes);
	if (!(obj->final_vertexes))
		exit(88);
	int j = 0;
	while (i < gl->count_vertexes)
	{
		// printf("i = %d\n", i);
		int number_face = obj->faces_vertexes[j];
		int vertex_index = (number_face - 1) * 3;

		obj->final_vertexes[i] = obj->vertex_position[vertex_index];
		obj->final_vertexes[i + 1] = obj->vertex_position[vertex_index + 1];
		obj->final_vertexes[i + 2] = obj->vertex_position[vertex_index + 2];
		printf("%f %f %f\n", obj->final_vertexes[i], obj->final_vertexes[i + 1], obj->final_vertexes[i + 2]);
		i += 3;
		j++;
	}
}
