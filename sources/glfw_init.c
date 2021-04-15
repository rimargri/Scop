/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:03:54 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/15 17:23:09 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	compatibility_settings(void)
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int		init_glfw(t_gl *gl)
{
	if (!glfwInit())
	{
		printf("failed to inicialize glfw!\n");
		return (-1);
	}
	compatibility_settings();
	gl->window = glfwCreateWindow(WIN_W, WIN_H, "scop", NULL, NULL);
	if (!gl->window)
	{
		printf("Failed to open GLFW gl window.\n");
		return (-1);
	}
	glfwMakeContextCurrent(gl->window);
	glfwSetInputMode(gl->window, GLFW_STICKY_KEYS, GL_TRUE); // esc work
	return (1);
}
