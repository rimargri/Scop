/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:42:15 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/13 19:05:41 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "bmp_load.h"



void create_cubemap(t_scop *scop)
{
	glGenTextures(1, &scop->skybox.texture_id);
	glBindTexture(GL_TEXTURE_CUBE_MAP, scop->skybox.texture_id);
	
	read_texture(&scop->skybox.textures[0], "textures/skybox/front.bmp");
	read_texture(&scop->skybox.textures[1], "textures/skybox/back.bmp");
	read_texture(&scop->skybox.textures[2], "textures/skybox/top.bmp");
	read_texture(&scop->skybox.textures[3], "textures/skybox/bottom.bmp");
	read_texture(&scop->skybox.textures[4], "textures/skybox/left.bmp");
	read_texture(&scop->skybox.textures[5], "textures/skybox/right.bmp");

	
	if (scop->skybox.textures[0].data)
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 
			0, GL_RGB, scop->skybox.textures[0].width, scop->skybox.textures[0].height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->skybox.textures[0].data);
	if (scop->skybox.textures[1].data)
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 
			0, GL_RGB, scop->skybox.textures[1].width, scop->skybox.textures[1].height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->skybox.textures[1].data);
	if (scop->skybox.textures[2].data)
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 
			0, GL_RGB, scop->skybox.textures[2].width, scop->skybox.textures[2].height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->skybox.textures[2].data);
	if (scop->skybox.textures[3].data)
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 
			0, GL_RGB, scop->skybox.textures[3].width, scop->skybox.textures[3].height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->skybox.textures[3].data);
	if (scop->skybox.textures[4].data)
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 
			0, GL_RGB, scop->skybox.textures[4].width, scop->skybox.textures[4].height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->skybox.textures[4].data);
	if (scop->skybox.textures[5].data)
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X, 
			0, GL_RGB, scop->skybox.textures[5].width, scop->skybox.textures[5].height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->skybox.textures[5].data);

	free(scop->skybox.textures[0].data);
	free(scop->skybox.textures[1].data);
	free(scop->skybox.textures[2].data);
	free(scop->skybox.textures[3].data);
	free(scop->skybox.textures[4].data);
	free(scop->skybox.textures[5].data);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}
