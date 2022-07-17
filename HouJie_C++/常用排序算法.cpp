#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

void MyPrint(int val) {
	cout << val << " ";
}

void STest01() {
	srand(unsigned int(time(NULL)));
//random_shuffle: ϴ�ƣ��������˳��
	vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl;
	random_shuffle(vec.begin(), vec.end());
	for_each(vec.begin(), vec.end(), MyPrint);
}

void STest02() {
	
	//merge: �鲢������������������������ģ������������ϲ�����������Ҳ�������
	vector<int> vec1;
	vector<int> vec2;
	for (int i = 0; i < 10; i++) {
		vec1.push_back(i);
		vec2.push_back(i + 1);
	}
	vector<int> vTarget;
	vTarget.resize(vec1.size() + vec2.size());
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
	cout << endl;

	//reverse:��ת
	reverse(vTarget.begin(), vTarget.end());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
}

//int main() {
//	//STest01();
//	STest02();
//	return 0;
//}