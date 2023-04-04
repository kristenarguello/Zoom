#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;

	struct image_s dataNew;
	struct image_s *imageNew = &dataNew;

	int i, j, r, r1, h, w;

	r1 = read_ppm("lena.ppm", image);
	if (r1 == 0)
	{
		h = image->height;
		w = image->width;

		printf("width: %d, height: %d\n", image->width, image->height);
		for (j = 0; j < image->height; j++)
		{
			
			for (i = 0; i < image->width; i++)
			{
				printf("(%d %d) %d %d %d\n", i, j,
					   image->pix[j * image->width + i].r,
					   image->pix[j * image->width + i].g,
					   image->pix[j * image->width + i].b);

			}//printa os pixels
		}

		// image->pix[50 * image->width + 20].r = 255;
		// image->pix[50 * image->width + 20].g = 255;
		// image->pix[50 * image->width + 20].b = 255;

		write_ppm("lena_copy.ppm", image);//faz o arquivo no copy

	}

	if (r1 == 0) 
		r = new_ppm(imageNew, w*3, h*3);//cria unma nova imagem do 0

	if (r == 0 && r1 == 0)
	{
		for (j = 0; j < image->height; j++)
		{
			for (i = 0; i < image->width; i++)
			{
				imageNew->pix[j * imageNew->width + i].r = image->pix[j * image->width + i].r;
				imageNew->pix[j * imageNew->width + i].g = image->pix[j * image->width + i].g;
				imageNew->pix[j * imageNew->width + i].b = image->pix[j * image->width + i].b;
			}
		}


		write_ppm("test.ppm", imageNew);

		free_ppm(image);
		free_ppm(imageNew);
	}

	return 0;
}


