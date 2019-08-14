#pragma once
#include <iostream>
//#include <Windows.h>
#include "ConsoleFunctions.h"

using namespace std;
class map
{
	int i, j, floor;
	int batch[30][50] = { 0, };
public:

	void mapNum(int num = 1) {
		switch (num) {
			case 1:
				
				for (i = 0; i < 50; i++) {
					batch[0][i] = 1;
					batch[10][i] = 1;
					//cout << batch[0][i];
				}
				for (i = 1; i < 10; i++) {
					batch[i][0] = 1;
					batch[i][49] = 1;
					batch[i][17] = 1;
					batch[i][32] = 1;

				}
				batch[10][16] = batch[10][1] = 0;
				

			
				break;

			case 2 :

				break;

			case 3:

				break;

		}

	}

	void drawMap() {
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 50; j++) {
				//std::cout << batch[i][j];
				if (batch[i][j] == 1) {
					cout << "бс";
				}
				else {
					cout << "  ";
				}
				/*else {
					cout << batch[i][j];
				}*/
		
			}
			std::cout << "\n";
		}
		/*for (int i = 0; i < 50; i++) {
			cout << ("бс");
		}*/

		gotoxy(16, 4);
		cout << "2-5";
		gotoxy(1, 1);
	}
	void removeMap() {
		system("cls");
	}

	void getBatch() {
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 50; j++) {
				std::cout << batch[i][j];
				

			}
			std::cout << "\n";
		}
	}
	
};

