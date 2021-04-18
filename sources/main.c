/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/04/18 20:33:51 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libvector/include/libvector.h"

// NDC - normalized device coordinates

// https://www.3dgep.com/understanding-the-view-matrix/

void	allocate_mem(t_scop *scop)
{
	if (!(scop->gl = malloc(sizeof(t_gl))))
		exit(99);	// ERROR: MALLOC
	if (!(scop->matrix = malloc(sizeof(t_matrix))))
		exit(99);	// ERROR: MALLOC
	if (!(scop->matrix->rotate = malloc(sizeof(t_rotate))))
		exit(99);	// ERROR: MALLOC
	if (!(scop->shader = malloc(sizeof(t_shader))))
		exit(99);	// ERROR: MALLOC
}

int		main(void)
{
	t_scop *scop;

	if (!(scop = malloc(sizeof(t_scop))))
		exit(99);	// ERROR: MALLOC
	allocate_mem(scop);
	if (init_glfw(scop->gl) == 0)
		exit(99); // ERROR: init glfw
	scop->gl->program_id = glCreateProgram();

// reading .obj

	create_triangle(scop);
	create_shaders(scop->shader, scop->gl->program_id);
	load_texture(scop);
	glLinkProgram(scop->gl->program_id);
	render(scop);
	return (0);
}













// http://www.gl-tutorial.org/ru/beginners-tutorials/tutorial-3-matrices/

// https://solarianprogrammer.com/2013/05/22/gl-101-matrices-projection-view-model/

// https://learngl.com/Getting-started/Transformations

// https://www.cs.cornell.edu/courses/cs4620/2010fa/lectures/03transforms3d.pdf

// code:
// https://learngl.com/code_viewer_gh.php?code=src/1.getting_started/7.1.camera_circle/camera_circle.cpp