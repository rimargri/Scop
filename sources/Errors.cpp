/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:08:09 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/20 12:36:05 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Errors.hpp"

void	ErrorsProcess::printErrAndExit(int code, void *param) {
	if (code == MALLOC_ERROR)
		std::cout << "MALLOC was destroyed\n" << std::endl;
	if (code == INIT_GL_ERROR)
		std::cout << "init gl error\n" << std::endl;
	if (code == FAIL_GLEW)
		std::cout << "GLEW error\n" << std::endl;
	if (code == FAIL_GLFW)
		std::cout << "failed to inicialize glfw!\n" << std::endl;
	if (code == FAIL_WIN_GLFW)
		std::cout << "Failed to open GLFW opengl window.\n" << std::endl;
	if (code == FAIL_CREATE_VERT_SHADER)
		std::cout << "FAIL_CREATE_VERT_SHADER\n" << std::endl;
	if (code == FAIL_CREATE_FRAGM_SHADER)
		std::cout << "FAIL_CREATE_FRAGM_SHADER\n" << std::endl;
	if (code == ERROR_VERT_SHADER_INDEX)
		std::cout << "ERROR: vertex shader index " << *(GLuint*)(param) << " did not compile\n" << std::endl;
	if (code == ERROR_FRAGM_SHADER_INDEX)
		std::cout << "ERROR: fragment shader index " << *(GLuint*)(param) << " did not compile\n" << std::endl;
	if (code == FAIL_CREATE_SHADER_PROGRAMME)
		std::cout << "FAIL_CREATE_SHADER_PROGRAMME\n" << std::endl;
	if (code == LINK_ERROR)
		std::cout << "ERROR: could not link shader program GL index " << *(GLuint*)(param) << "\n" << std::endl;
	exit (0);
}
