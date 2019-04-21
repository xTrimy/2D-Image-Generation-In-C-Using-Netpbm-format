
#include "pch.h"
#include "Shapes.h"



int main() {
	Shapes sh;
	sh.background(255);
	sh.setAntiAliasing(true);
	sh.fill(0);
	sh.rect(0, 0, 20, 20);
	sh.draw();
}
