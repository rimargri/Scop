/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:05:07 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/09 14:45:45 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "../libvector/include/libvector.h"

/*
** *********************************** **
** *********************************** **
**           		 scop	           **
** *********************************** **
** *********************************** **
*/

void	init_glfw(t_gl *gl);
void	create_triangle(t_scop *s);
void	create_shaders(t_shader *shader, int program_id);
int		render(t_scop *scop);
void	get_camera_values(t_camera *camera);
void	load_texture(t_scop *scop);
// void	validate_index(t_obj *obj, char *buf, int start, int finish);
void	translate_readed_obj_to_struct(t_obj *obj, t_gl *gl);
void	read_obj(const char *filename, t_obj *obj, t_gl *gl);

int		get_count_faces_on_line(t_obj *obj, char *buf, int start, int finish);

/*
** *********************************** **
** *********************************** **
**           		 matrix	           **
** *********************************** **
** *********************************** **
*/

void	scale(t_vec3 scale_value, t_matrix *matrix);
void	translate(t_vec3 translate_value, t_matrix *matrix);
void	rotate(t_vec3 angle, t_matrix *matrix);
void	create_model_matrix(t_matrix *matrix);
void	create_view_matrix(t_matrix *matrix, t_camera camera);
void	create_projection_matrix(t_matrix *matrix);
void	create_mvp_matrix(t_matrix *matrix);


#endif