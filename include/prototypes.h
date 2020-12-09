/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:05:07 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 19:17:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_gl(t_opengl *opengl);
void	create_shaders(t_scop *scop);
void	scp_gl_loop(t_scop *scop);
void	create_shape(t_scop *s);
void	error_processing(int code, void *param);

/*
** *********************************** **
** *********************************** **
**      	perspective matrix         **
** *********************************** **
** *********************************** **
*/

t_mat4	build_perspective_projection(t_scop *s);
t_mat4	create_frustum(t_frustum frustum);
t_mat4	perspective_calculation(void);
t_mat4	mapping_depth(void);
t_mat4	scale_view_window(t_frustum frustum);


/*
** *********************************** **
** *********************************** **
**           	mvp matrix             **
** *********************************** **
** *********************************** **
*/

void	create_model_view_projection_mat(t_scop *s);
t_mat4	create_model_mat(void);
t_mat4	create_view_mat(t_vec3 eye, t_vec3 center, t_vec3 up);



