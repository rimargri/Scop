/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:06:03 by cvernius          #+#    #+#             */
/*   Updated: 2021/08/02 15:45:54 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "../libmat4/include/libmat4.h"
#include "obj_load.h"

#define SKYBOX_TEXT 6

typedef struct			s_texture
{
	int					width;
	int					height;
	unsigned char		*data;
	unsigned int		id;
}						t_texture;

// typedef struct			s_camera
// {
// 	t_vec3				pos;
// 	t_vec3				target;
// 	t_vec3				reverse_dir;
// 	t_vec3				right;
// 	t_vec3				up;
// }						t_camera;

typedef struct			s_rotate
{
	t_mat4				x;
	t_mat4				y;
	t_mat4				z;
	t_mat4				xyzrotate;
}						t_rotate;

typedef struct			s_input_transform
{
	t_vec3				translate;
	t_vec3				rotate;
	t_vec3				scale;
	float				mix_value;
}						t_input_transform;

typedef struct			s_matrix		
{
	t_mat4				model;							// model matrix
	t_mat4				scale;							// model matrix
	t_mat4				translate;						// model matrix
	t_rotate			*rotate;						// model matrix
	t_mat4				look_at;						// view matrix
	t_mat4				projection;
	t_mat4				mvp;
}						t_matrix;

typedef struct			s_shader
{
	GLuint				vert_id;
	GLuint				fragm_id;
	char				*vertex_shader;
	char				*fragment_shader;
	char				*vertex_shader_skybox;
	char				*fragment_shader_skybox;
	GLuint				vert_skybox_id;
	GLuint				fragm_skybox_id;
}						t_shader;

typedef struct			s_skybox
{
	unsigned int		texture_id;
	t_texture			textures[SKYBOX_TEXT];
	int					count_textures;
	GLuint				vbo;
	GLuint				vao;
	int					id_shader;
	GLint				projection_mat_location;
	GLint				rotation_mat_location;
}						t_skybox;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_gl
{
	GLFWwindow			*window;
	GLuint				vbo;
	GLuint				vao;
	GLuint				color_buffer;
	GLuint				program_id;
	GLint				mvp_location;
	GLint				model_location;
	GLint				mix_value_location;
	GLint				color_location;
	int					count_vertexes;
	float				*vertex_color;
	GLint				projection_location;
}						t_gl;

typedef struct			s_scop
{
	t_gl				*gl;
	t_matrix			*matrix;
	t_shader			*shader;
	t_texture			texture; // remove
	t_texture			*array_textures;
	t_obj				obj;
	t_input_transform	input_transform;
	t_skybox			skybox;
}						t_scop;

#endif
