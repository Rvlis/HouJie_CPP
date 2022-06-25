#include <iostream>

using namespace std;

namespace rvlis01 {
	void print_hehe() {
		cout << "hehe" << endl;
	}
}

namespace rvlis02 {
	void print_hehe() {
		cout << "hoho" << endl;
	}
}

using namespace rvlis01;

//int main() {
//	print_hehe();
//	rvlis02::print_hehe();
//	return 0;
//}