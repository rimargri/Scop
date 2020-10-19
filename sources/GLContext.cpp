/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLContext.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:00:09 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/20 00:00:33 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GLContext.hpp"

GLContext::GLContext(ErrorsProcess err) {
	if (!glfwInit())
		err.printErrAndExit(err.Errors::FAIL_GLFW, 0);

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(700, 500, "scop", NULL, NULL);
	if (!window)
		err.printErrAndExit(err.Errors::FAIL_WIN_GLFW, 0);

	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glewExperimental = GL_TRUE; 
	if (glewInit() != 0)
		err.printErrAndExit(err.Errors::FAIL_GLEW, 0);
}

void	GLContext::glLoop(void) {
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
					&& glfwWindowShouldClose(window) == 0)
	{
		// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
