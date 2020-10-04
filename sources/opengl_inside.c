/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_inside.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:03:54 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/04 20:53:01 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_gl_loop(t_scop *scop)
{
	while (glfwGetKey(scop->opengl.window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(scop->opengl.window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		// drawing
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->vertex_buffer);
		glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);

		glfwSwapBuffers(scop->opengl.window);
		glfwPollEvents();
	}
	return (0);
}

void	scop_gl_property(void)
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int		init_gl(t_opengl *opengl)
{
	if (!glfwInit())
	{
		printf("failed to inicialize glfw!\n");
		return (-1);
	}
	scop_gl_property();
	opengl->window = glfwCreateWindow(700, 500, "scop", NULL, NULL);
	if (!opengl->window)
	{
		printf("Failed to open GLFW opengl window.\n");
		return (-1);
	}
	glfwMakeContextCurrent(opengl->window);
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glfwSetInputMode(opengl->window, GLFW_STICKY_KEYS, GL_TRUE); // esc work
	return (1);
}
