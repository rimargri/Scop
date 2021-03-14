/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/03/14 20:48:19 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libvector/include/libvector.h"

int		main(void)
{
	t_scop *scop;

	if (!(scop = malloc(sizeof(t_scop))))
		return (0);
	if (init_gl(&scop->opengl) == 0)
		return (0);
	create_triangle(scop);
	scale((t_vec3){2, 0 ,0}, &scop->opengl);
	add_matrix_to_opengl(&scop->opengl);
	create_shaders(scop);
	glAttachShader(scop->opengl.program_id, scop->opengl.fragm_shader);
	glAttachShader(scop->opengl.program_id, scop->opengl.vert_shader);
	glLinkProgram(scop->opengl.program_id);
	sc_gl_loop(scop);
}

// http://www.opengl-tutorial.org/ru/beginners-tutorials/tutorial-3-matrices/

// https://solarianprogrammer.com/2013/05/22/opengl-101-matrices-projection-view-model/

// https://learnopengl.com/Getting-started/Transformations