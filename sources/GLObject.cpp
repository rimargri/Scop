/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLObject.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:52:05 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/21 18:59:38 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GLObject.hpp"

void	GLObject::initVertexArrayObject(void)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

void	GLObject::initVertexBufferObject(Shape sh)
{
	glGenBuffers(1, &vboPoints);
	glBindBuffer(GL_ARRAY_BUFFER, vboPoints);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sh.arrayVertex), &sh.arrayVertex, GL_STATIC_DRAW);
	glGenBuffers(1, &vboColors);
	glBindBuffer(GL_ARRAY_BUFFER, vboColors);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sh.arrayColors), &sh.arrayColors, GL_STATIC_DRAW);
}

void	GLObject::initElementsBufferObject(void) {
	glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), &elements, GL_STATIC_DRAW);

}

GLObject::GLObject() {
	elements[0] = 0;
	elements[1] = 1;
	elements[2] = 2;
	elements[3] = 2;
	elements[4] = 1;
	elements[5] = 3;
}

GLObject::~GLObject() {
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vboPoints);
	glDeleteVertexArrays(1, &vao);
}
