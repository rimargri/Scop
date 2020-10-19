/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaders.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:51:06 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/19 23:31:01 by f0rsunka         ###   ########.fr       */
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

#include "Errors.hpp"

class Shaders {
	public:
		GLuint		vertShader;
		GLuint		fragmShader;
		GLuint		shaderProgramme;
	Shaders();
	~Shaders();
		void		createVertexShader(const char *);
		void		createFragmentShader(const char *);
		void		createProgram(void);
	// private:
};
