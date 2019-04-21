#pragma once
class Shapes
{
public:
	const int height = 100, width = 100;
	int X[100][100];
	int oldX[100][100];
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


};

