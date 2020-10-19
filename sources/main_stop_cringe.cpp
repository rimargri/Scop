/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/18 22:08:51 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.hpp"

//  https://antongerdelan.net/opengl/hellotriangle.html

//  shader GLSL: https://thebookofshaders.cppom/06/

// https://open.gl/drawing
// https://open.gl/content/code/c2_triangle_elements.txt

// http://xed.ch/help/opengl.html

int		main(void)
{


	GLFWwindow	*window;
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;
	GLuint		vert_shader;
	GLuint		fragm_shader;
	GLuint		shader_programme;
	// t_scop *scop;

	// scop = new t_scop();
	// if (!(scop))
	// 	error_processing(MALLOC_ERROR, 0);

	if (!glfwInit())
		error_processing(FAIL_GLFW, 0);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(700, 500, "scop", NULL, NULL);
	if (!window)
		error_processing(FAIL_WIN_GLFW, 0);
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


	printf("aaa\n");


	// t_shape  shape;

	// shape.array_vertex = new float(COUNT_VERTEX);
	// printf("sc_get_vertex_shape\n");
	// if (!(shape.array_vertex))
	// 	error_processing(MALLOC_ERROR, 0);
	// printf("1\n");
	// shape.array_vertex[0] = -0.5f;
	// shape.array_vertex[1] = -0.5f;
	// shape.array_vertex[2] = 0.0f;

	// shape.array_vertex[3] = 0.5f;
	// shape.array_vertex[4] = -0.5f;
	// shape.array_vertex[5] = 0.0f;

	// shape.array_vertex[6] = -0.5f;
	// shape.array_vertex[7] = 0.5f;
	// shape.array_vertex[8] = 0.0f;

	// shape.array_vertex[9] = 0.5f;
	// shape.array_vertex[10] = 0.5f;
	// shape.array_vertex[11] = 0.0f;

    GLfloat array_vertex[] = {
        -0.5f,
		-0.5f,
		0.0f,

		0.5f,
		-0.5f,
		0.0f,

		-0.5f,
		0.5f,
		0.0f,

		0.5f,
		0.5f,
		0.0f
    };

	printf("inside x2\n");
	glGenVertexArrays(1, &vao);
	printf("glGenVertexArrays\n");
	glBindVertexArray(vao);
	printf("glBindVertexArray\n");

	glGenBuffers(1, &vbo);
	printf("glGenBuffers\n");
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	printf("glBindBuffer\n");
	glBufferData(GL_ARRAY_BUFFER, sizeof(array_vertex), array_vertex, GL_STATIC_DRAW);
	printf("glBufferData\n");
	printf("wtf\n");
	// Create an element array

    glGenBuffers(1, &ebo);
    GLuint elements[] = {
        0, 1, 2,
        2, 1, 3
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);




	printf("bbb\n");


	const char* vertex_shader =
	"#version 400\n"
	"in vec3 vp;"
	"void main() {"
	"  gl_Position = vec4(vp, 1.0);"
	"}";

	const char* fragment_shader =
	"#version 400\n"
	"out vec4 frag_colour;"
	"void main() {"
	"  frag_colour = vec4(0.5, 0.4, 0.5, 1.0);"
	"}";

	int lparams;

	lparams = -1;
	vert_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert_shader, 1, &vertex_shader, NULL);
	glCompileShader(vert_shader);
	glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &lparams);
	// if (GL_TRUE != lparams)
	// 	error_processing(ERROR_VERT_SHADER_INDEX, &vert_shader);


	lparams = -1;
	fragm_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragm_shader, 1, &fragment_shader, NULL);
	glCompileShader(fragm_shader);
	glGetShaderiv(fragm_shader, GL_COMPILE_STATUS, &lparams);
	// if (GL_TRUE != lparams)
	// 	error_processing(ERROR_FRAGM_SHADER_INDEX, &fragm_shader);
	printf("all shaders was created\n");
	lparams = -1;
	shader_programme = glCreateProgram();
	glAttachShader(shader_programme, vert_shader);
	glAttachShader(shader_programme, fragm_shader);
    // glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shader_programme);
	// glDeleteShader(vert_shader);
	// glDeleteShader(fragm_shader);
	glGetShaderiv(shader_programme, GL_LINK_STATUS, &lparams);
	glUseProgram(shader_programme);
	

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
						&& glfwWindowShouldClose(window) == 0)
	{
		// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		// glUseProgram(shader_programme);
		// glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glDeleteProgram(shader_programme);
	glDeleteShader(fragm_shader);
	glDeleteShader(vert_shader);

	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);

	// window.close();

	// exit(0);
	return (0);

}


