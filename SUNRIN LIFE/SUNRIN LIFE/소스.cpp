#include <iostream>
#include "ConsoleFunctions.h"
#include "map.h"
#include <Windows.h>
#include <stdio.h>
#include "getCursor.h"

using namespace std;



int main() {
	int a;
	system("mode con cols=100 lines=40");
	setCursorType(CursorInvisible);
	map m1;
	getCursor cur;

	m1.mapNum(1);
	//std::cout << "fagfasfsafasd";
	m1.drawMap();
	cur.printCursor();
	/*cout << sizeof("��") << endl;
	for (int i = 0; i < 50; i++) {
		cout <<("��");
	}
	cout << "\n";
	for (int i = 0; i < 50; i++) {
		cout << ("��");
	}*/
	//m1.getBatch();
	
}