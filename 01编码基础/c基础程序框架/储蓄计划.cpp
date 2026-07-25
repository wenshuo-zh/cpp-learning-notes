#include<iostream>
using namespace std;

const int N = 20;
int budget[N];

int main() {
	int money = 0;
	int savings = 0;
	for (int i = 1; i <= 12; i++) {
		money += 300;
		cin >> budget[i];
		money -= budget[i];
		if (money < 0) {
			cout << -i;
			return 0;
		}
		while (money >= 100) {
			savings += 100;
			money -= 100;
		}
	}
	cout << savings * 12 / 10 + money;
	return 0;
}