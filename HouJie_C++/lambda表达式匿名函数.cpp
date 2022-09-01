#include <iostream>
#include <memory>
using namespace std;
//匿名函数格式：
//[捕获列表] (参数列表)->返回类型{
//	函数体
//}(实参)
//捕获列表用于捕获外部参数

class Base {
	virtual void fun() {
		cout << "Base::fun()" << endl;
	}
	int base;
};

int main() {
	cout << sizeof(Base) << endl;
	//auto f1 = [](int a, int b)->int {
	//	return a + b;
	//};
	//cout << f1(1,2) << endl;

	//auto f2 = [](int a) {
	//	return [a](int b) {
	//		return a + b;
	//	};
	//};
	//cout << f2(5)(6) << endl;
	shared_ptr<int> i_p = shared_ptr<int>(new int(10));
	cout << *i_p << endl;
	cout << i_p.use_count() << endl;
	shared_ptr<int> ip2 = i_p;
	cout << ip2.use_count() << ' ' << i_p.use_count() << endl;
	shared_ptr<int> ip3 = shared_ptr<int>(new int(100));
	ip2 = ip3;
	cout << i_p.use_count() << ' ' << ip3.use_count() << endl;
	return 0;
}