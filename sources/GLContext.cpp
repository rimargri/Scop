/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLContext.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:00:09 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/21 18:29:56 by f0rsunka         ###   ########.fr       */
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

void	GLContext::glLoop(GLuint shaderProgramme, GLuint vao) {
	// GLint uniformColor = glGetUniformLocation(shaderProgramme, "input_color");
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
					&& glfwWindowShouldClose(window) == 0)
	{
		// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// glUseProgram(shaderProgramme);

		// GLfloat timeValue = glfwGetTime();
		// GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
		// std::cout << "aa\n" << std::endl;
		// GLint vertexColorLocation = glGetUniformLocation(shaderProgramme, "out_color");
		// glUniform4f(uniformColor, 0.0f, greenValue, 0.0f, 1.0f);
		// glBindVertexArray(vao);
		// glBindVertexArray(0);
		// glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
