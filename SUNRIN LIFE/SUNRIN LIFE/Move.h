#pragma once
#include <iostream>
#include "ConsoleFunctions.h"
#include <Windows.h>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <thread>

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
	int x = 3, y = 3;    
public:
	void moveCharacter(string name = "나") {
		int key;  //움직일 때 필요한 변수 
		   // x좌표, y좌표 
		char c[4];
		strcpy_s(c, name.c_str());


		while (1)
		{
			key = _getch();     // 자동입력 
			if (102 == key) {
				//printCursor();
				cout << x << "," << y;
			}
			if((y == 10 && (x < 3 && x>1) || (x > 30 && x < 33)) || (x >= 1 && y >= 1) && (x < 32 && y < 10) || y >= 11){
			//if ((x > 1 && y > 1) && (x < 3 && y < 9) || (x == 1 && y == 11) || (x == 10 && y == 11) || y > 11) {
				switch (key)   // key변수 - 스위치 
				{


				case UP:     // #define UP 에 대한 것 (위로 움직일 때) 
					if (y > 0) {
						gotoxy(x, y--); puts(" "); //위로 움직일 때마다 c 감소 
						gotoxy(x, y);   puts(c); //x,y좌표에 대한 값 c 출력
					}

					break;
				case DOWN:  // #define DOWN 에 대한 것 (아래로 움직일 때)

					gotoxy(x, y++); puts(" "); // 아래로 움직일 때마다 c 증가 
					gotoxy(x, y);   puts(c); //x,y좌표에 대한 값 c 출력
					break;

				case LEFT:         //#define LEFT 에 대한 것 (왼쪽으로 움직일 때) 
					if (x > 0) {
						gotoxy(x--, y); puts(" ");     //왼쪽으로 움직일 때마다 c 감소 
						gotoxy(x, y);   puts(c);     //x,y좌표에 대한 값 *c 출력
					}
					break;

				case RIGHT:        //#define RIGHT 에 대한 것 (오른쪽으로 움직일 때) 

					gotoxy(x++, y); puts(" ");      //오른쪽으로 움직일 때마다 *c 증가 
					gotoxy(x, y);   puts(c);      //x,y좌표에 대한 값 *c 출력 

					break;
				}
			}
			else {
				gotoxy(30, 15);
				setTextColor(ColorRed);
				cout <<name << "님 게임이 종료되었습니다.";
				break;
			}
			
		}
		Sleep(1000);
		
	}
	void print() {
		cout << "fsafdas";
	}
	/*void Start() {
		thread threadM1(moveCharacter("나"));
		thread threadM2(moveCharacter("왕"));
	}*/
};

