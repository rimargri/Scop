/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_glfw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:03:54 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/20 18:29:34 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "log_scop.h"

void	compatibility_settings(void)
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void	init_glfw(t_gl *gl)
{
	if (!glfwInit())
		log_scop("GLFW::Failed to initalize GLFW.\0", (enum errors)glfw_not_init);
	compatibility_settings();
	gl->window = glfwCreateWindow(WIN_W, WIN_H, "scop", NULL, NULL);
	if (!gl->window)
		log_scop("GLFW::Failed to open GLFW gl window.\0", (enum errors)window_not_open);
	glfwMakeContextCurrent(gl->window);
	glfwSetInputMode(gl->window, GLFW_STICKY_KEYS, GL_TRUE); // esc work
}
