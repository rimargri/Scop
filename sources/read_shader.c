/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:03:25 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/26 20:42:01 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_load.h"
#include "log_scop.h"

char	*read_shader(const char *filename, char *shader)
{
	int		fd;
	int		returned_bytes;
	char	buf[MAX_SHADER];
	int		i;

	i = 0;
	returned_bytes = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 3)
		log_scop("Read shader::This is not a file\n", (enum errors)not_a_file);
	if ((returned_bytes = read(fd, &buf, MAX_SHADER)) >= MAX_SHADER - 1)
		log_scop("Read shader::This file is a giant\n", (enum errors)giant_file);
	close(fd);
	buf[returned_bytes] = '\0';
	if (!(shader = malloc(sizeof(char) * (returned_bytes))))
		log_scop("Read shader::Malloc can't allocate memory\0", (enum errors)malloc_error);
	while (i < returned_bytes) {
		if (buf[i] == '\0' && i != returned_bytes)
			buf[i] = '\n';
		shader[i] = buf[i];
		i++;
	}
	shader[i] = '\0';
	return (shader);
}


















// void	init_vertex_array_object(t_opengl *gl, float *array_vertex)
// {
// 	glGenBuffers(1, &gl->vbo);
// 	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
// 	glBufferData(GL_ARRAY_BUFFER, COUNT_VERTEX * sizeof(float), array_vertex, GL_STATIC_DRAW);
// }

// void	init_vertex_buffer_object(t_opengl *gl)
// {
// 	glGenVertexArrays(1, &gl->vao);
// 	glBindVertexArray(gl->vao);
// 	glEnableVertexAttribArray(0);
// 	// glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
// 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
// }

// void	create_shape(t_scop *s)
// {
// 	t_shape  shape;

// 	sc_get_vertex_shape(&shape);		
// 	init_vertex_array_object(&s->opengl, shape.array_vertex);
// 	init_vertex_buffer_object(&s->opengl);
// 	// Create an element array

//     glGenBuffers(1, &s->opengl.ebo);

//     GLuint elements[] = {
//         0, 1, 2,
//         2, 1, 3
//     };

//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->opengl.ebo);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
// }































// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 	glUseProgram(scop->opengl.shader_programme);
// 	// glDrawArrays(GL_TRIANGLES, 0, 6);
// 	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
// 	glfwPollEvents();
// 	glfwSwapBuffers(scop->opengl.window);