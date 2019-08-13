#include <iostream>
#include "ConsoleFunctions.h"
#include "map.h"
#include <Windows.h>
#include <stdio.h>

using namespace std;

int main() {
	system("mode con cols=100 lines=40");
	map m1;

	m1.mapNum(1);
	//std::cout << "fagfasfsafasd";
	m1.drawMap();
	/*cout << sizeof("бс") << endl;
	for (int i = 0; i < 50; i++) {
		cout <<("бс");
	}
	cout << "\n";
	for (int i = 0; i < 50; i++) {
		cout << ("бс");
	}*/
	m1.getBatch();
	
}