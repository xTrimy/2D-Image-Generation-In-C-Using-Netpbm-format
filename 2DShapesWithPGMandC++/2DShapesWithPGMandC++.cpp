
#include "pch.h"
#include <iostream>
#include <fstream>
std::ofstream file("imgs.pgm");
const int height = 100, width = 100;
int X[height][width];
int oldX[height][width];
int strokeC = 0;
int fillC = 100;
int strokeW = 1;
bool antialiasing = true;
void rect(int, int, int, int);
void rectStroke(int, int, int, int);
void circle(int, int, int);
void circleStroke(int, int, int);
void fill(int);
void stroke(int);
void strokeWeight(int);
void setAntiAliasing(bool);
void oldCopy();

void background(int);
void draw();
int main() {
	background(100);
	file << "P2";
	file << std::endl << width << " " << height << std::endl << "100" << std::endl;
	rectStroke(1, 10, 10, 10);
	strokeWeight(0);
	setAntiAliasing(true);
	fill(0);
	circle(50, 50, 20);
	rect(10, 10, 20, 20);
	circle(40, 80, 20);
	rect(18, 50, 20, 20);
	draw();
	file.close();
	system("imgs.pgm");

}

void rect(int x, int y, int sx, int sy) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (i >= x && i < x + sx && j >= y && j < y + sy) {
				X[i][j] = fillC;
			}
		}
	}
}
void rectStroke(int x, int y, int sx, int sy) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

		}
	}
}
void circle(int x, int y, int r) {
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
void circleStroke(int x, int y, int r) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			float cr = sqrt(pow((i - x), 2) + pow((j - y), 2));
			if (r - cr >= 0 && r - cr <= strokeW) {
				X[j][i] = strokeC + ((antialiasing) ? ((oldX[j][i] - 100 * (r - cr) <= 0)?0: oldX[j][i] - 100 * (r - cr)) : 0);
			}
		}
	}
}
void background(int x) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			X[j][i] = x;
		}
	}
}
void draw() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			file << X[j][i] << " ";
		}
		file << std::endl;
	}
}
void stroke(int x) {
	strokeC = x;
}
void fill(int x) {
	fillC = x;
}
void strokeWeight(int x) {
	x = (x <= 0) ? 1 : x;
	strokeW = x;
}
void setAntiAliasing(bool x) {
	antialiasing = x;
}

void oldCopy() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			oldX[j][i] = X[j][i];
		}
	}
}