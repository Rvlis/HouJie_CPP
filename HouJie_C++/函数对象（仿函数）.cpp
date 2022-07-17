//函数对象（仿函数）
//概念：
//- 重载函数调用操作符的类，其对象成为函数对象
//- 函数对象使用重载的（）时，行为类似函数调用，也叫仿函数
//
//本质：
//函数对象（仿函数）是一个类，不是一个函数

#include <iostream>

using namespace std;

//1. 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值

class MyAdd {
public:
	int operator()(int& a, int& b) {
		return a + b;
	}
};

void FTest01() {
	MyAdd myadd;
	int a = 10, b = 10;
	cout << myadd(a, b) << endl;
}

//2. 函数对象超出普通函数的概念，函数对象可以有自己的状态
#include <string>

class MyPrint {
public:
	MyPrint() {
		this->m_count = 0;
	}
	void operator()(string s) {
		cout << s << endl;
		this->m_count++;
	}
	int m_count;
};

void FTest02() {
	MyPrint myprint;
	myprint("Hello");
	myprint("Hello");
	myprint("Hello");
	myprint("Hello");
	cout << myprint.m_count << endl;
}

//3. 函数对象可以作为参数进行传递
void doPrint(MyPrint& m, string s) {
	m(s);
}

void FTest03() {
	MyPrint myprint;
	doPrint(myprint, "hello");
}

//int main() {
//	//FTest01();
//	//FTest02();
//	FTest03();
//	return 0;
//}