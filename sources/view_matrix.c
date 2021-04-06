/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:22:30 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/06 20:41:47 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libmat4/include/libmat4.h"
#include "../libvector/include/libvector.h"

t_mat4 camera_space(t_vec3 right_vec, t_vec3 up_vec, t_vec3 dir_vec)
{
	t_mat4 camera_space;

	camera_space.value[0] = right_vec.x;
	camera_space.value[1] = right_vec.y;
	camera_space.value[2] = right_vec.z;
	camera_space.value[3] = 0;

	camera_space.value[4] = up_vec.x;
	camera_space.value[5] = up_vec.y;
	camera_space.value[6] = up_vec.z;
	camera_space.value[7] = 0;

	camera_space.value[8] = dir_vec.x;
	camera_space.value[9] = dir_vec.y;
	camera_space.value[10] = dir_vec.z;
	camera_space.value[11] = 0;

	camera_space.value[12] = 0;
	camera_space.value[13] = 0;
	camera_space.value[14] = 0;
	camera_space.value[15] = 1;

	return (camera_space);
}

t_mat4 camera_position(t_vec3 camera_pos)
{
	t_mat4 cam_pos;

	cam_pos.value[0] = 1;
	cam_pos.value[1] = 0;
	cam_pos.value[2] = 0;
	cam_pos.value[3] = -camera_pos.x;

	cam_pos.value[4] = 0;
	cam_pos.value[5] = 1;
	cam_pos.value[6] = 0;
	cam_pos.value[7] = -camera_pos.y;

	cam_pos.value[8] = 0;
	cam_pos.value[9] = 0;
	cam_pos.value[10] = 1;
	cam_pos.value[11] = -camera_pos.z;

	cam_pos.value[12] = 0;
	cam_pos.value[13] = 0;
	cam_pos.value[14] = 0;
	cam_pos.value[15] = 1;

	return (cam_pos);
}

void get_camera_values(t_camera *camera)
{
	// camera->pos = (t_vec3){0.0f, 0.0f, 3.0f}; 
	camera->target = (t_vec3){0.0f, 0.0f, 0.0f};

	// t_vec3 up = (t_vec3){0.0f, 1.0f, 0.0f};
}

void create_view_matrix(t_opengl *opengl, t_camera camera)
{
	
	const float radius = 10.0f;
	float camX = sin(glfwGetTime() * radius);
	float camZ = cos(glfwGetTime() * radius);
	opengl->camera.pos = (t_vec3){camX, 0.0f, camZ}; 


	opengl->camera.reverse_dir = vec_normalize(vec_diff(opengl->camera.pos, opengl->camera.target));
	opengl->camera.right = vec_normalize(cross(UP_AXIS, opengl->camera.reverse_dir));
	// opengl->camera.up = cross(opengl->camera.reverse_dir, opengl->camera.right);
	opengl->camera.up = cross(opengl->camera.reverse_dir, opengl->camera.right);


	opengl->matrix->look_at = mult_matrix(camera_space(opengl->camera.right, UP_AXIS, opengl->camera.reverse_dir), camera_position(opengl->camera.pos));
	// opengl->matrix->look_at = mult_matrix(camera_space(opengl->camera.right, opengl->camera.up, opengl->camera.reverse_dir), camera_position(opengl->camera.pos));

}

// look_at(position, target, up)

// glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0)