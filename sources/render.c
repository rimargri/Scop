/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/11 15:19:14 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// glDrawArrays(GL_TRIANGLES, 0, 3) - draw points 0-3 from the
// currently bound VAO with current in-use shader

// glfwSwapBuffers(scop->gl.window) - put the stuff we've been drawing
// onto the display

void	free_gl_attributies(t_scop *scop)
{
	glDeleteBuffers(1, &scop->gl->vbo);
	glDeleteProgram(scop->gl->program_id);
	glDeleteVertexArraysAPPLE(1, &scop->gl->vao);
	glDeleteShader(scop->shader->vert_id);
	glDeleteShader(scop->shader->fragm_id);
	glfwTerminate();	
}

int		render(t_scop *scop)
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	while (glfwWindowShouldClose(scop->gl->window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(scop->gl->program_id);
		glBindTexture(GL_TEXTURE_2D, scop->texture.id);
		glBindVertexArray(scop->gl->vao);
		create_mvp_matrix(scop->matrix, &scop->input_transform);
		scop->gl->mvp_location = glGetUniformLocation(scop->gl->program_id, "mvp");
		create_shaders(scop->shader, scop->gl->program_id);


		glUniformMatrix4fv(scop->gl->mvp_location, 1, GL_TRUE, scop->matrix->mvp.value);
		glUniformMatrix4fv(scop->gl->model_location, 1, GL_TRUE, scop->matrix->model.value);
		glDrawArrays(GL_TRIANGLES, 0, scop->gl->count_vertexes);
		// glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();
		glfwSwapBuffers(scop->gl->window);
		if (glfwGetKey(scop->gl->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(scop->gl->window, 1);
		}
		events(scop);
	}
	free_gl_attributies(scop);
	return (0);
}


// glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles -> 6 squares
// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-4-a-colored-cube/

