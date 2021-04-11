/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/04/11 18:12:06 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libvector/include/libvector.h"

// NDC - normalized device coordinates

// https://www.3dgep.com/understanding-the-view-matrix/

int		main(void)
{
	t_scop *scop;

	if (!(scop = malloc(sizeof(t_scop))))
		exit(99);
	if (!(scop->opengl = malloc(sizeof(t_opengl))))
		exit(99);
	if (!(scop->opengl->matrix = malloc(sizeof(t_matrix))))
		exit(99);
	if (!(scop->opengl->matrix->rotate = malloc(sizeof(t_rotate))))
		exit(99);
	if (init_gl(scop->opengl) == 0)
		exit(99);

	create_triangle(scop);

	create_model_matrix(scop->opengl);

	get_camera_values(&scop->opengl->camera);								// will be input from keyboard in future
	create_view_matrix(scop->opengl->matrix, scop->opengl->camera);
	create_projection_matrix(scop->opengl);
	create_mvp_matrix(scop->opengl);

	scop->opengl->program_id = glCreateProgram();
	create_shaders(scop);
	glAttachShader(scop->opengl->program_id, scop->opengl->fragm_shader);
	glAttachShader(scop->opengl->program_id, scop->opengl->vert_shader);
	glLinkProgram(scop->opengl->program_id);
	scop->opengl->mvp_location = glGetUniformLocation(scop->opengl->program_id, "mvp");
	printf("model lok : %d\n", scop->opengl->mvp_location);
	
	sc_gl_loop(scop);
}


// http://www.opengl-tutorial.org/ru/beginners-tutorials/tutorial-3-matrices/

// https://solarianprogrammer.com/2013/05/22/opengl-101-matrices-projection-view-model/

// https://learnopengl.com/Getting-started/Transformations

// https://www.cs.cornell.edu/courses/cs4620/2010fa/lectures/03transforms3d.pdf

// code:
// https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/7.1.camera_circle/camera_circle.cpp