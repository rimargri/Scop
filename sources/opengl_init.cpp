/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_init.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:03:54 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/14 18:18:17 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.hpp"

void	sc_gl_property(void)
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

/*
** glfwSetInputMode(opengl->window, GLFW_STICKY_KEYS, GL_TRUE) - esc work
*/

void		init_gl(t_opengl *opengl)
{
	if (!glfwInit())
		error_processing(FAIL_GLFW, 0);
	sc_gl_property();
	opengl->window = glfwCreateWindow(700, 500, "scop", NULL, NULL);
	if (!opengl->window)
		error_processing(FAIL_WIN_GLFW, 0);
	glfwMakeContextCurrent(opengl->window);
	glfwSetInputMode(opengl->window, GLFW_STICKY_KEYS, GL_TRUE);
	glewExperimental = GL_TRUE; 
	if (glewInit() != 0)
		error_processing(FAIL_GLEW, 0);
}
