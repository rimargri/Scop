/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/07/09 18:10:14 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log_scop.h"
#include "scop.h"

// NDC - normalized device coordinates

// https://www.3dgep.com/understanding-the-view-matrix/

void	allocate_mem(t_scop *scop)
{
	if (!(scop->gl = malloc(sizeof(t_gl))))
		log_scop("Main(gl)::Malloc can't allocate memory\n", (enum errors)malloc_error);
	if (!(scop->matrix = malloc(sizeof(t_matrix))))
		log_scop("Main(matrix)::Malloc can't allocate memory\n", (enum errors)malloc_error);
	if (!(scop->matrix->rotate = malloc(sizeof(t_rotate))))
		log_scop("Main(rotate)::Malloc can't allocate memory\n", (enum errors)malloc_error);
	if (!(scop->shader = malloc(sizeof(t_shader))))
		log_scop("Main(shader)::Malloc can't allocate memory\n", (enum errors)malloc_error);
}

int		main(int argc, char **argv)
{
	t_scop *scop;

	if (!(scop = malloc(sizeof(t_scop))))
		log_scop("Main::Malloc can't allocate memory\n", (enum errors)malloc_error);
	allocate_mem(scop);
	init_glfw(scop->gl);
	scop->gl->program_id = glCreateProgram();
	create_mvp_matrix(scop->matrix);
	read_obj("models/cube.obj", &scop->obj, scop->gl);
	create_mesh(scop);
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


