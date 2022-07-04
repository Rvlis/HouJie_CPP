#include <iostream>

using namespace std;

class Base {
public:
	//纯虚函数
	/*只要有一个纯虚函数，这个类成为抽象类
	特点：
		1. 无法实例化
		2. 抽象类的子类，必须重写父类的纯虚函数，否则也属于抽象类*/
	virtual void func() = 0;
};

class Derived : public Base {
public:
	void func() {
		cout << "func in Derived." << endl;
	}
};

void test001() {
	Base* base = new Derived;
	base->func();
}

void test002() {
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;
}

//int main() {
//	test001();
//	test002();
//	return 0;
//}