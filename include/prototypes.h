/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:05:07 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/04 17:16:16 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvector/include/libvector.h"

int		init_gl(t_opengl *opengl);
void	create_shaders(t_scop *scop);
int		sc_gl_loop(t_scop *scop);
void	create_triangle(t_scop *s);
void	scale(t_vec3 scale_value, t_opengl *opengl);
void	add_matrix_to_opengl(t_opengl *opengl);
void	translate(t_vec3 translate_value, t_opengl *opengl);
void	rotation(t_vec3 angle, t_opengl *opengl);
void	create_model_matrix(t_opengl *opengl);
