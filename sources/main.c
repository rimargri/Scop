/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/07/11 19:48:38 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log_scop.h"
#include "scop.h"

// NDC - normalized device coordinates

// https://www.3dgep.com/understanding-the-view-matrix/

void	init_input_transform_value(t_input_transform *transform_val)
{
	transform_val->translate.x = 0.0f;
	transform_val->translate.y = 0.0f;
	transform_val->translate.z = 3.0f;
	transform_val->rotate.x = 0.0f;
	transform_val->rotate.y = 0.0f;
	transform_val->rotate.z = 0.0f;
	transform_val->scale.x = 1.0f;
	transform_val->scale.y = 1.0f;
	transform_val->scale.z = 1.0f;
}

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
	init_input_transform_value(&scop->input_transform);
	create_mvp_matrix(scop->matrix, &scop->input_transform);
	read_obj("models/42.obj", &scop->obj, scop->gl);
	create_mesh(scop);
	create_shaders(scop->shader, scop->gl->program_id);
	load_texture(scop);
	glLinkProgram(scop->gl->program_id);
	glfwSetWindowUserPointer(scop->gl->window, scop);
	glfwSetKeyCallback(scop->gl->window, key_callback);
	render(scop);
	return (0);
}













// http://www.gl-tutorial.org/ru/beginners-tutorials/tutorial-3-matrices/

// https://solarianprogrammer.com/2013/05/22/gl-101-matrices-projection-view-model/

// https://learngl.com/Getting-started/Transformations

// https://www.cs.cornell.edu/courses/cs4620/2010fa/lectures/03transforms3d.pdf

// code:
// https://learngl.com/code_viewer_gh.php?code=src/1.getting_started/7.1.camera_circle/camera_circle.cpp


