#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		m_A = 100;
	}
	void func() {
		cout << "Base: func()调用" << endl;
	}

	void func(int a) {
		cout << "Base: func(int a)调用" << endl;
	}

	int m_A;
	static int m_SA;
};

//静态成员属性，类内声明，类外初始化
int Base::m_SA = 100;

class Derived : public Base {
public:
	Derived() {
		m_A = 200;
	}

	void func() {
		cout << "Derived func()调用" << endl;
	}

	int m_A;
	static int m_SA;
};

int Derived::m_SA = 200;

void t01() {
	Derived d;
	cout << d.m_A << endl;
	cout << d.Base::m_A << endl;
}

void t02() {
	Derived d;
	d.func();
	d.Base::func();

	//报错：如果子类中出现和父类同名的成员函数，子类的同名成员函数会隐藏掉父类中所有（包含重载）的同名成员函数
	//如果想调用父类中同名成员函数，需要加作用域
	//d.func(10); 
}

void t03() {
	cout << Derived::m_SA << endl;
	cout << Derived::Base::m_SA << endl;
}

//int main() {
//	//t01();
//	//t02();
//	t03();
//	return 0;
//}