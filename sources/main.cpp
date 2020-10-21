/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/21 15:45:00 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "scop.hpp"

//  https://antongerdelan.net/opengl/hellotriangle.html

//  shader GLSL: https://thebookofshader.cppom/06/


// #include <GL/glew.h>
// https://open.gl/drawing
// https://open.gl/content/code/c2_triangle_elements.txt

// http://xed.ch/help/opengl.html


// https://badvertex.com/2012/11/20/how-to-load-a-glsl-shader-in-opengl-using-c.html
// https://habr.com/ru/post/313380/
// https://startandroid.ru/ru/uroki/vse-uroki-spiskom/398-urok-169-opengl-shejdery.html


#include "GLContext.hpp"
#include "Shape.hpp"
#include "GLObject.hpp"
#include "Shader.hpp"

int main(void) {
	ErrorsProcess 	err;
	GLContext		openglContext(err);
	Shape			rectangle;
	GLObject		obj;
	// Shader			shader("../shaders/vertShader.vert", "../shaders/fragmShader.frag");
	Shader			shader;

	// const char* vertex_shader =
	// "#version 400\n"
	// "in vec3 vp;"
	// "void main() {"
	// "  gl_Position = vec4(vp, 1.0);"
	// "}";

	// const char* fragment_shader =
	// "#version 400\n"
	// "out vec4 frag_colour;"
	// "void main() {"
	// "  frag_colour = vec4(0.5, 0.4, 0.5, 1.0);"
	// "}";

	obj.initVertexArrayObject();
	obj.initVertexBufferObject(rectangle.arrayVertex);
	obj.initElementsBufferObject();
	shader.createShaders(err, "shaders/vertShader.vert", "shaders/fragShader.frag");
	shader.compileShaders(err);
	// shader.createVertexShader(err);
	// shader.createFragmentShader(err);
	shader.createProgram(err);
	openglContext.glLoop();
	obj.~GLObject();
	shader.~Shader();
	return (0);
}
