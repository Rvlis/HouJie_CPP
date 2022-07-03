#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		m_A = 100;
	}
	void func() {
		cout << "Base: func()����" << endl;
	}

	void func(int a) {
		cout << "Base: func(int a)����" << endl;
	}

	int m_A;
	static int m_SA;
};

//��̬��Ա���ԣ����������������ʼ��
int Base::m_SA = 100;

class Derived : public Base {
public:
	Derived() {
		m_A = 200;
	}

	void func() {
		cout << "Derived func()����" << endl;
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

	//������������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա���������ص����������У��������أ���ͬ����Ա����
	//�������ø�����ͬ����Ա��������Ҫ��������
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