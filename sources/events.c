/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 18:50:56 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	events_translate(t_vec3 *translate, GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		translate->z += 0.1f;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		translate->z -= 0.1f;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		translate->x -= 0.1f;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		translate->x += 0.1f;
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		translate->y += 0.1f;
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		translate->y -= 0.1f;
	}
}

void	events_scale(t_vec3 *scale, GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
	{
		scale->x *= 0.9f;
		scale->y *= 0.9f;
		scale->z *= 0.9f;
	}
	if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
	{
		scale->x /= 0.9f;
		scale->y /= 0.9f;
		scale->z /= 0.9f;
	}
}

void	events_rotate(t_vec3 *rotate, GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_RIGHT) != GLFW_PRESS)
	{
		rotate->y += 1.0f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		rotate->y -= 1.0f;
	}
	else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		rotate->x += 1.0f;
	}
	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		rotate->x -= 1.0f;
	}
}

void	event_wireframe_mode(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else if (glfwGetKey(window, GLFW_KEY_SPACE) != GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	static int num_text = 0;
	t_scop *scop;

	(void)mods;
	(void)scancode;
	scop = (t_scop *)glfwGetWindowUserPointer(window);
    if (key == GLFW_KEY_T && action == GLFW_PRESS)
	{
		num_text += 1;
		change_texture(scop, num_text);
	}
}

void	events(t_scop *scop)
{
	if (glfwGetKey(scop->gl->window, GLFW_KEY_ENTER) == GLFW_PRESS)
	{
		scop->input_transform.mix_value += 0.01f;
		if (scop->input_transform.mix_value > 1.0f)
		scop->input_transform.mix_value = 1.0f;
	}
	events_translate(&scop->input_transform.translate, scop->gl->window);
	events_scale(&scop->input_transform.scale, scop->gl->window);
	events_rotate(&scop->input_transform.rotate, scop->gl->window);
	event_wireframe_mode(scop->gl->window);
}
