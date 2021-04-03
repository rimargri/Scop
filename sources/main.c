/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/04/03 19:13:35 by cvernius         ###   ########.fr       */
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
	if (!(scop->opengl->matrix = malloc(sizeof(t_matrix))))
		exit(99);
	if (!(scop->opengl->matrix->rotate = malloc(sizeof(t_rotate))))
		exit(99);
	if (!(scop->opengl->matrix->model_matrix = malloc(sizeof(GLfloat) * 16)))
		exit(88);
	if (init_gl(scop->opengl) == 0)
		exit(99);

	create_triangle(scop);

	// translate((t_vec3){2.0, 0.0, 0.0}, scop->opengl);
	rotation((t_vec3){30, 30, 30}, scop->opengl);
	// scale((t_vec3){2, 0, 0}, scop->opengl);

	scop->opengl->program_id = glCreateProgram();
	create_shaders(scop);
	glAttachShader(scop->opengl->program_id, scop->opengl->fragm_shader);
	glAttachShader(scop->opengl->program_id, scop->opengl->vert_shader);
	glLinkProgram(scop->opengl->program_id);
	// scop->opengl->scale_location = glGetUniformLocation(scop->opengl->program_id, "scale");
	// scop->opengl->translate_location = glGetUniformLocation(scop->opengl->program_id, "translate");
	scop->opengl->rotate_location = glGetUniformLocation(scop->opengl->program_id, "rotate");
	sc_gl_loop(scop);
}

// http://www.opengl-tutorial.org/ru/beginners-tutorials/tutorial-3-matrices/

// https://solarianprogrammer.com/2013/05/22/opengl-101-matrices-projection-view-model/

// https://learnopengl.com/Getting-started/Transformations

// https://www.cs.cornell.edu/courses/cs4620/2010fa/lectures/03transforms3d.pdf
