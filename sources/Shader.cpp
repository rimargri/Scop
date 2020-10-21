/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:01:36 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/21 12:33:51 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shader.hpp"

std::string Shader::readShader(const char* filePath) {
	std::string shaderCode;
	std::ifstream shaderFileRead;
	std::stringstream shaderStream;

	shaderFileRead.exceptions(std::ifstream::badbit);
	try {
		shaderFileRead.open(filePath);
		shaderStream << shaderFileRead.rdbuf();
		shaderFileRead.close();
		shaderCode = shaderStream.str();
	}
	catch(std::ifstream::failure e) {
		std::cout << "Error: Reading shaders from file.\n" << std::endl;
		// exit(0);
	}
	return (shaderCode);
}

// std::string Shader::readShader(const char* filePath) {
// 	std::string content;
// 	std::ifstream fileStream(filePath, std::ios::in);
// 	std::string line;

// 	line = "";
// 	if (!fileStream.is_open()) {
//         std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
//         return "";
// 	}
// 	while (!fileStream.eof()) {
// 		std::getline(fileStream, line);
// 		content.append(line + "\n");
// 	}
// 	fileStream.close();
// 	return (content);
// }

void		Shader::createShaders(ErrorsProcess err, const char *vertShadFile, const char *fragmShadFile) {
	
	std::string tmp;
	std::string tmp2;
	// int success;
	
	// success = -1;
	vertShader = glCreateShader(GL_VERTEX_SHADER);
	((vertShader == 0) ? (err.printErrAndExit(err.Errors::FAIL_CREATE_VERT_SHADER, 0)) : void());
	tmp = readShader(vertShadFile);
	vertexShaderStr = tmp.c_str();
	glShaderSource(vertShader, 1, &vertexShaderStr, NULL);

	fragmShader = glCreateShader(GL_FRAGMENT_SHADER);
	((fragmShader == 0) ? (err.printErrAndExit(err.Errors::FAIL_CREATE_FRAGM_SHADER, 0)) : void());
	tmp2 = readShader(fragmShadFile);
	fragmentShaderStr = tmp2.c_str();
	glShaderSource(fragmShader, 1, &fragmentShaderStr, NULL);
}

void		Shader::compileShaders(ErrorsProcess err) {
	int success;
	
	success = -1;
	glCompileShader(vertShader);
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
	if (GL_TRUE != success) {
		// glDeleteShader(vertShader);
		err.printErrAndExit(err.Errors::ERROR_VERT_SHADER_INDEX, &vertShader);
	}

	glCompileShader(fragmShader);
	glGetShaderiv(fragmShader, GL_COMPILE_STATUS, &success);
	if (GL_TRUE != success) {
		// glDeleteShader(fragmShader);
		glDeleteShader(vertShader);
		err.printErrAndExit(err.Errors::ERROR_FRAGM_SHADER_INDEX, &fragmShader);
	}
}

void		Shader::createProgram(ErrorsProcess err) {
	int success;

	success = -1;
	shaderProgramme = glCreateProgram();
	((shaderProgramme == 0) ? (err.printErrAndExit(err.Errors::FAIL_CREATE_SHADER_PROGRAMME, 0)) : void());
	glAttachShader(shaderProgramme, vertShader);
	glAttachShader(shaderProgramme, fragmShader);
    // glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgramme);
	glGetShaderiv(shaderProgramme, GL_LINK_STATUS, &success);
	if (success == GL_FALSE) {
		// glDeleteProgram(shaderProgramme);
		glDeleteShader(fragmShader);
		glDeleteShader(vertShader);
		err.printErrAndExit(err.Errors::LINK_ERROR, &shaderProgramme);
	}

	glUseProgram(shaderProgramme);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glDeleteShader(vertShader);
	glDeleteShader(fragmShader);
}

Shader::Shader() {
}

Shader::~Shader() {
	glDeleteProgram(shaderProgramme);
	glDeleteShader(vertShader);
	glDeleteShader(fragmShader);
}
