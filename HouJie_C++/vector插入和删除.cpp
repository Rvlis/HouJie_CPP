#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test0020() {
	vector<int> v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	printVector(v1);

	//尾删除
	v1.pop_back();
	printVector(v1);

	//插入，位置为迭代器
	v1.insert(v1.begin() + 1, 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//int* val = new int(1000);
	//v1.insert(v1.begin(), val);
	//printVector(v1);

	v1.erase(v1.begin() + 2);
	printVector(v1);

	//v1.clear();
	//printVector(v1);

	vector<int> v2;
	for (int i = 0; i < 100000; i++) {
		v2.push_back(i);
	}
	cout << "v2容量：" << v2.capacity() << endl;
	cout << "v2大小：" << v2.size() << endl;

	v2.resize(3);

	//10w+空间，只利用前三个，造成严重空间浪费
	cout << "v2容量：" << v2.capacity() << endl;
	cout << "v2大小：" << v2.size() << endl;

	//匿名对象
	vector<int>(v2).swap(v2);

	//通过匿名对象，使用swap方法，可以收缩内存空间，匿名对象占用的空间可以被编译器直接回收
	cout << "v2容量：" << v2.capacity() << endl;
	cout << "v2大小：" << v2.size() << endl;

}

void test0021() {
	vector<int> v1;
	int* p = NULL;
	int num = 0;
	//reserve预留空间
	v1.reserve(100000);
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			num++;
		}
	}
	
	//如果不预留，100000个元素大约需要开辟30次，而预留足够空间后，只需要开辟一次
	cout << num << endl;
}

//int main() {
//	//test0020();
//	test0021();
//	return 0;
//}