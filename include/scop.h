/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:33:37 by f0rsunka          #+#    #+#             */
/*   Updated: 2021/04/06 19:40:18 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE_CC__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <GLFW/glfw3.h>

# define DEG2RAD (M_PI / 180.f)

#include <stdlib.h>
#include <stdio.h> //!---------------------------------------------------

#include "structures.h"
#include "prototypes.h"

#define COUNT_VERTEX 9
// #define COUNT_VERTEX 3

#define UP_AXIS (t_vec3){0.0f, 0.1f, 0.0f}