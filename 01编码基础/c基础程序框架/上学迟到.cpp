#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int s, v;
	cin >> s >> v;
	//因为只能每分钟第0秒出发，所以要向上取整
	int t;
	/*
	if (s % v == 0) t = s / v + 10;
	else t = s / v + 1 + 10;
	*/
	t = ceil(1.0 * s / v) + 10;
	int h = 0;
	int m = 0;

	if (t <= 480) m = 480 - t;
	else m = 24 * 60 - (t - 480);
	
	/*
		while (m > 60) {
			h++;
			m -= 60;
		}
	*/
	h = m / 60;
	m = m % 60;

	printf("%02d:%02d", h,m);
	return 0;
}