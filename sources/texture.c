/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:51:05 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/18 20:46:47 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "bmp_loader.h"

void	read_texture(t_texture *texture)
{
	t_bmp bmp;

	read_bmp("textures/wall.bmp", &bmp);
	texture->data = malloc(bmp.size);
	if (!(texture->data))
		exit(88); // ERROR: MALLOC
	texture->width = bmp.width;
	texture->height = bmp.height;
	texture->data = bmp.data;
	printf("%p\n", texture->data);
}

void	load_texture(t_scop *scop)
{
	glGenTextures(1, &scop->texture.id);
	glBindTexture(GL_TEXTURE_2D, scop->texture.id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	read_texture(&scop->texture);
	printf("%p\n", scop->texture.data);
	if (scop->texture.data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, scop->texture.width, scop->texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->texture.data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		exit(88); // ERROR: fail to load texture
	free(scop->texture.data);

	// glBindTexture(GL_TEXTURE_2D, scop->texture.data);
	// glBindVertexArray(scop->gl->vao);

	// float texture_coords[6] = {0.0f, 0.0f, 
	// 							1.0f, 0.0f,
	// 							0.5f, 1.0f};

	// // float borderColor[] = {1.0f, 10.0f, 0.0f, 1.0f};
	// // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

}




