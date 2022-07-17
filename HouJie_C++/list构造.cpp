#include <iostream>
#include <list>

using namespace std;

void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test0025() {
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int> L2(L1);
	printList(L2);

	list<int> L3(L1.begin(), L1.end());
	printList(L3);

	list<int> L4(10, 1000);
	printList(L4);

	list<int> L5 = L4;
	printList(L5);

}

//int main() {
//	test0025();
//	return 0;
//}