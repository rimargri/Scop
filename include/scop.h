/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:33:37 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/16 21:53:06 by f0rsunka         ###   ########.fr       */
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

#include <stdlib.h>
#include <stdio.h> //!---------------------------------------------------

#include "structures.h"
#include "prototypes.h"

#define COUNT_VERTEX 36



/*
** *********************************** **
** *********************************** **
**            	errors		           **
** *********************************** **
** *********************************** **
*/


#define MLX_ERROR 0
#define INIT_GL_ERROR 1
#define FAIL_GLFW 2
#define FAIL_WIN_GLFW 3
#define ERROR_VERT_SHADER_INDEX 4
#define ERROR_FRAGM_SHADER_INDEX 5
#define LINK_ERROR 6

