#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

void print() {
}
// C++11������
// ����������ģ�����
template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
	cout << firstArg << endl;
	print(args...);
}

//int main() {
//	print(7.5, "hello", bitset<16>(377), 42);
//	
//	//ranged-based for
//	vector<double> vec = { 1.1, 2.2, 3.3, 4.4 };
//	for (auto v : vec) {
//		cout << v << endl;
//	}
//	for (auto& v : vec) {
//		v *= 3;
//	}
//	for (auto v : vec) {
//		cout << v << endl;
//	}
//	return 0;
//}