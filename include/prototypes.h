/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:05:07 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/18 19:17:48 by cvernius         ###   ########.fr       */
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

int		init_glfw(t_gl *gl);
void	create_triangle(t_scop *s);
char	*read_shader(const char *filename, char *shader);
void	create_shaders(t_shader *shader, int program_id);
int		render(t_scop *scop);
void	get_camera_values(t_camera *camera);
void	load_texture(t_scop *scop);

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