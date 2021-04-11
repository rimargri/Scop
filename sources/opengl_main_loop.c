/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_main_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/11 18:14:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// glDrawArrays(GL_TRIANGLES, 0, 3) - draw points 0-3 from the
// currently bound VAO with current in-use shader

// glfwSwapBuffers(scop->opengl.window) - put the stuff we've been drawing
// onto the display

int		sc_gl_loop(t_scop *scop)
{
	while (glfwWindowShouldClose(scop->opengl->window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(scop->opengl->program_id);
		create_model_matrix(scop->opengl);
		create_mvp_matrix(scop->opengl);
		glUniformMatrix4fv(scop->opengl->mvp_location, 1, GL_TRUE, scop->opengl->matrix->mvp.value);			// FALSE or TRUE  (transparent matrix) -- ??
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
		glfwSwapBuffers(scop->opengl->window);

		if (glfwGetKey(scop->opengl->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(scop->opengl->window, 1);
		}
	}
	glDeleteBuffers(1, &scop->opengl->vbo);
	glDeleteProgram(scop->opengl->program_id);
	glDeleteVertexArraysAPPLE(1, &scop->opengl->vao);
	glDeleteShader(scop->opengl->fragm_shader);
	glDeleteShader(scop->opengl->vert_shader);
	glfwTerminate();
	return (0);
}
