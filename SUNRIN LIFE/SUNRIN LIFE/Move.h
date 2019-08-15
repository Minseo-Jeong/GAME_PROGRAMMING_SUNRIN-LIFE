#pragma once
#include <iostream>
#include "ConsoleFunctions.h"
#include <Windows.h>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <thread>
#include <time.h>
#include <math.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

using namespace std;
class Move
{
	//debug
	/*int getX() {
		CONSOLE_SCREEN_BUFFER_INFO a;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
		return a.dwCursorPosition.X;
	}
	int getY() {
		CONSOLE_SCREEN_BUFFER_INFO a;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
		return a.dwCursorPosition.Y;
	}
	void printCursor() {
		cout << "(" << getX() << "," << getY() << ")";
	}
	*/
	int x_b, y_b;
	int x = 4, y = 4;
	int x1 = 3, y1 = 3;
	string name = "나";
	string college;
	int check = 10;
	int volunteer = 10;
	int setc = 0;
	int timetable = 1;
	int sum = 0;

public:
	void printsc() {

		gotoxy(85, 3);
		cout << "           " << endl;
		gotoxy(85, 4);
		cout << "           " << endl;
		gotoxy(85, 5);
		cout << "           "<<endl;
		gotoxy(85, 6);
		cout << "          ";

		gotoxy(85, 3);
		cout << "봉사 : " << volunteer << endl;
		gotoxy(85, 4);
		cout << "출결 : " << check << endl;
		gotoxy(85, 5);
		cout << "세특 : " << setc << endl;
		gotoxy(85, 6);
		cout << timetable << "교시";
	}
	
	void printsc(int x, int y, int sum) {
		gotoxy(x, y++);
		cout << "봉사 : " << volunteer << endl;
		gotoxy(x, y++);
		cout << "출결 : " << check << endl;
		gotoxy(x, y++);
		cout << "세특 : " << setc << endl;
		gotoxy(x, ++y);
		cout << "총합 : " << sum;
	}
	void moveCharacter(const string name_Inp, int qual = 1) {
		int key;  //움직일 때 필요한 변수 
		
		   // x좌표, y좌표 
		name = name_Inp;
		int start;
		char c[4];
		bool timer_init = 1;
		strcpy_s(c, name.c_str());
		printsc();

		while (1)
		{
			if (timer_init) {
				start = GetTickCount64();
				timer_init = 0;
			}
			key = _getch();     // 자동입력 
			if (102 == key) {
				//printCursor();
				cout << x1 << "," << y1;
			}
			if((y1 == 10 && (x1 < 4 && x1>1) || (x1 > 30 && x1 < 33)) || (x1 >= 1 && y1 >= 1) && (x1 < 32 && y1 < 10) || (y1 >= 11&&y1<39)){
			//if ((x > 1 && y1 > 1) && (x < 3 && y < 9) || (x == 1 && y == 11) || (x == 10 && y == 11) || y > 11) {
				switch (key)   // key변수 - 스위치 
				{


				case UP:     // #define UP 에 대한 것 (위로 움직일 때) 
					if (y1 > 0) {
						gotoxy(x1, y1--); puts(" "); //위로 움직일 때마다 c 감소 
						gotoxy(x1, y1);   puts(c); //x,y1좌표에 대한 값 c 출력
					}

					break;
				case DOWN:  // #define DOWN 에 대한 것 (아래로 움직일 때)

					gotoxy(x1, y1++); puts(" "); // 아래로 움직일 때마다 c 증가 
					gotoxy(x1, y1);   puts(c); //x,y좌표에 대한 값 c 출력
					break;

				case LEFT:         //#define LEFT 에 대한 것 (왼쪽으로 움직일 때) 
					if (x1 > 0) {
						gotoxy(x1--, y1); puts(" ");     //왼쪽으로 움직일 때마다 c 감소 
						gotoxy(x1, y1);   puts(c);     //x,y좌표에 대한 값 *c 출력
					}
					break;

				case RIGHT:        //#define RIGHT 에 대한 것 (오른쪽으로 움직일 때) 

					gotoxy(x1++, y1); puts(" ");      //오른쪽으로 움직일 때마다 *c 증가 
					gotoxy(x1, y1);   puts(c);      //x1,y좌표에 대한 값 *c 출력 

					break;
				}
			}
			else {
				gotoxy(30, 15);
				setTextColor(ColorRed);
				cout <<name << "님 게임이 종료되었습니다";
				break;
			}
			moveCharacter();
			if (abs(sqrt((x1 - x) * (x1 - x) + (y1 - y)* (y1 - y)))<qual) {
				gotoxy(30, 15);
				setTextColor(ColorGreen);
				cout << name << "님 퀘스트 성공";
				Sleep(1000);
				//system("PAUSE");
				_getch();
				gotoxy(30, 15);
				cout << "                 ";
				setTextColor(ColorWhite);
				timetable++;
				volunteer += 4;
				setc += rand() % 4;
				printsc();
				timer_init = 1;
			}
			else if (GetTickCount64() - start >= 1000*10) {
				gotoxy(30, 15);
				cout << "시간 초과";
				Sleep(1000);
				_getch();
				gotoxy(30, 15);
				cout << "         ";
				check--;
				timetable++;
				printsc();
				timer_init = 1;
			}
			if (timetable > 7) {
				int texty = 20;
				system("cls");
				if (volunteer >= 20) {
					sum += 20;
				}
				else {
					sum += volunteer;
				}
				if (check == 10) {
					sum += 40;
				}
				else {
					sum = check * 3;
				}
				sum += setc * 3;
				if (sum > 50) {
					college = "서성한";
				}
				else if (sum > 46) {
					college = "중경외시";
				}
				else if (sum > 42) {
					college = "건동홍";
				}
				else if (sum > 38) {
					college = "국숭세단";
				}
				printsc(45, 7, sum);
				gotoxy(40, 15);
				if(sum<38) {
					cout << "아직 수능이 460일 남았어요" << endl;
					gotoxy(40, 16);
					cout << "정시파이터 화이팅!";
					Sleep(1000);
					break;
				}
				cout << "당신이 갈 수 있는 대학은" << college << "입니다";
				Sleep(1000);
				break;
			}
			
		}
		Sleep(1000);
		
	}

	void moveCharacter() {
		int key;  //움직일 때 필요한 변수 
		   // x좌표, y좌표 
		srand((unsigned int)time(0));
		//
		
		x_b = x;
		y_b = y;
		gotoxy(x_b, y_b);
		puts(" ");
		x = rand() % 100;
		y = rand() % 27 + 11;
		gotoxy(x, y);
		puts("왕");
		
		
	}
};

