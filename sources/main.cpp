/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:18:16 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/21 17:52:02 by f0rsunka         ###   ########.fr       */
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
	Shader			shader;

	obj.initVertexArrayObject();
	obj.initVertexBufferObject(rectangle.arrayVertex);
	obj.initElementsBufferObject();
	shader.createShaders(err, "shaders/vertShader.vert", "shaders/fragShader.frag");
	shader.compileShaders(err);
	shader.createProgram(err);
	openglContext.glLoop(shader.shaderProgramme, obj.vao);
	obj.~GLObject();
	shader.~Shader();
	return (0);
}
