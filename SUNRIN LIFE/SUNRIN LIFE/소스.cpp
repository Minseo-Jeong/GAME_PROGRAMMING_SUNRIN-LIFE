#include <iostream>
#include "ConsoleFunctions.h"
#include "map.h"
#include <Windows.h>
#include <stdio.h>
#include "getCursor.h"
#include "Move.h"
#include <thread>

using namespace std;



int main() {

	system("mode con cols=100 lines=40");
	setCursorType(CursorInvisible);
	string name;
	int a;

	map m1;
	map m2;
	getCursor cur;
	Move m;
	gotoxy(35, 17);
	cout << "난이도를 입력해주세요 1 ~ 5"<<endl;
	gotoxy(35, 18);
	cin >> a;
	gotoxy(35, 19);
	cout << "이름을 입력해주세요 1글자"<<endl;
	gotoxy(35, 20);
	cin >> name;
	system("cls");
	

	m1.mapNum(1);

	m1.drawMap();


	m.moveCharacter(name, 6-a);
}