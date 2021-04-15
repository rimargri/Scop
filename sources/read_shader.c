/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:03:25 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/15 17:11:51 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#define MAX_SHADER 500

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
		exit(88); // ERROR: NOT A FILE
	if ((returned_bytes = read(fd, &buf, MAX_SHADER)) >= MAX_SHADER - 1)
		exit(88); // ERROR: TOO BIG
	close(fd);
	buf[returned_bytes] = '\0';
	if (!(shader = malloc(sizeof(char) * (returned_bytes))))
		exit(88); // ERROR: MALLOC
	while (i < returned_bytes) {
		if (buf[i] == '\0' && i != returned_bytes)
			buf[i] = '\n';
		shader[i] = buf[i];
		i++;
	}
	shader[i] = '\0';
	return (shader);
}
