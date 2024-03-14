// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "pixel.h"
#define GET_PIXEL(a, i ,j) (*(*((a) + (i)) + (j)))

void swap(Pixel *p1, Pixel *p2)
{
	Pixel aux;
	aux = *p1;
	*p1 = *p2;
	*p2 = aux;
}

void SwapLine(Pixel *l1, Pixel *l2, int width)
{
	int i;
	for (i = 0; i < width; i++)
	{
		swap(&l1[i], &l2[i]);
	}
}

void reversePic(Picture *pic)
{
	int i;
	for (i = 0; i <  pic->height / 2; i++)
	{
		SwapLine(pic->pix_array[i], pic->pix_array[pic->height - 1 - i], pic->width);
	}
}

void colorToGray(Picture *pic)
{
	int i, j;
	Pixel *p;
	for (i = 0; i < pic->height; i++)
	{
		for (j = 0; j < pic->width; j++)
		{
			p = &GET_PIXEL(pic->pix_array, i, j);
			p->R = 0.3 * p->R;
			p->G = 0.59 * p->G;
			p->B = 0.11 * p->B;
		}
	}
}

int main(void)
{
	int height, width;

	scanf("%d%d", &height, &width);
	Pixel **pix_array = generatePixelArray(height, width);
	Picture *pic = generatePicture(height, width, pix_array);

	printPicture(pic);
	printf("Matricea inversata: \n");
	reversePic(pic);
	printPicture(pic);

	colorToGray(pic);
	printf("Color to Gray: \n");
	printPicture(pic);

	freePicture(&pic);
	freePixelArray(&pix_array, height, width);
	return 0;
}

