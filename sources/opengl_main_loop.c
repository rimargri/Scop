/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_main_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/17 19:11:43 by f0rsunka         ###   ########.fr       */
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
		glUseProgram(scop->opengl.shader_programme);
	
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->opengl.buffer_vertex);
		glVertexAttribPointer(0, COUNT_VERTEX, GL_FLOAT, GL_FALSE, 0, NULL);

	
		glDrawArrays(GL_TRIANGLES, 0, COUNT_VERTEX);

		glDisableVertexAttribArray(0);
		//  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwPollEvents();
		glfwSwapBuffers(scop->opengl.window);
	}

	glDeleteProgram(scop->opengl.shader_programme);
	glDeleteShader(scop->opengl.fragm_shader);
	glDeleteShader(scop->opengl.vert_shader);

	// glDeleteBuffers(1, &scop->opengl.ebo);
	// glDeleteBuffers(1, &scop->opengl.vbo);

	// glDeleteVertexArrays(1, &scop->opengl.vao);

	// scop->opengl.window.close();

	exit(0);
}
