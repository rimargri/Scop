/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaders.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:01:36 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/19 23:29:33 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shaders.hpp"

void		Shaders::createVertexShader(const char * vertShaderString) {
	int lparams;

	lparams = -1;
	vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, &vertShaderString, NULL);
	glCompileShader(vertShader);
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &lparams);
	// if (GL_TRUE != lparams)
	// 	ErrorsProcess::printErrAndExit(ErrorsProcess::Errors::ERROR_VERT_SHADER_INDEX, &vertShader);
}

void		Shaders::createFragmentShader(const char * fragmShaderString) {
	int lparams;

	lparams = -1;
	fragmShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmShader, 1, &fragmShaderString, NULL);
	glCompileShader(fragmShader);
	glGetShaderiv(fragmShader, GL_COMPILE_STATUS, &lparams);
	// if (GL_TRUE != lparams)
	// 	error_processing(ERROR_FRAGM_SHADER_INDEX, &fragmShader);
}

void		Shaders::createProgram(void) {
	int lparams;

	lparams = -1;
	shaderProgramme = glCreateProgram();
	glAttachShader(shaderProgramme, vertShader);
	glAttachShader(shaderProgramme, fragmShader);
    // glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgramme);
	// glDeleteShader(vertShader);
	// glDeleteShader(fragmShader);
	glGetShaderiv(shaderProgramme, GL_LINK_STATUS, &lparams);
	glUseProgram(shaderProgramme);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	
	// printf("%u %d\n", GL_TRUE, lparams);
	// if (GL_TRUE != lparams)
		// error_processing(LINK_ERROR, &shaderProgramme);
}

Shaders::Shaders() {
	
}

Shaders::~Shaders() {
	glDeleteProgram(shaderProgramme);
	glDeleteShader(vertShader);
	glDeleteShader(fragmShader);
}
