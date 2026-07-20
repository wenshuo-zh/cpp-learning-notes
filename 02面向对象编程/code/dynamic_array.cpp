#include<iostream>
using namespace std;
/*
设计一个动态数组类DynamicArray，能够存储整数。要求实现以下功能：
1.构造函数初始化数组大小(size)为 0，容量（capacity）为一个默认值,数组需要在堆区申请内存。
2.实现拷贝构造函数，复制另一个动态数组的内容。
3.在析构函数中释放动态分配的内存。
4.push_back：添加元素，容量不足时要支持动态扩容(2倍)
5.empty：判断是否为空
6.full：判断是否为满
7.show：打印数组
*/
class DynamicArray {
private:
	int size;
	int capacity;
	int* arr;
public:
	//构造函数
	DynamicArray(int capacity) :size(0), capacity(capacity) {
		this->arr = new int [capacity]();//数组在堆区申请空间，格式：
		//                                                          类型* 指针名 = new 类型[长度]；
		//															类型* 指针名 = new 类型[长度]()； 全零初始化
	}
	//拷贝构造函数（深拷贝）
	DynamicArray(const DynamicArray& d) 
		:size(d.size)
		,capacity(d.capacity)
	{
		this->arr = new int[capacity]();
		for (int i = 0; i < size; i++) {
			arr[i] = d.arr[i];
		}
	}
	//析构函数
	~DynamicArray() {
		delete[] arr;
		arr = nullptr;
	}
	//添加元素
	void push_back(int num){
		
		if (full()) {
			int newcapacity = capacity * 2;
			int* newarr = new int[newcapacity]();
			for (int i = 0; i < size; i++) {
				newarr[i] = arr[i];
			}
			delete[] arr;                               //用new[]申请的数组必须用delete[]释放
			arr = newarr;
			capacity = newcapacity;
		}
		arr[size++] = num;
	}

	//const修饰成员函数 常函数
	//常函数内不可修改成员属性，也不可调用非常函数
	//成员属性声明时加关键字mutable后，在常含数中可以修改
	//常含数和非常函数函数名字相同，参数相同也是函数重载，非常对象优先调用非常函数，常对象只能调用常函数
	
	//判断为空
	bool empty() const {
		return size == 0;	
	}
	//判断为满
	bool full()const {
		return capacity == size;
	}
	//打印动态数组
	void show()const {
		cout << "capacity:" << capacity << " size:" << size << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	DynamicArray arr(1);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.show();
	return 0;
}
