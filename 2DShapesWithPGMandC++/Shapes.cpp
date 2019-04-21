#include "pch.h"
#include "Shapes.h"
std::ofstream file("img.pgm");

void Shapes::rect(int x, int y, int sx, int sy) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (i >= x && i < x + sx && j >= y && j < y + sy) {
				X[i][j] = fillC;
			}
		}
	}
}
void Shapes::rectStroke(int x, int y, int sx, int sy) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

		}
	}
}
void Shapes::circle(int x, int y, int r) {
	if (antialiasing) {
		oldCopy();
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			float cr = sqrt(pow((i - x), 2) + pow((j - y), 2));
			if (cr <= (r)) {
				X[j][i] = fillC;
			}
		}
	}
	circleStroke(x, y, r);
}
void Shapes::circleStroke(int x, int y, int r) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			float cr = sqrt(pow((i - x), 2) + pow((j - y), 2));
			if (r - cr >= 0 && r - cr <= strokeW) {
				X[j][i] = strokeC + ((antialiasing) ? ((oldX[j][i] - 255 * (r - cr) <= 0) ? 0 : oldX[j][i] - 255 * (r - cr)) : 0);
			}
		}
	}
}
void Shapes::background(int x) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			X[j][i] = x;
		}
	}
}
void Shapes::draw() {
	file << "P2" << std::endl << width << " " << height << std::endl << "255" << std::endl;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			file << X[j][i] << " ";
		}
		file << std::endl;
	}
	file.close();
	system("img.pgm");

}
void Shapes::stroke(int x) {
	strokeC = x;
}
void Shapes::fill(int x) {
	fillC = x;
}
void Shapes::strokeWeight(int x) {
	x = (x <= 0) ? 1 : x;
	strokeW = x;
}
void Shapes::setAntiAliasing(bool x) {
	antialiasing = x;
}

void Shapes::oldCopy() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			oldX[j][i] = X[j][i];
		}
	}
}