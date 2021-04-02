/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_main_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/02 21:13:17 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// glDrawArrays(GL_TRIANGLES, 0, 3) - draw points 0-3 from the
// currently bound VAO with current in-use shader

// glfwSwapBuffers(scop->opengl.window) - put the stuff we've been drawing
// onto the display

int		sc_gl_loop(t_scop *scop)
{
	// scop->opengl->matrix->scale[0] = 2;
	// scop->opengl->matrix->scale[1] = 0;
	// scop->opengl->matrix->scale[2] = 0;
	// scop->opengl->matrix->scale[3] = 0;

	// scop->opengl->matrix->scale[4] = 0;
	// scop->opengl->matrix->scale[5] = 2;
	// scop->opengl->matrix->scale[6] = 0;
	// scop->opengl->matrix->scale[7] = 0;

	// scop->opengl->matrix->scale[8] = 0;
	// scop->opengl->matrix->scale[9] = 0;
	// scop->opengl->matrix->scale[10] = 2;
	// scop->opengl->matrix->scale[11] = 1;

	// scop->opengl->matrix->scale[12] = 0;
	// scop->opengl->matrix->scale[13] = 0;
	// scop->opengl->matrix->scale[14] = 0;
	// scop->opengl->matrix->scale[15] = 1;


	float scale[16];

	scale[0] = 2;
	scale[1] = 0;
	scale[2] = 0;
	scale[3] = 0;

	scale[4] = 0;
	scale[5] = 2;
	scale[6] = 0;
	scale[7] = 0;

	scale[8] = 0;
	scale[9] = 0;
	scale[10] = 2;
	scale[11] = 1;

	scale[12] = 0;
	scale[13] = 0;
	scale[14] = 0;
	scale[15] = 1;


	// GLint scale_location = glGetUniformLocation(scop->opengl->program_id, "scale");
	scop->opengl->scale_location = glGetUniformLocation(scop->opengl->program_id, "scale");

	while (glfwGetKey(scop->opengl->window, GLFW_KEY_ESCAPE) != GLFW_PRESS
						&& glfwWindowShouldClose(scop->opengl->window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(scop->opengl->program_id);
		glUniformMatrix4fv(scop->opengl->scale_location, 1, GL_FALSE, scale);
		// glUniformMatrix4fv(scop->opengl->scale_location, 1, GL_FALSE, scop->opengl->matrix->scale);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
		glfwSwapBuffers(scop->opengl->window);
	}
	glDeleteBuffers(1, &scop->opengl->vbo);
	glDeleteProgram(scop->opengl->program_id);
	glDeleteVertexArraysAPPLE(1, &scop->opengl->vao);
	glDeleteShader(scop->opengl->fragm_shader);
	glDeleteShader(scop->opengl->vert_shader);
	glfwTerminate();
	return (0);
}


// int		sc_gl_loop(t_scop *scop)
// {
// 	while (glfwGetKey(scop->opengl.window, GLFW_KEY_ESCAPE) != GLFW_PRESS
// 						&& glfwWindowShouldClose(scop->opengl.window) == 0)
// 	{
// 		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 		glUseProgram(scop->opengl.program_id);
// 		glUniformMatrix4fv(scop->opengl.scale_location, 1, GL_FALSE, scop->opengl.matrix.scale);
// 		glDrawArrays(GL_TRIANGLES, 0, 3);
// 		glfwPollEvents();
// 		glfwSwapBuffers(scop->opengl.window);
// 	}
// 	glDeleteBuffers(1, &scop->opengl.vbo);
// 	glDeleteProgram(scop->opengl.program_id);
// 	glDeleteVertexArraysAPPLE(1, &scop->opengl.vao);
// 	glDeleteShader(scop->opengl.fragm_shader);
// 	glDeleteShader(scop->opengl.vert_shader);
// 	glfwTerminate();
// 	return (0);
// }
