#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Base {
	T m;
};

class Derived1 : public Base<int> {

};

template<typename T1, typename T2>
class Derived2 : public Base<T2> {
public:
	Derived2() {
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T1 obj;
};

void test0011() {
	Derived1 d;
}

void test0012() {
	Derived2<int, char> d;
}

//int main() {
//	test0012();
//	return 0;
//}