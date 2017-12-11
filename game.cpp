#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <windows.h> 


using namespace std;



bool bGameOver;
const int AREA_WIDTH = 20;
const int AREA_HEIGHT = 20;
const int SIZE_ARR = 100;
int iSnakePosX, iSnakePosY, iFruitPosX, iFruitPosY, iScore;

int tailX[SIZE_ARR], tailY[SIZE_ARR]; //pos tail
int nTail; //count tail
enum eDirection {
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
eDirection eDir;


void setup() {
	srand(time(NULL));
	bGameOver = false;
	eDir = STOP;
	iSnakePosX = AREA_WIDTH/2-1;
	iSnakePosY = AREA_HEIGHT/2-1;
	iFruitPosX = rand() % iSnakePosX;
	iFruitPosY = rand() % iSnakePosY;
	iScore = 0;
}

void draw(){
	system("cls");
	
	for(int i=0; i<=AREA_WIDTH; i++) {
		cout << "#";
	}
	cout << endl;
	
	for (int i=0; i<AREA_HEIGHT; i++) {
		for (int j=0; j<AREA_WIDTH; j++){
			if (j==0|| j==AREA_WIDTH-1) {
				cout << "#";
			}
			
			if (i == iSnakePosY && j == iSnakePosX) {
				cout << "0";
			} else if(i == iFruitPosY && j == iFruitPosX) {
				cout << "F";
			} else {
				bool print = false;
				for (int k=0; k<nTail; k++) {
					if (tailX[k] == j && tailY[k] == i){
						print = true;
						cout << "o";						
					}
				}
				if (!print) {
					cout << " ";
				}
			}

		}
		cout << endl;
	}
	
	for(int i=0; i<=AREA_WIDTH; i++) {
		cout << "#";
	}
	cout << endl;
	
	cout << "Score: " << iScore << endl;
}

void input(){
	//button listener
	if(_kbhit()){
		switch(_getch()) {
			case 'a':
				eDir = LEFT;
				break;
				
			case 's':
				eDir = DOWN;
				break;
				
			case 'd':
				eDir = RIGHT;
				break;
				
			case 'w':
				eDir = UP;
				break;
				
			case 'x':
				bGameOver = true;
				break;
		}
	}
}

void logic(){
	
	//tail
	int prevX = tailX[0]; 
	int prevY = tailY[0]; 
	int prev2X, prev2Y;
	tailX[0] = iSnakePosX;
	tailY[0] = iSnakePosY;
	
	for (int i=1; i<nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	//tail
	
	switch (eDir){
		case LEFT:
			iSnakePosX--;
			break;
		case RIGHT:
			iSnakePosX++;
			break;			
		case UP:
			iSnakePosY--;
			break;
		case DOWN:
			iSnakePosY++;
			break;			
			

	}
	
		//exit before border
		if (iSnakePosX >= AREA_WIDTH-1) {
			iSnakePosX = 0;
		} else if (iSnakePosX < 0) {
			iSnakePosX = AREA_WIDTH -2;
		}
		
		if (iSnakePosY >= AREA_HEIGHT) {
			iSnakePosY = 0;
		} else if (iSnakePosY < 0) {
			iSnakePosY = AREA_HEIGHT-1;
		}
		
		//self eat
		for (int i=0; i<nTail; i++) {
			if (tailX[i] == iSnakePosX && tailY[i] == iSnakePosY){
				bGameOver = true;
			}
		}
		
		//eat fruit
		
		if (iSnakePosX == iFruitPosX && iSnakePosY == iFruitPosY) {
			 srand(time(NULL));
			iScore = iScore+10+rand()%10;
			iFruitPosX = (rand() % AREA_WIDTH-1)+1;
			iFruitPosY = (rand() % AREA_HEIGHT-1)+1;
			nTail++;
			printf("\a");
		}
}

int main(int argc, char** argv) {
	setup();
	while (!bGameOver) {
		draw();
		input();
		logic();
		Sleep (100);
	}
	
	return 0;
}
