#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;

	struct image_s dataNew;
	struct image_s *imageNew = &dataNew;

	int i, j, r, r1, red, green, blue;

	r1 = read_ppm("lena.ppm", image);
	if (r1 == 0) {
		r = new_ppm(imageNew, (image->width)*3, (image->height)*3);
	}

	if (r == 0 && r1 == 0) {
		for (j = 0; j < image->height; j++) {
			for (i = 0; i < image->width; i++) {
				
				red = image->pix[j * image->width + i].r;
				green = image->pix[j * image->width + i].g;
				blue = image->pix[j * image->width + i].b;
				
				// red
				for (int k = 0; k < 3; k++) {
					imageNew->pix[(j * 3 + k) * imageNew->width + i * 3].r = 0;
					imageNew->pix[(j * 3 + k) * imageNew->width + i * 3].g = 0;
					imageNew->pix[(j * 3 + k) * imageNew->width + i * 3].b = 0;
				}
				if (red > 74 && red < 135) {
					imageNew->pix[(j * 3 + 1) * imageNew->width + i * 3].r = 255;
				}
				else if (red > 134 && red < 180) {
					imageNew->pix[(j * 3) * imageNew->width + i * 3].r = 255;
					imageNew->pix[(j * 3 + 2) * imageNew->width + i * 3].r = 255;
				}
				else if (red > 179 && red < 256){
					imageNew->pix[(j * 3) * imageNew->width + i * 3].r = 255;
					imageNew->pix[(j * 3 + 1) * imageNew->width + i * 3].r = 255;
					imageNew->pix[(j * 3 + 2) * imageNew->width + i * 3].r = 255;
				}

				// green
				for (int k = 0; k < 3; k++) {
					imageNew->pix[(j * 3 + k) * imageNew->width + i * 3 + 1].r = 0;
					imageNew->pix[(j * 3 + k) * imageNew->width + i * 3 + 1].g = 0;
					imageNew->pix[(j * 3 + k) * imageNew->width + i * 3 + 1].b = 0;
				}
				if (green > 74 && green < 135) {
					imageNew->pix[(j * 3 + 1) * imageNew->width + i * 3 + 1].g = 255;
				}
				else if (green > 134 && green < 180) {
					imageNew->pix[(j * 3) * imageNew->width + i * 3 + 1].g = 255;
					imageNew->pix[(j * 3 + 2) * imageNew->width + i * 3 + 1].g = 255;
				}
				else if (green > 179 && green < 256){
					imageNew->pix[(j * 3) * imageNew->width + i * 3 + 1].g = 255;
					imageNew->pix[(j * 3 + 1) * imageNew->width + i * 3 + 1].g = 255;
					imageNew->pix[(j * 3 + 2) * imageNew->width + i * 3 + 1].g = 255;
				}

				// blue
				for (int k = 0; k < 3; k++) {
					imageNew->pix[(j * 3 + k) * imageNew->width + i * 3 + 2].r = 0;
					imageNew->pix[(j * 3 + k) * imageNew->width + i * 3 + 2].g = 0;
					imageNew->pix[(j * 3 + k) * imageNew->width + i * 3 + 2].b = 0;
				}
				if (blue > 74 && blue < 135) {
					imageNew->pix[(j * 3 + 1) * imageNew->width + i * 3 + 2].b = 255;
				}
				else if (blue > 134 && blue < 180) {
					imageNew->pix[(j * 3) * imageNew->width + i * 3 + 2].b = 255;
					imageNew->pix[(j * 3 + 2) * imageNew->width + i * 3 + 2].b = 255;
				}
				else if (blue > 179 && blue < 256) {
					imageNew->pix[(j * 3) * imageNew->width + i * 3 + 2].b = 255;
					imageNew->pix[(j * 3 + 1) * imageNew->width + i * 3 + 2].b = 255;
					imageNew->pix[(j * 3 + 2) * imageNew->width + i * 3 + 2].b = 255;
				}
			}
		}
		write_ppm("zoomLena.ppm", imageNew);
		
		printf("Imagem com zoom 3x criada com sucesso!");

		free_ppm(image);
		free_ppm(imageNew);
	}

	return 0;
}


