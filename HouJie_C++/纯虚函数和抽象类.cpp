#include <iostream>

using namespace std;

class Base {
public:
	//���麯��
	/*ֻҪ��һ�����麯����������Ϊ������
	�ص㣺
		1. �޷�ʵ����
		2. ����������࣬������д����Ĵ��麯��������Ҳ���ڳ�����*/
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