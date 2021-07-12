/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:42:15 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/12 19:53:05 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "bmp_load.h"

void create_cubemap(t_scop *scop)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	
	read_texture();
}
