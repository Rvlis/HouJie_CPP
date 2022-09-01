#include <iostream>
#include <string>
#include <climits>
using namespace std;

void change(int& ra) {
	
	cout << &ra << endl;
	ra = 20;
	return;
}

static int ga = 10;

//int main() {
//	int a = 10;
//	//int* p = &a;
//	//cout << &p << endl;
//	static int sa = a;
//	cout << a << " " << sa << " " << ga << endl;
//	cout << &a << " " << &sa << " " << &ga << endl;
//}

//int main() {
//	double m = 0, n = 1;
//	try {
//		cout << "before dividing." << endl;
//		if (n == 0) {
//			throw - 1;
//		}
//		else if (m == 0) {
//			throw - 1.0;
//		}
//		else cout << m / n << endl;
//		cout << "after dividing." << endl;
//	}
//	catch (double e) {
//		cout << "catch (double)" << endl;
//	}
//	catch (...) {
//		cout << "catch (...)" << endl;
//	}
//	return 0;
//}

//int main() {
//	cout << INT_MAX << endl;
//	try {
//		char* p = new char[10e11]; //plain new, 空间分配失败时，抛异常，不反悔NULL
//		delete[] p;
//	}
//	catch (const std::bad_alloc& ex) {
//		cout << ex.what() << endl;
//	}
//
//	// nothrow new, 空间分配失败时不抛异常，而是返回NULL
//	char* p = new(nothrow) char[10e11];
//	if (p == NULL) {
//		cout << "alloc failed." << endl;
//	}
//	delete[] p;
//
//	return 0;
//}