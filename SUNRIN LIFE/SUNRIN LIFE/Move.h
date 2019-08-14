#pragma once
#include <iostream>
#include "ConsoleFunctions.h"
#include <Windows.h>
#include <conio.h>
#include <string>
#include <stdio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

using namespace std;
class Move
{
public:
	void moveCharacter(string name) {
		int key;  //움직일 때 필요한 변수 
		int x = 0, y = 0;       // x좌표, y좌표 
		char c[4];
		strcpy_s(c, name.c_str());

		puts(c);

		while (1)
		{
			key = _getch();     // 자동입력 
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
		
	}

};

