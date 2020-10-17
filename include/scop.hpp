/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:33:37 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/17 22:50:08 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE_CC__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
// #include <GL/glut.h>

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GL/glext.h>
#endif

#include <GLFW/glfw3.h>

#include <cstdlib>
#include <cstdio> //!---------------------------------------------------

#include "structures.hpp"
#include "prototypes.hpp"

#define COUNT_VERTEX 12



/*
** *********************************** **
** *********************************** **
**            	errors		           **
** *********************************** **
** *********************************** **
*/


#define MALLOC_ERROR 0
#define INIT_GL_ERROR 1
#define FAIL_GLFW 2
#define FAIL_WIN_GLFW 3
#define ERROR_VERT_SHADER_INDEX 4
#define ERROR_FRAGM_SHADER_INDEX 5
#define LINK_ERROR 6

