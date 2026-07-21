#include<iostream>
using namespace std;

//复数类，含有实部和虚部两个成员函数
class CComplex {
private:
	int real;
	int imag;
public:
	CComplex(int real):real(real),imag(0){}
	CComplex(int real,int imag):real(real),imag(imag){}

	void const print() {
		cout << real << "+" << imag << "i" << endl;
	}

	// +重载 成员函数
	//CComplex operator+(const CComplex& );
	friend CComplex operator+(const CComplex& , const CComplex& );

	//+=重载
	CComplex& operator+=(const CComplex& c) {     //支持链式调用，返回值要用引用（返回修改后的对象本身）
		this->real = this->real + c.real;
		this->imag = this->imag + c.imag;
		return *this;
	}
};

//CComplex CComplex::operator+(const CComplex& c) {
//	return CComplex(this->real + c.real,this->imag + c.imag);
//}

//+重载 全局作用域下友元重载函数
CComplex operator+(const CComplex& c1,  const CComplex& c2) {
	return CComplex(c1.real + c2.real, c1.imag + c2.imag);
}




int main() {
	CComplex c1(10, 20),c2(20,30);

	//operator+
	CComplex c3 = c1 + c2;
	//CComplex c4 = c1.operator+(c2);
	CComplex c4 = 10 + c2;
	c3.print();
	c4.print();

	c3 += c1;
	c3.print();
}
