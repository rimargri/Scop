/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_main_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 20:08:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// glDrawArrays(GL_TRIANGLES, 0, 3) - draw points 0-3 from the
// currently bound VAO with current in-use shader

// glfwSwapBuffers(scop->opengl.window) - put the stuff we've been drawing
// onto the display

void	scp_gl_loop(t_scop *scop)
{
	while (glfwGetKey(scop->opengl.window, GLFW_KEY_ESCAPE) != GLFW_PRESS
						&& glfwWindowShouldClose(scop->opengl.window) == 0)
	{


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(scop->opengl.program_id);
	
		glUniformMatrix4fv(scop->opengl.matrix_id, 1, GL_FALSE, &scop->opengl.mvp[0][0]);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->opengl.buffer_vertex);
		glVertexAttribPointer(0, COUNT_VERTEX, GL_FLOAT, GL_FALSE, 0, NULL);

		glDrawArrays(GL_TRIANGLES, 0, COUNT_VERTEX);
		glDisableVertexAttribArray(0);
		//  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwPollEvents();
		glfwSwapBuffers(scop->opengl.window);
	}

	glDeleteBuffers(1, &scop->opengl.buffer_vertex);
	glDeleteProgram(scop->opengl.program_id);
	glDeleteVertexArraysAPPLE(1, &scop->opengl.array_vertex_id);
	glDeleteShader(scop->opengl.fragm_shader);
	glDeleteShader(scop->opengl.vert_shader);
	glfwTerminate();
	// exit(0);
}
