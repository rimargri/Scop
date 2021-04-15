/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:29:49 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/15 20:49:47 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct			s_BMPFileHeader
{
	unsigned short int	file_type{0x4D42};          // File type always BM which is 0x4D42
	unsigned int		file_size{0};               // Size of the file (in bytes)
	unsigned short int	reserved1{0};               // Reserved, always 0
	unsigned short int	reserved2{0};               // Reserved, always 0
	unsigned int		offset_data{0};             // Start position of pixel data (bytes from the beginning of the file)
}						t_BMPFileHeader;


// uint16_t unsigned short int
// uint32_t unsigned int


typedef struct			s_BMPInfoHeader
{
	unsigned int		size{ 0 };                     	// Size of this header (in bytes)
	int					width{ 0 };                    	// width of bitmap in pixels
	int					height{ 0 };                   	// height of bitmap in pixels
	                                         			//       (if positive, bottom-up, with origin in lower left corner)
	                                         			//       (if negative, top-down, with origin in upper left corner)
	unsigned short int	planes{ 1 };             		// No. of planes for the target device, this is always 1
	unsigned short int	bit_count{ 0 };          		// No. of bits per pixel
	unsigned int		compression{ 0 };              	// 0 or 3 - uncompressed. THIS PROGRAM CONSIDERS ONLY UNCOMPRESSED BMP images
	unsigned int		size_image{ 0 };               	// 0 - for uncompressed images
	int					x_pixels_per_meter{ 0 };
	int					y_pixels_per_meter{ 0 };
	unsigned int		colors_used{ 0 };              	// No. color indexes in the color table. Use 0 for the max number of colors allowed by bit_count
	unsigned int		colors_important{ 0 };         	// No. of colors used for displaying the bitmap. If 0 all colors are required
}						t_BMPInfoHeader;



typedef struct		s_BMPColorHeader
{
	unsigned int	red_mask{ 0x00ff0000 };         // Bit mask for the red channel
	unsigned int	green_mask{ 0x0000ff00 };       // Bit mask for the green channel
	unsigned int	blue_mask{ 0x000000ff };        // Bit mask for the blue channel
	unsigned int	alpha_mask{ 0xff000000 };       // Bit mask for the alpha channel
	unsigned int	color_space_type{ 0x73524742 }; // Default "sRGB" (0x73524742)
	unsigned int	unused[16]{ 0 };                // Unused data for sRGB color space
}					t_BMPColorHeader;

