#include<iostream>
using namespace std;
int main() {
	int m, n;	
	cin >> m >> n;
	//辗转相除法（欧几里得算法）找最大公约数（gcd）
	//原理：gcd(a,b) = gcd(b, a mod b) 
	int temp ;
	while(n != 0){ 
		temp = m % n;
		m = n;
		n = temp;
	}
	int gcd = m;
	cout << gcd << endl;


}