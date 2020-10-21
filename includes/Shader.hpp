/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:51:06 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/20 11:26:32 by f0rsunka         ###   ########.fr       */
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
#include <fstream>
#include <sstream>

#include "Errors.hpp"

class Shader {
	public:
		// void		createVertexShader(ErrorsProcess err);
		// void		createFragmentShader(ErrorsProcess err);
		void		createShaders(ErrorsProcess err, const char *vertShadFile, const char *fragmShadFile);
		void		compileShaders(ErrorsProcess err);
		void		createProgram(ErrorsProcess err);
		Shader();
		~Shader();
	private:
		GLuint		vertShader;
		GLuint		fragmShader;
		GLuint		shaderProgramme;
		const char* vertexShaderStr;
		const char* fragmentShaderStr;
		std::string	readShader(const char* filePath);
};
