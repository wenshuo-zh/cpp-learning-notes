#include<iostream>
using namespace std;

//复数类，含有实部和虚部两个成员函数
class CComplex {
private:
	int real;
	int imag;
public:
	CComplex(){}
	CComplex(int real):real(real){}
	CComplex(int real,int imag):real(real),imag(imag){}

	void printf() {
		cout << real << "+" << imag << "i" << endl;
	}
	CComplex operator+(const CComplex& c);
};
CComplex CComplex::operator+(const CComplex& c) {
	return CComplex(this->real + c.real,this->imag + c.imag);
}

int main() {
	CComplex c1(10, 20),c2(20,30);

	//operator+
	CComplex c3 = c1 + c2;
	CComplex c4 = c1.operator+(c2);
	c3.printf();
	c4.printf();


}
