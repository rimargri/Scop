/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:03:25 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/14 17:25:32 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stddef.h>

# include "../libft/libft.h"

void	read_shaders(t_shader *shader)
{
	int		fd;
	int		returned_bytes;
	char	buf[MAX_SHADER];
	char	buf1[MAX_SHADER];
	int i = 0;

	fd = open("shaders/vertex_shader.vert", O_RDONLY);	
	if (fd < 3)
		exit(88); // ERROR: NOT A FILE
	if ((returned_bytes = read(fd, buf, MAX_SHADER)) >= MAX_SHADER - 1)
		exit(88); // ERROR: TOO BIG
	buf[returned_bytes] = '\0';
	if (!(shader->vertex_shader = malloc(sizeof(char) * (returned_bytes))))
		exit(88); // ERROR: MALLOC
	while (i < returned_bytes) {
		if (buf[i] == '\0' && i != returned_bytes)
			buf[i] = '\n';
		shader->vertex_shader[i] = buf[i];
		i++;
	}
	shader->vertex_shader[i] = '\0';
	close(fd);

	returned_bytes = 0;
	fd = 0;

	fd = open("shaders/fragment_shader.frag", O_RDONLY);
	if (fd < 3)
		exit(88); // ERROR: NOT A FILE
	if ((returned_bytes = read(fd, buf1, MAX_SHADER)) >= MAX_SHADER - 1)
		exit(88); // ERROR: TOO BIG
	buf1[returned_bytes] = '\0';
	if (!(shader->fragment_shader = malloc(sizeof(char) * (returned_bytes))))
		exit(88); // ERROR: MALLOC
	i = 0;
	while (i < returned_bytes) {
		if (buf1[i] == '\0' && i != returned_bytes)
			buf1[i] = '\n';
		shader->fragment_shader[i] = buf1[i];
		i++;
	}
	shader->fragment_shader[i] = '\0';
	close(fd);
}
