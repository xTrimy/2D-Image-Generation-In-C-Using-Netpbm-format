#include "pch.h"
#include "SaveToBMP.h"
#include "Shapes.h"

void setBitmapPixels(Shapes, SaveToBMP::rgb_data*);
int randomColor(void);

int main() {
	SaveToBMP x;
	Shapes sh;
	sh.background(255);
	sh.setAntiAliasing(true);
	sh.fill(0);
	sh.rect(0, 0, 100, 20);
	int dpi = 256;
	SaveToBMP::rgb_data *pixels = new SaveToBMP::rgb_data[sh.width * sh.height];
	std::srand(time(0));

	setBitmapPixels(sh, pixels);
	x.save_bitmap("img.bmp", sh.width, sh.height, dpi, pixels);
}

void setBitmapPixels(Shapes sh, SaveToBMP::rgb_data*pixels) {
	int r, g, b;
	b = randomColor();
	g = randomColor();
	r = randomColor();
	for (int x = 0; x < sh.width; x++) {
		for (int y = 0; y < sh.height; y++) {
			int a = y * sh.width + x;
			pixels[a].r = (sh.X[x][sh.height - y - 1] + r >= 255) ? 255 : sh.X[x][sh.height - y - 1] + r;
			pixels[a].g = (sh.X[x][sh.height - y - 1] + g >= 255) ? 255 : sh.X[x][sh.height - y - 1] + g;
			pixels[a].b = (sh.X[x][sh.height - y - 1] + b >= 255) ? 255 : sh.X[x][sh.height - y - 1] + b;
		}
	}
}

int randomColor() {
	return std::rand() % 256;
}
