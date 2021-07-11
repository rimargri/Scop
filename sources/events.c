/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/11 12:50:28 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	events_translate(t_vec3 *translate, GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		translate->z += 5.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		translate->z -= 5.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		translate->x -= 5.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		translate->x += 5.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		translate->y += 5.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		translate->y -= 5.0f;
	}
}

void	events_scale(t_vec3 *scale, GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
	{
		scale->x *= 5.0f;
		scale->y *= 5.0f;
		scale->z *= 5.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
	{
		scale->x /= 5.0f;
		scale->y /= 5.0f;
		scale->z /= 5.0f;
	}
}

void	events_rotate(t_vec3 *rotate, GLFWwindow *window)
{
	// static float alpha = 0.0f;

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

void	events(t_scop *scop)
{
	int num_text;

	if (glfwGetKey(scop->gl->window, GLFW_KEY_T) == GLFW_PRESS)
	{
		num_text += 1;
		// change_texture(scop);
		change_texture(scop, num_text);
	}
	events_translate(&scop->input_transform.translate, scop->gl->window);
	events_scale(&scop->input_transform.scale, scop->gl->window);
	events_rotate(&scop->input_transform.rotate, scop->gl->window);
	event_wireframe_mode(scop->gl->window);
}

// https://stackoverflow.com/questions/137629/how-do-you-render-primitives-as-wireframes-in-opengl