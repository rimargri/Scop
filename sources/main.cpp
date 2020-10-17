/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/17 22:50:08 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.hpp"

//  https://antongerdelan.net/opengl/hellotriangle.html

//  shader GLSL: https://thebookofshaders.cppom/06/



// https://open.gl/drawing
// https://open.gl/content/code/c2_triangle_elements.txt

int		main(void)
{
	t_scop *scop;

	scop = new t_scop();
	if (!(scop))
		error_processing(MALLOC_ERROR, 0);
	init_gl(&scop->opengl);
	printf("aaa\n");
	create_shape(scop);
	printf("bbb\n");
	create_shaders(scop);
	printf("ccc\n");
	sc_gl_loop(scop);
}
