#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

bool myCompare(const int& i, const int& j) {
	return (i > j);
}

void printDeque(deque<int>& d) {
	//sort(d.begin(), d.end(), greater<int>());
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//���˲���
void test0022() {
	deque<int> d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//βɾ
	d1.pop_back();
	printDeque(d1);
	
	//ͷɾ
	d1.pop_front();
	printDeque(d1);
}

//����
void test0023(){
	deque<int> d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);

	printDeque(d1);

	d1.insert(d1.begin() + 1, 1000);
	printDeque(d1);

	d1.insert(d1.begin(), 2, 10000);
	printDeque(d1);

	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);
}

//ɾ��
void test0024() {
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	d1.erase(d1.begin() + 1);
	printDeque(d1);

	/*d1.erase(d1.begin(), d1.end());
	printDeque(d1);*/

	d1.clear();
}

//int main() {
//	//test0022();
//	//test0023();
//	test0024();
//	return 0;
//}