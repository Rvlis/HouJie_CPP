#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

void SetTest01() {
	//set_intersection: �����󽻼������ؽ�����Ŀ�������е����λ�õĵ�������������������ϱ����������
	vector<int> v1, v2;
	vector<int> vTarget;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i); //0~9
		v2.push_back(i + 5); //5~14
	}
	vTarget.resize(min(v1.size(), v2.size()));

	vector<int>::iterator iEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for (auto it = vTarget.begin(); it != iEnd; it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void SetTest02() {
	//set_union: �����󲢼������ز�����Ŀ�������е����λ�õĵ�������������������ϱ����������
	vector<int> v1, v2;
	vector<int> vTarget;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i); //0~9
		v2.push_back(i + 5); //5~14
	}
	vTarget.resize(v1.size()+v2.size());

	vector<int>::iterator iEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for (auto it = vTarget.begin(); it != iEnd; it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void SetTest03() {
	//set_difference: �����������ز��Ŀ�������е����λ�õĵ�������������������ϱ����������
	//v1��v2�Ĳ��ʾv1��ɾ��������ʣ��Ĳ���
	//v2��v1�Ĳ��ʾv2��ɾ��������ʣ��Ĳ���
	vector<int> v1, v2;
	vector<int> vTarget;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i); //0~9
		v2.push_back(i + 5); //5~14
	}
	vTarget.resize(max(v1.size(), v2.size()));

	vector<int>::iterator iEnd1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for (auto it = vTarget.begin(); it != iEnd1; it++) {
		cout << *it << " ";
	}
	cout << endl;
	vTarget.resize(max(v1.size(), v2.size()));

	vector<int>::iterator iEnd2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

	for (auto it = vTarget.begin(); it != iEnd2; it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	//SetTest01();
	//SetTest02();
	SetTest03();
	return 0;
}