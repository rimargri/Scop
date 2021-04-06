/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:22:30 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/06 19:31:32 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libmat4/include/libmat4.h"
#include "../libvector/include/libvector.h"

t_mat4 coordinate_space(t_vec3 right_vec, t_vec3 up_vec, t_vec3 dir_vec)
{
	t_mat4 coordinate_space;

	coordinate_space.value[0] = right_vec.x;
	coordinate_space.value[1] = right_vec.y;
	coordinate_space.value[2] = right_vec.z;
	coordinate_space.value[3] = 0;

	coordinate_space.value[4] = up_vec.x;
	coordinate_space.value[5] = up_vec.y;
	coordinate_space.value[6] = up_vec.z;
	coordinate_space.value[7] = 0;

	coordinate_space.value[8] = dir_vec.x;
	coordinate_space.value[9] = dir_vec.y;
	coordinate_space.value[10] = dir_vec.z;
	coordinate_space.value[11] = 0;

	coordinate_space.value[12] = 0;
	coordinate_space.value[13] = 0;
	coordinate_space.value[14] = 0;
	coordinate_space.value[15] = 1;

	return (coordinate_space);
}

t_mat4 camera_position(t_vec3 cam_pos)
{
	t_mat4 camera_pos;

	camera_pos.value[0] = 1;
	camera_pos.value[1] = 0;
	camera_pos.value[2] = 0;
	camera_pos.value[3] = -cam_pos.x;

	camera_pos.value[4] = 0;
	camera_pos.value[5] = 1;
	camera_pos.value[6] = 0;
	camera_pos.value[7] = -cam_pos.y;

	camera_pos.value[8] = 0;
	camera_pos.value[9] = 0;
	camera_pos.value[10] = 1;
	camera_pos.value[11] = -cam_pos.z;

	camera_pos.value[12] = 0;
	camera_pos.value[13] = 0;
	camera_pos.value[14] = 0;
	camera_pos.value[15] = 1;

	return (camera_pos);
}

void create_view_matrix(t_opengl *opengl, t_camera camera)
{
	opengl->camera.pos = (t_vec3){0.0f, 0.0f, 3.0f}; 
	opengl->camera.target = (t_vec3){0.0f, 0.0f, 0.0f};
	opengl->camera.reverse_dir = vec_normalize(vec_diff(opengl->camera.pos, opengl->camera.target));
	t_vec3 up = (t_vec3){0.0f, 1.0f, 0.0f};
	opengl->camera.right = vec_normalize(cross(up, opengl->camera.reverse_dir));
	opengl->camera.up = cross(opengl->camera.reverse_dir, opengl->camera.right);

	opengl->matrix.look_at = mult_matrix(coordinate_space(opengl->camera.right, opengl->camera.up, opengl->camera.reverse_dir), camera_position(opengl->camera.pos));

}
