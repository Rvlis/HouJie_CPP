#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print01(int val) {
	cout << val << " ";
}

class print02 {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

void ATest01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//for_each������ͨ����ʱ��ֻ��Ҫ���������ɣ���ͨȫ�ֺ����ĺ������Ǹú����ĵ�ַ������ָ�룩
	cout << int(print01) << endl;
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	for_each(v.begin(), v.end(), print02());
}

int Transform(int val) {
	return val+100;
}

void ATest02() {
//transform: ������������һ��������
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int> vTarget;
	vTarget.resize(v.size());

	transform(v.begin(), v.end(), vTarget.begin(), Transform);

	for_each(vTarget.begin(), vTarget.end(), print02());
}

//int main() {
//	//ATest01();
//	ATest02();
//	return 0;
//}