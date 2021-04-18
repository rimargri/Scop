/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft_parse_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:16:47 by cvernius          #+#    #+#             */
/*   Updated: 2021/04/17 20:08:32 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// #include <iostream.h>
// #include <stdio.h>
// #include <stdlib.h>
#include <stdint.h>
#include "bmp_loader.h"

int *load_BMP(const char *fname, int &mx, int &my)
{
	int mx;
	int my;
	
    mx = -1;
	my = -1;
    FILE *f = fopen(fname, "rb");
    if(!f)
		return NULL;
    t_bmp_header bh;    // File header sizeof(BMPheader) = 56
    size_t res;

    // читаем заголовок
    res = fread(&bh, 1, sizeof(t_bmp_header), f);
    if (res != sizeof(t_bmp_header))
	{
		fclose(f);
		return NULL;
	}

    // проверяем сигнатуру
    if(bh.bfType != 0x4d42 && bh.bfType != 0x4349 && bh.bfType != 0x5450)
	{
		fclose(f);
		return NULL;
	}

    // проверка размера файла
    fseek(f, 0, SEEK_END);
    int filesize = ftell(f);
    // восстановим указатель в файле:
    fseek(f, sizeof(t_bmp_header), SEEK_SET);
    // проверим условия
    if (bh.bfSize != filesize ||
        bh.bfReserved != 0    ||
        bh.biPlanes   != 1    ||
       (bh.biSize!=40 && bh.biSize!=108 && bh.biSize!=124)||
        bh.bfOffBits != 14+bh.biSize ||

        bh.biWidth <1 || bh.biWidth >10000 ||
        bh.biHeight<1 || bh.biHeight>10000 ||
        bh.biBitCount    != 24 ||             // рассматриваем только полноцветные изображения
        bh.biCompression !=  0                // рассматриваем только несжатие изображения
	)
    { 
            fclose(f); 
            return NULL; 
    }
    // Заголовок прочитан и проверен, тип - верный (BGR-24), размеры (mx,my) найдены
    int mx = bh.biWidth;
    int my = bh.biHeight;
    int mx3 = (3 * mx + 3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
    unsigned char *tmp_buf = new unsigned char[mx3 * my];    // читаем данные
    res = fread(tmp_buf, 1, mx3*my, f);
    if((int)res != mx3*my) {
		delete []tmp_buf;
		fclose(f);
		return NULL;
	}
    // данные прочитаны
    fclose(f); 

    // выделим память для результата
    v = new int[mx * my];

    // Перенос данных (не забудем про BGR->RGB)
    unsigned char *ptr = (unsigned char *) v;
    for(int y = my-1; y >= 0; y--) {
        unsigned char *pRow = tmp_buf + mx3*y;

        for(int x = 0; x < mx; x++) {
            *ptr++ = *(pRow + 2);
            *ptr++ = *(pRow + 1);
            *ptr++ = *pRow; 
            pRow += 3;
            ptr++;
        }
    }
    delete []tmp_buf;
    return v;    // OK
}


// return mx, my	