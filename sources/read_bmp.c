/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:25:17 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/18 20:19:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_loader.h"
#include <stdio.h>
#include <stdlib.h>

// unsigned char* ReadBMP(char* filename)
void read_bmp(char* filename, t_bmp *bmp)
{
	FILE *f;
	int i;
	// unsigned char info[54];
	int row_padded;
	unsigned char tmp;

	f = fopen(filename, "rb");
	if (f == NULL)
		exit(88); // ERROR: FILE
	fread(bmp->info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	bmp->width = *(int*)&bmp->info[18];
	bmp->height = *(int*)&bmp->info[22];
	row_padded = (bmp->width * 3 + 3) & (~3);
	bmp->size = sizeof(unsigned char) * row_padded;
	bmp->data = malloc(bmp->size);
	if (!(bmp->data))
		exit(88); // ERROR: MALLOC
	for (int i = 0; i < bmp->height; i++)
	{
		fread(bmp->data, sizeof(unsigned char), row_padded, f);
		for (int j = 0; j < bmp->width * 3; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = bmp->data[j];
			bmp->data[j] = bmp->data[j + 2];
			bmp->data[j + 2] = tmp;

			// printf("R: %d ", (int)bmp->data[j]);
			// printf("G: %d ", (int)bmp->data[j + 1]);
			// printf("B: %d\n", (int)bmp->data[j + 2]);
		}
	}
	fclose(f);
}

// int main() {
// 	ReadBMP("textures/test.bmp");	
// }

// https://stackoverflow.com/questions/9296059/read-pixel-value-in-bmp-file