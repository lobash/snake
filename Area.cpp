#include "Area.h"

char *Area::simbolBorder = "#";

void writeHorizontalLine(int width)  {
	width = width+1;
	for (int i = 0; i < width; i++) {
		cout << *Area::simbolBorder;
	}
	cout << endl;			
}

void writeVerticalLines(int width, int height) {
	for (int i=0; i< height; i++) {
		for (int j=0; j< width; j++) {
			if (j == 0 || j == width-1) {
				cout << *Area::simbolBorder;
			}
			
			cout << " ";
		}
		cout << endl;
	}			
}
	
Area::Area(int width, int height)
	:width(width),height(height) {}
		
void Area::clearScreen() {
	system("cls");
}

void Area::createBorder() {
	writeHorizontalLine(width);
	writeVerticalLines(width, height);
	writeHorizontalLine(width);
}

void Area::createArea() {
	clearScreen();
	createBorder();
}

