/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_main_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/01/23 18:18:03 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// glDrawArrays(GL_TRIANGLES, 0, 3) - draw points 0-3 from the
// currently bound VAO with current in-use shader

// glfwSwapBuffers(scop->opengl.window) - put the stuff we've been drawing
// onto the display
#include <stdio.h>

void	scp_gl_loop(t_scop *scop)
{
	// const GLfloat mvp[] = {
	// 	1.0f, 0.0f, 0.0f, 0.0f,
	// 	0.0f, 1.0f, 0.0f, 0.0f,
	// 	0.0f, 0.0f, 1.0f, 0.0f,
	// 	0.0f, 0.0f, 0.0f, 1.0f		
	// };

	// scop->opengl.matrix_id = glGetUniformLocation(scop->opengl.program_id, "mvp");

	// glUniformMatrix4fv(scop->opengl.matrix_id, 1, GL_FALSE, modelviewmatrix);
	
	for (int i = 0; i < 16; i++)
		printf("%f\n", scop->opengl.mvp[i]);

	while (glfwGetKey(scop->opengl.window, GLFW_KEY_ESCAPE) != GLFW_PRESS
						&& glfwWindowShouldClose(scop->opengl.window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(scop->opengl.program_id);

		glUniformMatrix4fv(scop->opengl.matrix_id, 1, GL_FALSE, scop->opengl.mvp);

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
