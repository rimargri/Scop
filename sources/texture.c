/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:51:05 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/22 20:33:21 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "bmp_load.h"
#include "log_scop.h"

void	read_texture(t_texture *texture)
{
	t_bmp bmp;

	read_bmp("textures/marble.bmp", &bmp);
	texture->data = malloc(bmp.size);
	if (!(texture->data))
		log_scop("Texture::Malloc can't allocate memory\n", (enum errors)malloc_error);
	texture->width = bmp.width;
	texture->height = bmp.height;
	texture->data = bmp.data;
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
	if (scop->texture.data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, scop->texture.width, scop->texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->texture.data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		log_scop("Texture::Empty data in bmp file\n", empty_data_tex);
	free(scop->texture.data);
}

void	new_load_texture(t_scop *scop)
{
	int i = 0;

	glGenTextures(1, &scop->texture.id);
	glBindTexture(GL_TEXTURE_2D, scop->texture.id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	scop->array_textures = malloc(sizeof(t_texture) * COUNT_TEXTURES);
	if (!(scop->array_textures))
		exit(88);
	while (i < COUNT_TEXTURES)
	{
		read_texture(scop->array_textures[i]);
		i++;
	}
	if (scop->array_textures[0].data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, scop->array_textures[0].width, scop->array_textures[0].height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->array_textures[0].data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		log_scop("Texture::Empty data in bmp file\n", empty_data_tex);
	// free(scop->array_textures[0].data);
}

void	change_texture(t_scop *s, int n)
{
	int current_num = n % COUNT_TEXTURES;
	if (scop->array_textures[current_num].data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, scop->array_textures[current_num].width, scop->array_textures[current_num].height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->array_textures[current_num].data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		log_scop("Texture::Empty data in bmp file\n", empty_data_tex);
	// free(scop->array_textures[current_num].data);
}
