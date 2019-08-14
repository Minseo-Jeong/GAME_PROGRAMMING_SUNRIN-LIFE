#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;
class getCursor
{
public:
	int getX() {
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

};

