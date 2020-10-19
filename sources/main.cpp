/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/20 00:06:50 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "scop.hpp"

//  https://antongerdelan.net/opengl/hellotriangle.html

//  shader GLSL: https://thebookofshaders.cppom/06/


// #include <GL/glew.h>
// https://open.gl/drawing
// https://open.gl/content/code/c2_triangle_elements.txt

// http://xed.ch/help/opengl.html

// int		main(void)
// {
// 	t_scop *scop;

// 	scop = new t_scop();
// 	if (!(scop))
// 		error_processing(MALLOC_ERROR, 0);
// 	init_gl(&scop->opengl);
// 	create_shape(scop);
// 	create_shaders(scop);
		
// 	glEnableVertexAttribArray(0);
// 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	
// 	sc_gl_loop(scop);
// 	// delete_shaders();
// 	return (0);
// }

	// GLint posAttrib = glGetAttribLocation(scop->opengl.shader_programme, "position");
	// glEnableVertexAttribArray(posAttrib);
	// glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
	// printf("glEnableVertexAttribArray\n");

	// GLint colAttrib = glGetAttribLocation(scop->opengl.shader_programme, "color");
	// glEnableVertexAttribArray(colAttrib);
	// glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
	// printf("glVertexAttribPointer\n");
	// printf("ccc\n");

#include "GLContext.hpp"
#include "Shape.hpp"
#include "GLObject.hpp"
#include "Shaders.hpp"

int main(void) {
	ErrorsProcess 	err;
	GLContext		openglContext(err);
	Shape			rectangle;
	GLObject		obj;
	Shaders			shaders;

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

	obj.initVertexArrayObject();
	obj.initVertexBufferObject(rectangle.arrayVertex);
	obj.initElementsBufferObject();
	shaders.createVertexShader(vertex_shader, err);
	shaders.createFragmentShader(fragment_shader, err);
	shaders.createProgram();
	openglContext.glLoop();
	obj.~GLObject();
	shaders.~Shaders();
	return (0);
}
