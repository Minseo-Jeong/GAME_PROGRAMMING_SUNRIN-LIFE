#include <iostream>
#include "ConsoleFunctions.h"
#include "map.h"
#include <Windows.h>
#include <stdio.h>
#include "getCursor.h"
#include "Move.h"

using namespace std;



int main() {
	int a;
	system("mode con cols=100 lines=40");
	setCursorType(CursorInvisible);
	map m1;
	getCursor cur;
	Move m;

	m1.mapNum(1);

	m1.drawMap();
	cur.printCursor();
	while (1) {
		m.moveCharacter("³ª");
	}
	
	
}