//���
//- ����bool���͵ķº�����Ϊν��
//- ���operator()����һ����������ΪһԪν�ʣ�����Ϊ��Ԫν��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

//һԪν��
void PredTest01() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	//��������Ĳ���һ���Ƕ�����������GreaterFive()��һ����������
	//��set��map������������������ģ�壬<>�ڴ���ģ������б�ģ������б�Ҫ���������ͣ�������������������
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterFive());
	while (it != v1.end()) {
		cout << *it << endl;
		it = find_if(it+1, v1.end(), GreaterFive());
	}
}

//��Ԫν��
void PredTest02() {
	vector<int> v2;
	v2.push_back(10);
	v2.push_back(50);
	v2.push_back(20);
	v2.push_back(40);
	v2.push_back(30);
	
	sort(v2.begin(), v2.end(), greater<int>());

	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
}


//int main() {
//	//PredTest01();
//	PredTest02();
//	return 0;
//}
