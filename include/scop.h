/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:33:37 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/05 19:12:13 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE_CC__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <GLFW/glfw3.h>


#include <stdlib.h>
#include <stdio.h> //!---------------------------------------------------

#include "structures.h"
#include "prototypes.h"

#define COUNT_VERTEX 9



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