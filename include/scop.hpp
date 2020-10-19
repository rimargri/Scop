/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:33:37 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/19 19:42:16 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE_CC__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else

#define GL_GLEXT_PROTOTYPES
#define GLEW_STATIC
#include <GL/glew.h>

#endif

#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cstdio> //!---------------------------------------------------
#include <array>

#include "structures.hpp"
#include "prototypes.hpp"

/*
** *********************************** **
** *********************************** **
**            	classes		           **
** *********************************** **
** *********************************** **
*/

// class Shape
// {
// 	private:
// 		std::array<float, COUNT_VERTEX> array_vertex;
// 		void get_vertex_shape(std::array<float, COUNT_VERTEX> array_vertex);
// 	Shape();
// };

// class OpenGL
// {
// 	private:
// 		GLFWwindow	*window;
// 		GLuint		vao;
// 		GLuint		vbo;
// 		GLuint		ebo;
// 		GLuint		vert_shader;
// 		GLuint		fragm_shader;
// 		GLuint		shader_programme;
// 		void		gl_property();
// 		void		init_gl(GLFWwindow	*window);
// 		void		init_vertex_array_object(t_opengl *gl);
// 		void		init_vertex_buffer_object(t_opengl *gl, std::array<float, COUNT_VERTEX> array_vertex);
// 		void		sc_gl_loop(t_scop *scop);
// 	OpenGL();
// };

// class Error_proceccing
// {
// 	enum Errors
// 	{
// 		MALLOC_ERROR,
// 		INIT_GL_ERROR,
// 		FAIL_GLFW,
// 		FAIL_WIN_GLFW,
// 		FAIL_GLEW,
// 		ERROR_VERT_SHADER_INDEX,
// 		ERROR_FRAGM_SHADER_INDEX
// 	};
// 	void	error_processing(int code, void *param);
// 	// Error_proceccing();
// };




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
#define FAIL_GLEW 7

