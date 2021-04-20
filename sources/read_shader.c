/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:03:25 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/20 18:37:10 by cvernius         ###   ########.fr       */
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
		log_scop("Read shader::This is not a file\0", (enum errors)not_a_file);
	if ((returned_bytes = read(fd, &buf, MAX_SHADER)) >= MAX_SHADER - 1)
		log_scop("Read shader::This file is a giant\0", (enum errors)giant_file);
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
