/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:05:24 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/18 17:28:37 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "bmp_loader.h"
// #include <stdlib.h>

// void	read_bmp(char *filename, t_bmp *bmp)
// {
// 	FILE *file;
// 	int32 data_offset;
// 	int16 bits_per_pixel;
// 	int size_padded_row;
// 	int size_unpadded_row;
// 	int total_size;
// 	byte current_row_pointer;
// 	int i = 0;

// 	file = fopen(filename, "r");
// 	if (!(file))
// 		exit(88); // ERROR: !FILE

// 	fseek(file, DATA_OFFSET, SEEK_SET);
// 	fread(&data_offset, 4, 1, file);
// 	fseek(file, WIDTH_OFFSET, SEEK_SET);
// 	fread(&bmp->width, 4, 1, file);
// 	fseek(file, HEIGHT_OFFSET, SEEK_SET);
// 	fread(&bmp->height, 4, 1, file);
// 	fseek(file, BITS_PER_PIXEL_OFFSET, SEEK_SET);
// 	fread(&bits_per_pixel, 2, 1, file);
// 	bmp->bytes_per_pixel = ((int32)bits_per_pixel) / 8;
// 	printf("%d\n", bmp->bytes_per_pixel);

// 	size_padded_row = (int)(4 * ceil((float) bmp->width / 4.0f)) * (bmp->bytes_per_pixel);
// 	printf("%d\n", size_padded_row);
// 	size_unpadded_row = bmp->width * bmp->bytes_per_pixel;
// 	total_size = size_unpadded_row * bmp->height;
// 	bmp->pixels = malloc(sizeof(byte) * total_size);
// 	if (!(bmp->pixels))
// 		exit(88); // ERROR: MALLOC
// 	current_row_pointer = *bmp->pixels + ((bmp->height - 1) * size_unpadded_row);
// 	printf("%d\n", current_row_pointer);
// 	while (i < bmp->height)
// 	{
// 		fseek(file, data_offset + (i * size_padded_row), SEEK_SET);
// 		fread(&current_row_pointer, 1, size_unpadded_row, file);
// 		printf("%d\n", size_unpadded_row);
// 		current_row_pointer -= size_unpadded_row;
// 		i++;
// 	}
// 	fclose(file);
// }




// struct pixel* read_data(FILE* stream, const struct bmp_header* header)
// {
//   if (stream == NULL || header == NULL)
//   {
//     return 0;
//   }
//   // w == 1 && p == 1;   w == 2 && p == 2;   w == 3 && p == 3;   w == 4 && p == 0  
//   int padding = header->width % 4; 		// (4-((3*width)%4))%4
//   int num_of_pixels = header->width * header->height;
//   struct pixel* Pixel[num_of_pixels];

//   fseek(stream, 54, SEEK_SET); //move 54B (header size)
//   int index_p = 0;
//   for(int i = 0; i < header->height; i++){
//     for(int j = 0; j < header->width; j++){
//       Pixel[index_p] = malloc(sizeof(struct pixel));
//       fread(&(Pixel[index_p]->blue), 1, 1, stream); 
//       fread(&(Pixel[index_p]->green), 1, 1, stream); 
//       fread(&(Pixel[index_p]->red), 1, 1, stream); 
//       index_p++;
//     }
//     fseek(stream, padding, SEEK_CUR);  //padding at the end of row
//   }
//   return *Pixel;
// }

















// // https://stackoverflow.com/questions/61360044/reading-data-from-bmp-file-in-c




// void	read_bmp(char *filename, t_bmp *bmp)
// {
// 	FILE* stream;

// 	stream = fopen(filename, "rb");
// 	if (stream == NULL && header == NULL)
// 	{
		
// 	}
// }





// # ifndef BMP_H
// # define BMP_H
/*
 BMP format
 The data in this format is divided into three to four parts, in order:
 File information header (14 bytes) stores file type, file size and other information
 The picture information header (40 bytes) stores the picture size, color index, bit plane number and other information
 Palette (determined by the number of color indexes) [may not have this information]
 Bitmap data (determined by the image size) information for each pixel is stored here

 The general bmp image is 24 bits, which is true color. Every 8 bits is a byte, and 24 bits use three bytes to store the information of each pixel. The three bytes correspond to the data of the three primary colors of r, g, and b.
 The storage range of each byte is 0-255. Then by analogy, a 32-bit image stores four data of r, g, b, a (Alpha channel, storage transparency) per pixel. 8-bit image is only the grayscale information,
 There is also a binary image, which has only two colors, black or white.
*/
// File information header structure
typedef struct tagBITMAPFILEHEADER 
{
    //unsigned short bfType; // 19778, must be a BM string, the corresponding hexadecimal is 0x4d42, and the decimal is 19778, otherwise it is not a bmp format file
    unsigned int   bfSize;        // File size in bytes (2-5 bytes)
    unsigned short bfReserved1;   // Reserved, must be set to 0 (6-7 bytes)
    unsigned short bfReserved2;   // Reserved, must be set to 0 (8-9 bytes)
    unsigned int   bfOffBits;     // Offset from file header to pixel data (10-13 bytes)
} BITMAPFILEHEADER;

//Image information header structure
typedef struct tagBITMAPINFOHEADER 
{
    unsigned int    biSize;          // The size of this structure (14-17 bytes)
    long            biWidth;         // The width of the image (18-21 bytes)
    long            biHeight;        // The height of the image (22-25 bytes)
    unsigned short  biPlanes;        // Indicates the plane attribute of the bmp picture, obviously the display has only one plane, so it is always equal to 1 (26-27 bytes)
    unsigned short  biBitCount;      // The number of bits occupied by a pixel, generally 24 (28-29 bytes)
    unsigned int    biCompression;   // Describe the type of image data compression, 0 means no compression. (30-33 bytes)
    unsigned int    biSizeImage;     // The size of pixel data, this value should be equal to bfSize-bfOffBits (34-37 bytes) in the file header structure above
    long            biXPelsPerMeter; // Describe the horizontal resolution, expressed in pixels/meter. Generally 0 (38-41 bytes)
    long            biYPelsPerMeter; // Describe the vertical resolution, expressed in pixels/meter. Generally 0 (42-45 bytes)
    unsigned int    biClrUsed;       // Describe the number of color indexes in the color table actually used by the bitmap (if set to 0, all palette items are used). (46-49 bytes)
    unsigned int    biClrImportant;  // Explain the number of color indexes that have an important influence on the image display. If it is 0, it means all are important. (50-53 bytes)
} BITMAPINFOHEADER;

//24 bitmap pixel information structure, namely palette
typedef struct _PixelInfo {
    unsigned char rgbBlue;   //The blue component of the color (value range is 0-255)
    unsigned char rgbGreen;  //The green component of the color (value range is 0-255)
    unsigned char rgbRed;    //The red component of the color (value range is 0-255)
    unsigned char rgbReserved;// reserved, must be 0
} PixelInfo;

// #endif




#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>
// #include "BmpFormat.h"

BITMAPFILEHEADER fileHeader;
BITMAPINFOHEADER infoHeader;

void showBmpHead(BITMAPFILEHEADER pBmpHead) 
{  //Define the function of displaying information, pass in the file header structure
    printf("BMP file size: %dkb\n", fileHeader.bfSize/1024);
    printf("Reserved words must be 0: %d\n",  fileHeader.bfReserved1);
    printf("Reserved words must be 0: %d\n",  fileHeader.bfReserved2);
    printf("Offset bytes of actual bitmap data: %d\n",  fileHeader.bfOffBits);
}
void showBmpInfoHead(BITMAPINFOHEADER pBmpinfoHead) 
{//Define the function to display the information, and the information header structure is passed in
   printf("Bitmap Information Header:\n" );   
   printf("The size of the message header: %d\n" ,infoHeader.biSize);   
   printf("Bitmap width: %d\n" ,infoHeader.biWidth);   
   printf("Bitmap height: %d\n" ,infoHeader.biHeight);   
   printf("The number of planes of the image (the number of planes is the number of palettes, the default is 1 palette): %d\n" ,infoHeader.biPlanes);   
   printf("Number of bits per pixel: %d\n" ,infoHeader.biBitCount);   
   printf("Compression method:%d\n" ,infoHeader.biCompression);   
   printf("Image size: %d\n" ,infoHeader.biSizeImage);   
   printf("Horizontal resolution: %d\n" ,infoHeader.biXPelsPerMeter);   
   printf("Vertical resolution: %d\n" ,infoHeader.biYPelsPerMeter);   
   printf("Number of colors used: %d\n" ,infoHeader.biClrUsed);   
   printf("Number of important colors: %d\n" ,infoHeader.biClrImportant);   
}

int main()
{
    FILE* fp;    
    fp = fopen("textures/test.bmp", "rb"); //Read the image.bmp file in the same directory.
    if(fp == NULL)
    {
        printf("Failed to open'image.bmp'!\n");
        return -1;
    }
    //If you do not read the bifType first, according to the C language structure Sizeof operation rule-the whole is greater than the sum of the parts, resulting in misalignment of the read file
    unsigned short  fileType;   
    fread(&fileType,1,sizeof (unsigned short), fp);  
    if (fileType == 0x4d42)   
    {   
        printf("The file type identification is correct!" );  
        printf("\nFile identifier: %d\n", fileType); 
        fread(&fileHeader, 1, sizeof(BITMAPFILEHEADER), fp);
        showBmpHead(fileHeader);
        fread(&infoHeader, 1, sizeof(BITMAPINFOHEADER), fp);
        showBmpInfoHead(infoHeader);
        fclose(fp);        
    }
	printf("%lu\n", sizeof(BITMAPFILEHEADER));
}