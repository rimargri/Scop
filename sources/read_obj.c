/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:52:41 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/11 14:13:54 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_load.h"
#include "log_scop.h"
#include "scop.h"
#include <stdio.h> //!---------------------------------------------------------

// одновременно считаем количество вертексов и количество фэйсов
// count_indexes - количество строк фейсов
// count_atttributes - количество атрибутов в строке face
void	get_count_attributes(int buf_size, char *buf, t_obj *obj)
{	
	int	i;
	int start_line;
	int length;
	int prefix;
	int prefix_pos;

	i = 0;
	start_line = 0;
	obj->count_vertexes = 0;
	obj->count_indexes = 0;
	obj->count_faces = 0;
	while (i < buf_size)
	{
		if (buf[i] == '\n')
		{
			length = i - start_line;
			start_line = i + 1;
			prefix_pos = i - length;
			prefix = buf[prefix_pos];
			if (prefix == '#') {}
			if (prefix == 'o') {}
			if (prefix == 'v' && buf[prefix_pos + 1] == ' ')
				obj->count_vertexes += 1;
			if (prefix == 'f')
			{
				obj->count_indexes += 1;
				obj->count_faces += get_count_faces_on_line(obj, buf, prefix_pos + 1, i);
			}
		}
		i++;
	}
	printf("obj->count_vertexes = %d\n", obj->count_vertexes);
	printf("obj->count_faces = %d\n", obj->count_faces);
}

void	validate_attributes(int buf_size, char *buf, t_obj *obj)
{
	int	i;
	int start_line;
	int length;
	int prefix;
	int prefix_pos;
	int j = 0;

	i = 0;
	start_line = 0;
	while (i < buf_size)
	{
		if (buf[i] == '\n')
		{
			length = i - start_line;
			start_line = i + 1;
			prefix_pos = i - length;
			prefix = buf[prefix_pos];
			if (prefix == '#') {}
			if (prefix == 'o') {}
			if (prefix == 'v' && buf[prefix_pos + 1] == ' ')
				validate_vertex(obj, buf, prefix_pos + 1, i);
			if (prefix == 'f')
			{
				validate_faces(obj, buf, prefix_pos + 1, i);
				obj->count_faces_on_line[j] = get_count_faces_line(obj, buf, prefix_pos + 1, i);
				j++;
			}
		}
		i++;
	}
}

// void	get_count_digits_on_faces_line(int buf_size, char *buf, t_obj *obj)
// {
// 	int	i;
// 	int j;
// 	int start_line;
// 	int length;
// 	int prefix;
// 	int prefix_pos;

// 	obj->count_digit_on_face_line = malloc(sizeof(int) * obj->count_indexes);
// 	if (!(obj->count_digit_on_face_line))
// 		exit(88);
// 	j = 0;
// 	i = 0;
// 	start_line = 0;
// 	while (i < buf_size)
// 	{
// 		if (buf[i] == '\n')
// 		{
// 			length = i - start_line;
// 			start_line = i + 1;
// 			prefix_pos = i - length;
// 			prefix = buf[prefix_pos];
// 			if (prefix == 'f')
// 			{
// 				obj->count_digit_on_face_line[j] = get_count_faces_on_line_on_line(obj, buf, prefix_pos + 1, i);
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// }


void	read_obj(const char *filename, t_obj *obj, t_gl *gl)
{
	int fd;
	int returned_bytes;
	char buf[MAX_OBJ];

	returned_bytes = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 3)
		log_scop("Read obj::This is not a valid file\n", (enum errors)not_a_file);
	if ((returned_bytes = read(fd, &buf, MAX_OBJ)) >= MAX_OBJ - 1)
		log_scop("Read obj::This file is a giant\n", (enum errors)giant_file);
	close(fd);
	buf[returned_bytes] = '\0';
	get_count_attributes(returned_bytes, &buf[0], obj);
	if (obj->count_vertexes < 3)
		log_scop("Read obj::Count vertexes is empty\n", (enum errors)null_count_vertexes);
	if (obj->count_indexes <= 0)
		log_scop("Read obj::Count indexes is empty\n", (enum errors)null_count_indexes);
	obj->vertex_position = malloc(sizeof(float) * obj->count_vertexes * 3);
	if (!obj->vertex_position)
		log_scop("Read obj::Malloc can't allocate memory\n", (enum errors)malloc_error);
	obj->faces_array = malloc(sizeof(int) * obj->count_faces);
	if (!obj->faces_array)
		log_scop("Read obj::Malloc can't allocate memory\n", (enum errors)malloc_error);
	
	// get_count_digits_on_faces_line(returned_bytes, &buf[0], obj);
	
	obj->count_faces_on_line = malloc(sizeof(int) * obj->count_indexes);
	if (!(obj->count_faces_on_line))
		exit(88);

	validate_attributes(returned_bytes, &buf[0], obj);
	
	printf("read_obj\n");
	printf("count indexes = %d\n", obj->count_indexes);
	printf("count_faces = %d\n", obj->count_faces);
	translate_readed_obj_to_struct(obj, gl);
}

// faces_array - массив, в котором id вертексов нахдятся в правильном порядке
// vertex_position - записывается, всё ок
// obj->faces_array - записывается, всё ок

// [0], [1], [2], [3], [4], [\n]

// [6], [7], [8], [9], [10], [\n]


// https://www.youtube.com/watch?v=p6PqJPFOIm4