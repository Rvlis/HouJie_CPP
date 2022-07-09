#include <iostream>
#include <string>

using namespace std;

template<typename T1, typename T2>
class Person {
public:
	Person(T1 name, T2 age) : m_Name(name), m_Age(age) {};
	T1 m_Name;
	T2 m_Age;
	void showPerson() {
		cout << "����Ϊ��" << m_Name << "������Ϊ��" << m_Age << endl;
	}
};
////1.ָ����������
//void printPerson1(Person<string, int>& p) {
//	p.showPerson();
//}
//
//void test008() {
//	Person<string, int> p("rvlis", 20);
//	printPerson1(p);
//}
//

//2.����ģ�廯
template<typename T1, typename T2>
void printPerson2(Person<T1, T2>& p) {
	p.showPerson();
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;
}

void test009() {
	Person<string, int> p("rvlis", 20);
	printPerson2(p);
}

////3.������ģ�廯
//template<typename T>
//void printPerson3(T& p) {
//	p.showPerson();
//}
//
//void test0010() {
//	Person<string, int> p("rvlis", 20);
//	printPerson3(p);
//}


//int main() {
//	//test008();
//	test009();
//	//test0010();
//	return 0;
//}