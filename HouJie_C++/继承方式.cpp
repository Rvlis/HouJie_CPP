#include <iostream>

using namespace std;

class Base {

//类外可以访问，子类可以访问
public:
	int m_A;
//类外访问不到，子类可以访问
protected:
	int m_B;

//类外访问不到，子类访问不到
private:
	int m_C;
};

//公共继承， public->public, protected->protected, private->private
class son1 : public Base {
public:
	void func() {
		m_A = 100; //public, 子类可以访问
		m_B = 100; //protected, 子类 可以访问
		//m_C = 100;	//报错，子类访问不到
	}
};

//保护继承， public->protected, protected->protected, private->private
class son2 : protected Base {
public:
	void func() {
		m_A = 100; //protected, 子类可以访问
		m_B = 100; //protected, 子类可以访问
		//m_C = 100; //报错，子类访问不到
	}
};

//私有继承，public/protected/private -> private
class son3 : private Base {
public:
	void func() {
		m_A = 100; //到子类中变为私有
		m_B = 100; //到子类中变为私有
		//m_C = 100; //报错
	}
};

class grandson3 : public son3 {
public:
	void func() {
		// 全部报错，三个成员在son3中都是私有，子类访问不到
		/*m_A = 100;
		m_B = 100;
		m_C = 100;*/
	}
};


//查看对象模型
//查看命令：cl /d1 reportSingleClassLayout类名 文件名.cpp
class Derived : public Base {
public:
	int m_D;
};

//int main() {
//	return 0;
//}