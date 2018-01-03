#ifndef AREA_H
#define AREA_H

#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

class Area {
	
	private :
		int width, height;
		const string _SIMBOL = "#";
		void clearScreen() {
			system("cls");
		}
		
		void writeHorizontalLine()  {
			for (int i = 0; i < width; i++) {
				cout << this->_SIMBOL;
			}
			cout << endl;			
		}
		
		void writeVerticalLines() {
			for (int i=0; i< height; i++) {
				for (int j=0; j< width; j++) {
					if (j == 0 || j == width-1) {
						cout << _SIMBOL;
					}
					
					cout << " ";
				}
				cout << endl;
			}			
		}
		
		void createBorder() {
			writeHorizontalLine();
			writeVerticalLines();
			writeHorizontalLine();
		}
	

		
	public:
		Area(int width, int height);
		void createArea() {
			clearScreen();
			createBorder();
		}
		
};

#endif
