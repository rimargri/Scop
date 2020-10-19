/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:08:30 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/20 00:05:36 by f0rsunka         ###   ########.fr       */
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
			ERROR_VERT_SHADER_INDEX,
			ERROR_FRAGM_SHADER_INDEX,
			LINK_ERROR
		};
		void	printErrAndExit(int code, void *param);
};

#endif