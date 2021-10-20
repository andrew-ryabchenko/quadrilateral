#include <iostream>
#include <fstream>
#include "shape.h"
using namespace std;

line sides[4];
line lineData;

int main() {
	char ui;
	ifstream infile("data.txt");
	while (!infile.eof()) {
		for (int i = 0; i < 4; i++) {
			double a, b, c;
			infile >> a >> b >> c;
			lineData.a = a;
			lineData.b = b;
			lineData.c = c;
			sides[i] = lineData;
		}
		shape a(sides);
		a.printName();
	}
	
	infile.close();

	//Prevent automatic closing of the terminal

	cout << "Press q to quit" << endl;

	cin >> ui;

	while (ui != 'q') {
		cin >> ui;
	}
	
	return 0;
}
