/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:25:17 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/19 20:26:53 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_loader.h"
#include <stdio.h>
#include <stdlib.h>

void read_bmp(char* filename, t_bmp *bmp)
{
	FILE *bmp_image;
	int i;
	int row_padded;
	unsigned char tmp;

	bmp_image = fopen(filename, "rb");
	if (bmp_image == NULL)
		exit(88); // ERROR: FILE
	fread(bmp->info, sizeof(unsigned char), 54, bmp_image);
	bmp->width = *(int*)&bmp->info[18];
	bmp->height = *(int*)&bmp->info[22];
    int size = 3 * bmp->width * bmp->height;
    bmp->data = malloc(sizeof(unsigned char) * size);
	if (!(bmp->data))
		exit(88); // ERROR: MALLOC
	fread(bmp->data, sizeof(unsigned char), size, bmp_image); 
	for (i = 0; i < size; i += 3)
	{
		tmp = bmp->data[i];
		bmp->data[i] = bmp->data[i + 2];
		bmp->data[i + 2] = tmp;
	}


	// row_padded = (bmp->width * 3 + 3) & (~3);
	// bmp->data = malloc(sizeof(unsigned char) * row_padded);


	// int ind = 0;
	// for(int i = 0; i < bmp->height; i++)
	// {
	// 	fread(bmp->data, sizeof(unsigned char), row_padded, bmp_image);
	// 	for(int j = 0; j < bmp->width*3; j += 3)
	// 	{
	// 		// Convert (B, G, R) to (R, G, B)
	// 		tmp = bmp->data[ind];
	// 		bmp->data[ind] = bmp->data[ind+2];
	// 		bmp->data[ind+2] = tmp;
	// 		ind++;
	// 	}
	// }




	// row_padded = (bmp->width * 3 + 3) & (~3);
	// printf("(bmp->width * 3 + 3) & (~3) == %d\n", ((bmp->width * 3 + 3) & (~3)));
	// // row_padded = (4 - ((3 * bmp->width) % 4)) % 4;
	// printf("(4 - ((3 * bmp->width) % 4)) % 4 == %d\n", ((4 - ((3 * bmp->width) % 4)) % 4));
	// bmp->size = sizeof(unsigned char) * row_padded;
	// bmp->data = malloc(bmp->size);
	// printf("row_padded = %d bmp->size = %d\n", row_padded, bmp->size);
	// if (!(bmp->data))
	// 	exit(88); // ERROR: MALLOC
	// for (int i = 0; i < bmp->height; i++)
	// {
	// 	fread(bmp->data, sizeof(unsigned char), row_padded, bmp_image);
	// 	for (int j = 0; j < bmp->width * 3; j += 3)
	// 	{
	// 		// Convert (B, G, R) to (R, G, B)
	// 		tmp = bmp->data[j];
	// 		bmp->data[j] = bmp->data[j + 2];
	// 		bmp->data[j + 2] = tmp;

	// 		// printf("R: %d ", (int)bmp->data[j]);
	// 		// printf("G: %d ", (int)bmp->data[j + 1]);
	// 		// printf("B: %d\n", (int)bmp->data[j + 2]);
	// 	}
	// }


	// int padding = bmp->width % 4;
	// int padding = ((bmp->width * 3 + 3) & (~3)) * bmp->height;
	// int num_of_pixels = bmp->width * bmp->height;
    // bmp->data = malloc(sizeof(unsigned char) * num_of_pixels);
	// if (!(bmp->data))
	// 	exit(88); //  ERROR: MALLOC
	// fseek(bmp_image, 54, SEEK_SET); //move 54B (header size)
	// int image_pix = 0;
	// for (int i = 0; i < bmp->height; i++)
	// {
	// 	printf("i = %d\n", i);
	// 	for (int j = 0; j < bmp->width; j++)
	// 	{
	// 		printf("j = %d\n", j);
	// // 		tmp = bmp->data[j];
	// // 		bmp->data[j] = bmp->data[j + 2];
	// // 		bmp->data[j + 2] = tmp;
	// 		fread(&(bmp->data[image_pix + 2]), 1, 1, bmp_image); //b
	// 		fread(&(bmp->data[image_pix + 1]), 1, 1, bmp_image); //g
	// 		fread(&(bmp->data[image_pix]), 1, 1, bmp_image); //r
	// 		image_pix += 3;
	// 	}
	// 	fseek(bmp_image, padding, SEEK_CUR);  //padding at the end of row
	// }

	fclose(bmp_image);
}

// https://stackoverflow.com/questions/9296059/read-pixel-value-in-bmp-file