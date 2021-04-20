/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:25:17 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/20 17:33:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_loader.h"

 /**
  * BMP IMAGE STRUCTURE
  * 
  * DECIMAL			DEFINITION
  * 
  * 0				'B'
  * 1'M'			'M' ("BM" == BitMap)
  * ..
  * 10				Offset to start of Pixel Data
  * ..
  * 18				Width
  * ..
  * 22				Height
  * ..
  * 28				Color depth (8, 16, 24, 32, etc)
  * ..
  * 34				Image size == width * height * 3 (3 bytes for each pixel (because of RGB))
  * 
 **/

void read_bmp(char* filename, t_bmp *bmp)
{
	FILE *bmp_image;
	int i;
	unsigned char tmp;

	bmp_image = fopen(filename, "rb");
	if (bmp_image == NULL)
		exit(88); // ERROR: FILE
	fread(bmp->info, sizeof(unsigned char), SIZE_BMP_HEADER, bmp_image);
	if (bmp->info[0] != 'B' || bmp->info[1] != 'M')
		exit(88); //ERROR: THIS IS NOT A BitMap File
	if (bmp->info[28] != COLOR_DEPTH)
		exit(88); // ERROR: COLOR DEPTH != 24 (Only 24 is required)
	bmp->offset_to_start_pixel_data = *(int*)&bmp->info[10];
	bmp->width = *(int*)&bmp->info[18];
	bmp->height = *(int*)&bmp->info[22];
	bmp->size = *(int*)&bmp->info[34];
	bmp->data = malloc(bmp->size + 1);
	if (!(bmp->data))
		exit(88); // ERROR: MALLOC
	fseek(bmp_image, bmp->offset_to_start_pixel_data, SEEK_SET);
	fread(bmp->data, sizeof(unsigned char), bmp->size, bmp_image); 
	for (i = 0; i < bmp->size; i += 3)
	{
		tmp = bmp->data[i];
		bmp->data[i] = bmp->data[i + 2];
		bmp->data[i + 2] = tmp;
	}
	fclose(bmp_image);
}
