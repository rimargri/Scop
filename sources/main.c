/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/04/04 18:26:50 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "../libvector/include/libvector.h"

int		main(void)
{
	t_scop *scop;

	if (!(scop = malloc(sizeof(t_scop))))
		exit(99);
	if (!(scop->opengl = malloc(sizeof(t_opengl))))
		exit(99);
	if (!(scop->opengl->matrix = malloc(sizeof(t_transform_matrix))))
		exit(99);
	if (!(scop->opengl->matrix->rotate = malloc(sizeof(t_rotate))))
		exit(99);
	if (init_gl(scop->opengl) == 0)
		exit(99);

	create_triangle(scop);
	create_model_matrix(scop->opengl);

	scop->opengl->program_id = glCreateProgram();
	create_shaders(scop);
	glAttachShader(scop->opengl->program_id, scop->opengl->fragm_shader);
	glAttachShader(scop->opengl->program_id, scop->opengl->vert_shader);
	glLinkProgram(scop->opengl->program_id);
	scop->opengl->model_location = glGetUniformLocation(scop->opengl->program_id, "modelmat");
	printf("model lok : %d\n", scop->opengl->model_location);
	
	printf("\nmodel mat\n");
	for (int i = 0; i < 16; i++) {
		printf("model = %f\n", scop->opengl->matrix->model.value[i]);
	}

	sc_gl_loop(scop);
}


// http://www.opengl-tutorial.org/ru/beginners-tutorials/tutorial-3-matrices/

// https://solarianprogrammer.com/2013/05/22/opengl-101-matrices-projection-view-model/

// https://learnopengl.com/Getting-started/Transformations

// https://www.cs.cornell.edu/courses/cs4620/2010fa/lectures/03transforms3d.pdf
