/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/08/02 15:46:29 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log_scop.h"
#include "scop.h"

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
	transform_val->mix_value = 0.0f;
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

	if (argc < 2 || argc > 2)
		log_scop("Main::Invalide arguments\n", (enum errors)invalide_arguments);
	if (!(scop = malloc(sizeof(t_scop))))
		log_scop("Main::Malloc can't allocate memory\n", (enum errors)malloc_error);
	print_micro_menu();
	allocate_mem(scop);
	init_glfw(scop->gl);
	init_input_transform_value(&scop->input_transform);
	create_mvp_matrix(scop->matrix, &scop->input_transform);
	read_obj(argv[1], &scop->obj, scop->gl);
	create_mesh(scop);
	create_shaders(scop->shader, &scop->gl->program_id);
	create_cube_skybox(scop);
	create_cubemap(scop);
	create_shaders_skybox(scop->shader, &scop->skybox.id_shader);
	load_texture(scop);
	glfwSetWindowUserPointer(scop->gl->window, scop);
	glfwSetKeyCallback(scop->gl->window, key_callback);
	render(scop);
	return (0);
}
