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
	//β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	printVector(v1);

	//βɾ��
	v1.pop_back();
	printVector(v1);

	//���룬λ��Ϊ������
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
	cout << "v2������" << v2.capacity() << endl;
	cout << "v2��С��" << v2.size() << endl;

	v2.resize(3);

	//10w+�ռ䣬ֻ����ǰ������������ؿռ��˷�
	cout << "v2������" << v2.capacity() << endl;
	cout << "v2��С��" << v2.size() << endl;

	//��������
	vector<int>(v2).swap(v2);

	//ͨ����������ʹ��swap���������������ڴ�ռ䣬��������ռ�õĿռ���Ա�������ֱ�ӻ���
	cout << "v2������" << v2.capacity() << endl;
	cout << "v2��С��" << v2.size() << endl;

}

void test0021() {
	vector<int> v1;
	int* p = NULL;
	int num = 0;
	//reserveԤ���ռ�
	v1.reserve(100000);
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			num++;
		}
	}
	
	//�����Ԥ����100000��Ԫ�ش�Լ��Ҫ����30�Σ���Ԥ���㹻�ռ��ֻ��Ҫ����һ��
	cout << num << endl;
}

//int main() {
//	//test0020();
//	test0021();
//	return 0;
//}