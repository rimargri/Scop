/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:29:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/18 20:18:58 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_LOADER_H
#define BMP_LOADER_H

#include <stdio.h>
#include <stdlib.h>



// typedef unsigned __int16 WORD;

// typedef struct		s_bmp_header
// {
//  	WORD			bfType;         // 0x4d42 | 0x4349 | 0x5450
//  	int				bfSize;         // размер файла
//  	int				bfReserved;     // 0
//  	int				bfOffBits;      // смещение до поля данных,
//  	   				                // обычно 54 = 16 + biSize
//  	int				biSize;         // размер струкуры в байтах:
//  	   				                // 40(BITMAPINFOHEADER) или 108(BITMAPV4HEADER)
//  	   				                // или 124(BITMAPV5HEADER)
//  	int				biWidth;        // ширина в точках
//  	int				biHeight;       // высота в точках
//  	WORD			biPlanes;       // всегда должно быть 1
//  	WORD			biBitCount;     // 0 | 1 | 4 | 8 | 16 | 24 | 32
//  	int				biCompression;  // BI_RGB | BI_RLE8 | BI_RLE4 |
//  	   				                // BI_BITFIELDS | BI_JPEG | BI_PNG
//  	   				                // реально используется лишь BI_RGB
//  	int				biSizeImage;    // Количество байт в поле данных
//  	   				                // Обычно устанавливается в 0
//  	int				biXPelsPerMeter;// горизонтальное разрешение, точек на дюйм
//  	int				biYPelsPerMeter;// вертикальное разрешение, точек на дюйм
//  	int				biClrUsed;      // Количество используемых цветов
//  	   				                // (если есть таблица цветов)
//  	int				biClrImportant; // Количество существенных цветов.
//  	    			                // Можно считать, просто 0
// }				t_bmp_header;



// #define DATA_OFFSET 0x000A
// #define WIDTH_OFFSET 0x0012
// #define HEIGHT_OFFSET 0x0016
// #define BITS_PER_PIXEL_OFFSET 0x001C
// #define HEADER_SIZE 14
// #define INFO_HEADER_SIZE 30
// // #define NO_COMPRESSION 0
// // #define MAX_NUMBER_OF_COLORS 0
// // #define ALL_COLORS_REUQIRED 0

// typedef unsigned int int32;
// typedef short int16;
// typedef unsigned char byte;

// typedef struct	s_bmp
// {
// 	byte		*pixels;
// 	int32		width;
// 	int32		height;
// 	int32		bytes_per_pixel;
// }				t_bmp;





// struct pixel {
//     uint8_t blue;
//     uint8_t green;
//     uint8_t red;
//     //uint8_t alpha;
// } __attribute__((__packed__));



// struct bmp_header{
//     uint16_t type;              // "BM" (0x42, 0x4D)
//     uint32_t size;              // file size
//     uint16_t reserved1;         // not used (0)
//     uint16_t reserved2;         // not used (0)
//     uint32_t offset;            // offset to image data (54B)
//     uint32_t dib_size;          // DIB header size (40B)
//     uint32_t width;             // width in pixels
//     uint32_t height;            // height in pixels
//     uint16_t planes;            // 1
//     uint16_t bpp;               // bits per pixel (24)
//     uint32_t compression;       // compression type (0/1/2) 0
//     uint32_t image_size;        // size of picture in bytes, 0
//     uint32_t x_ppm;             // X Pixels per meter (0)
//     uint32_t y_ppm;             // X Pixels per meter (0)
//     uint32_t num_colors;        // number of colors (0)
//     uint32_t important_colors;  // important colors (0)
// } __attribute__((__packed__));

// /**
//  * Read the pixels
//  *
//  * Reads the data (pixels) from stream representing the image. If the stream
//  * is not open or header is not provided, returns `NULL`.
//  *
//  * @param stream opened stream, where the image data are located
//  * @param header the BMP header structure
//  * @return the pixels of the image or `NULL` if stream or header are broken
//  */
// struct pixel* read_data(FILE* stream, const struct bmp_header* header);


typedef struct		s_bmp
{
	unsigned char	info[54];
	int				width;
	int				height;
	int				size;
	unsigned char	*data;
}					t_bmp;

void	read_bmp(char *filename, t_bmp *bmp);


#endif
