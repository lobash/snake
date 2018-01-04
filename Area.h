#ifndef AREA_H
#define AREA_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Area {
	
	private :
		int width, height;
		void clearScreen();
		void createBorder();
		
	public:
		static char *simbolBorder;
		Area(int width, int height);
		void createArea();
};
#endif
