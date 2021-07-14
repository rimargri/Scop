/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 18:39:54 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
** ******************************************************************* **
** ******************************************************************* **
** glDrawArrays(GL_TRIANGLES, 0, 3) - draw points 0-3 from the ******* **
** currently bound VAO with current in-use shader ******************** **
** glfwSwapBuffers(scop->gl.window) - put the stuff we've been drawing **
** onto the display*************************************************** **
** ******************************************************************* **
** ******************************************************************* **
*/

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

		glDepthMask(GL_FALSE);
		glUseProgram(scop->skybox.id_shader);
		scop->skybox.rotation_mat_location = glGetUniformLocation(scop->skybox.id_shader, "rotation");
		if (scop->skybox.rotation_mat_location != -1)
		{
			glUniformMatrix4fv(scop->skybox.rotation_mat_location, 1, GL_TRUE, scop->matrix->rotate->xyzrotate.value);
		}
		scop->skybox.projection_mat_location = glGetUniformLocation(scop->skybox.id_shader, "projection");
		if (scop->skybox.projection_mat_location != -1)
		{
			glUniformMatrix4fv(scop->skybox.projection_mat_location, 1, GL_TRUE, scop->matrix->projection.value);
		}
		glBindVertexArray(scop->skybox.vao);
		glBindTexture(GL_TEXTURE_CUBE_MAP, scop->skybox.texture_id);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glDepthMask(GL_TRUE);


		glUseProgram(scop->gl->program_id);
		glBindTexture(GL_TEXTURE_2D, scop->texture.id);
		glBindVertexArray(scop->gl->vao);
		create_mvp_matrix(scop->matrix, &scop->input_transform);
		scop->gl->mvp_location = glGetUniformLocation(scop->gl->program_id, "mvp");
		if (scop->gl->mvp_location != -1)
		{
			glUniformMatrix4fv(scop->gl->mvp_location, 1, GL_TRUE, scop->matrix->mvp.value);
		}
		scop->gl->mix_value_location = glGetUniformLocation(scop->gl->program_id, "mix_value");
		if (scop->gl->mix_value_location != -1)
		{
		   glUniform1f(scop->gl->mix_value_location, scop->input_transform.mix_value);
		}
		glDrawArrays(GL_TRIANGLES, 0, scop->gl->count_vertexes);
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
