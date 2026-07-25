#include<iostream>
using namespace std;

int main(){
  int n; 
	int cnt = 0;
	cin >> n;
	while (n) {
		n = n & (n - 1);  //消除最右侧的一个1
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
