/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:33:37 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/07/07 13:08:20 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
#define SCOP_H

#ifdef __APPLE_CC__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>

#include <X11/Xlib.h>
#include <GL/glx.h>
#endif

#include <GLFW/glfw3.h>
#include <math.h>

# define DEG2RAD (M_PI / 180.f)
# define RAD2DEG (1.0f / DEG2RAD)

#include <stdlib.h>
#include <stdio.h> //!---------------------------------------------------

#include "structures.h"
#include "prototypes.h"


// #define COUNT_VERTEX 3

#define COUNT_VERTEX 36


#define UP_AXIS (t_vec3){0.0f, 0.1f, 0.0f}

#define WIN_W (700)
#define WIN_H (500)

#define FOV (60)
#define ASPECT ((float)WIN_W / (float)WIN_H)



#define COUNT_INDEXES 6

#endif
