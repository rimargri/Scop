/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_main_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/03/13 13:26:39 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// glDrawArrays(GL_TRIANGLES, 0, 3) - draw points 0-3 from the
// currently bound VAO with current in-use shader

// glfwSwapBuffers(scop->opengl.window) - put the stuff we've been drawing
// onto the display

int		sc_gl_loop(t_scop *scop)
{
	glBindBuffer(GL_ARRAY_BUFFER, scop->vertex_buffer);

	while (glfwGetKey(scop->opengl.window, GLFW_KEY_ESCAPE) != GLFW_PRESS
						&& glfwWindowShouldClose(scop->opengl.window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(scop->opengl.program_id);
		glBindVertexArray(scop->opengl.vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
		glfwSwapBuffers(scop->opengl.window);
	}
	glDeleteBuffers(1, &scop->opengl.vbo);
	glDeleteProgram(scop->opengl.program_id);
	glDeleteVertexArraysAPPLE(1, &scop->opengl.vao);
	glDeleteShader(scop->opengl.fragm_shader);
	glDeleteShader(scop->opengl.vert_shader);
	glfwTerminate();
	return (0);
}
