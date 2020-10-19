/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GlObject.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:52:05 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/19 23:39:28 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GLObject.hpp"

void	GLObject::initVertexArrayObject(void)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

void	GLObject::initVertexBufferObject(std::array<float, COUNT_VERTEX> array_vertex)
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(array_vertex), &array_vertex, GL_STATIC_DRAW);
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
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}
