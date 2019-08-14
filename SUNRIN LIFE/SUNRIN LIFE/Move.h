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
	void moveCharacter(string name = "��") {
		int key;  //������ �� �ʿ��� ���� 
		   // x��ǥ, y��ǥ 
		char c[4];
		strcpy_s(c, name.c_str());


		while (1)
		{
			key = _getch();     // �ڵ��Է� 
			if (102 == key) {
				//printCursor();
				cout << x << "," << y;
			}
			if((y == 10 && (x < 3 && x>1) || (x > 30 && x < 33)) || (x >= 1 && y >= 1) && (x < 32 && y < 10) || y >= 11){
			//if ((x > 1 && y > 1) && (x < 3 && y < 9) || (x == 1 && y == 11) || (x == 10 && y == 11) || y > 11) {
				switch (key)   // key���� - ����ġ 
				{


				case UP:     // #define UP �� ���� �� (���� ������ ��) 
					if (y > 0) {
						gotoxy(x, y--); puts(" "); //���� ������ ������ c ���� 
						gotoxy(x, y);   puts(c); //x,y��ǥ�� ���� �� c ���
					}

					break;
				case DOWN:  // #define DOWN �� ���� �� (�Ʒ��� ������ ��)

					gotoxy(x, y++); puts(" "); // �Ʒ��� ������ ������ c ���� 
					gotoxy(x, y);   puts(c); //x,y��ǥ�� ���� �� c ���
					break;

				case LEFT:         //#define LEFT �� ���� �� (�������� ������ ��) 
					if (x > 0) {
						gotoxy(x--, y); puts(" ");     //�������� ������ ������ c ���� 
						gotoxy(x, y);   puts(c);     //x,y��ǥ�� ���� �� *c ���
					}
					break;

				case RIGHT:        //#define RIGHT �� ���� �� (���������� ������ ��) 

					gotoxy(x++, y); puts(" ");      //���������� ������ ������ *c ���� 
					gotoxy(x, y);   puts(c);      //x,y��ǥ�� ���� �� *c ��� 

					break;
				}
			}
			else {
				gotoxy(30, 15);
				setTextColor(ColorRed);
				cout <<name << "�� ������ ����Ǿ����ϴ�.";
				break;
			}
			
		}
		Sleep(1000);
		
	}
	void print() {
		cout << "fsafdas";
	}
	/*void Start() {
		thread threadM1(moveCharacter("��"));
		thread threadM2(moveCharacter("��"));
	}*/
};

