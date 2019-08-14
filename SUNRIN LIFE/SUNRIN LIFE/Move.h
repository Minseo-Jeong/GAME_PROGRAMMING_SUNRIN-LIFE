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
		int key;  //������ �� �ʿ��� ���� 
		int x = 0, y = 0;       // x��ǥ, y��ǥ 
		char c[4];
		strcpy_s(c, name.c_str());

		puts(c);

		while (1)
		{
			key = _getch();     // �ڵ��Է� 
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
		
	}

};

