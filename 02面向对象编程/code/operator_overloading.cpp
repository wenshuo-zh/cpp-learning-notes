#include<iostream>
using namespace std;

//复数类，含有实部和虚部两个成员函数
class CComplex {
private:
	int real;
	int imag;
	//int* p = new int();
public:
	CComplex(int real):real(real),imag(0){}
	CComplex(int real,int imag):real(real),imag(imag){}

	void  print()const {
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
	//++前加加重载
	CComplex& operator++() {
		this->real++;
		this->imag++;
		return *this;
	}
	//++后加加重载
	CComplex operator++(int) {                   //为了区分前加加、后加加，在后加加传参数int
		CComplex temp=*this;
		this->real++;
		this->imag++;
		return temp;
	}
	friend ostream& operator<<(ostream& , const CComplex& );
	friend istream& operator>>(istream&,  CComplex&);

	//=赋值运算符重载                       注意自赋值，深拷贝
	CComplex& operator=(const CComplex& c) {
		if (this == &c) {
			//delete p;
			return *this;
		}
		this->real = c.real;
		this->imag = c.imag;
		//this->p = new int(*c.p);
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
//<<与>>运算符重载
ostream& operator<<(ostream& out, const CComplex& c) {
	out << c.real <<"+" << c.imag<<"i" ;
	return out;
}
istream& operator>>(istream& in,  CComplex& c) {
	in >> c.real >> c.imag;
	return in;

}





int main() {
	CComplex c1(10, 20),c2(20,30);

	//operator+
	CComplex c3 = c1 + c2;
	//CComplex c4 = c1.operator+(c2);
	CComplex c4 = 10 + c2;
	c3.print();
	c4.print();

	//operator+=
	c3 += c1;
	c3.print();

	//operator++
	(++++c3).print();
	c3.print();
	(c4++).print();
	c4.print();
	
	//operator>>，operator<<
	cin >>c3>> c4;
	cout << c3 << " " << c4 << endl;

	//operator=
	c2 = c1;
	cout << c2 << endl;
}
