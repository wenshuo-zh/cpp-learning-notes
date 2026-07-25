#include<iostream>
using namespace std;

bool isLeap(int y) {
	/*
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return true;
	else return false;
	*/
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int main() {
	//闰年：可以被四整除，不能被100整除，或能被400整除
	int year;
	for (int i = 1000; i <= 2000; i+=4) {
		if (isLeap(i)) cout << i << " ";
	}
	return 0;
}