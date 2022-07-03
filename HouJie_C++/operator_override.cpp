#include <iostream>

using namespace std;

class Person {
public:
	Person(int age) {
		m_age = new int(age);
	}
	Person() {
		m_age = new int(0);
	}

	~Person() {
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
	}

	//重载赋值运算符
	Person& operator=(const Person& p) {
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);
		return *this;
	}

	int* m_age;
};

class myInteger{
	friend ostream& operator<<(ostream& os, const myInteger& i);
public:
	myInteger() {
		m_num = 0;
	}
	myInteger(int num) : m_num(num) {};

	//前置++运算符重载
	//返回引用类型：++++a
	myInteger& operator++() {
		m_num++;
		return *this;
	}
	//后置++运算符重载
	//和前置区分：占位参数int
	myInteger operator++(int) {
		myInteger temp(this->m_num);
		m_num++;
		return temp;
	}

private:
	int m_num;
};

ostream& operator<<(ostream& os, const myInteger& i) {
	os << i.m_num;
	return os;
}

void test01() {
	myInteger myint(10);
	cout << ++++myint << endl;
	cout << myint << endl;
}

void test02() {
	myInteger myint(10);
	cout << myint++++ << endl;
	cout << myint << endl;
}

void test03() {
	Person p1(10);
	Person p2;
	p2 = p1;
	cout << *p1.m_age << endl;
	cout << *p2.m_age << endl;

}

//int main() {
//	//test01();
//	//test02();
//	test03();
//	return 0;
//}