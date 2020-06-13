#include "Date.h"
#include <fstream>
#include<iostream>

using namespace std;

int main() {
	Date d1(13, DECEMBER, 1982);
	d1.Print();
	d1.operator()(2,12,3);
	d1.Print();



	/*d1.operator+=(20);
	d1.Print();*/
	/*++d1;
	d1.Print();*/



	system("pause");
	return 0;
}