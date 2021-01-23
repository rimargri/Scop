/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/01/08 16:39:53 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#include <stdio.h>

//  https://antongerdelan.net/opengl/hellotriangle.html

//  shader GLSL: https://thebookofshaders.com/06/



// https://open.gl/drawing
// https://open.gl/content/code/c2_triangle_elements.txt

int		main(void)
{
	t_scop *scop;

	if (!(scop = malloc(sizeof(t_scop))))
		error_processing(MLX_ERROR, 0);
	init_gl(&scop->opengl);
	create_shape(scop);
	create_shaders(scop);
	create_model_view_projection_mat(scop);
	scp_gl_loop(scop);
}

// http://www.opengl-tutorial.org/ru/beginners-tutorials/tutorial-2-the-first-triangle/
// http://www.opengl-tutorial.org/ru/beginners-tutorials/tutorial-3-matrices/



// http://learnwebgl.brown37.net/08_projections/projections_perspective.html

// https://learnopengl.com/Getting-started/Coordinate-Systems

// http://learnwebgl.brown37.net/08_projections/projections_perspective.html


// https://github.com/opengl-tutorials/ogl