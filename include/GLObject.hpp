/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLObject.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:45:38 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/19 23:46:01 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE_CC__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else

#define GL_GLEXT_PROTOTYPES
#define GLEW_STATIC
#include <GL/glew.h>

#endif

#include <GLFW/glfw3.h>
#include <array>
#define COUNT_VERTEX 12

class GLObject {
	public:
		void		initVertexArrayObject(void);
		void		initVertexBufferObject(std::array<float, COUNT_VERTEX> arrayVertex);
		void		initElementsBufferObject(void);
		GLObject();
		~GLObject();
	private:
		GLuint		vao;
		GLuint		vbo;
		GLuint		ebo;
		std::array<GLuint, 6> elements;
};
