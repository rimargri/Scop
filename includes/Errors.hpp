/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:08:30 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/20 12:35:31 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HPP
# define ERRORS_HPP

#include <iostream>
#include <GLFW/glfw3.h>

class ErrorsProcess
{
	public:
		enum Errors
		{
			MALLOC_ERROR,
			INIT_GL_ERROR,
			FAIL_GLFW,
			FAIL_WIN_GLFW,
			FAIL_GLEW,
			FAIL_CREATE_VERT_SHADER,
			FAIL_CREATE_FRAGM_SHADER,
			ERROR_VERT_SHADER_INDEX,
			ERROR_FRAGM_SHADER_INDEX,
			FAIL_CREATE_SHADER_PROGRAMME,
			LINK_ERROR
		};
		void	printErrAndExit(int code, void *param);
};

#endif