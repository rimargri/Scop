/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:29:52 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/05 19:13:00 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.hpp"

void	error_processing(int code, void *param)
{
	if (code == MALLOC_ERROR)
		printf("MALLOC was destroyed\n");
	if (code == INIT_GL_ERROR)
		printf("init gl error\n");
	if (code == FAIL_GLFW)
		printf("failed to inicialize glfw!\n");
	if (code == FAIL_WIN_GLFW)
		printf("Failed to open GLFW opengl window.\n");
	if (code == ERROR_VERT_SHADER_INDEX)
		printf("ERROR: vertex shader index %u did not compile\n", *(GLuint*)(param));
	if (code == ERROR_FRAGM_SHADER_INDEX)
		printf("ERROR: fragment shader index %u did not compile\n", *(GLuint*)(param));
	if (code == LINK_ERROR)
		printf("ERROR: could not link shader program GL index %u\n", *(GLuint*)(param));
	if (code == FAIL_GLEW)
		printf("GLEW error\n");
	exit (0);
}

