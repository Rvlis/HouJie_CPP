//�������󣨷º�����
//���
//- ���غ������ò��������࣬������Ϊ��������
//- ��������ʹ�����صģ���ʱ����Ϊ���ƺ������ã�Ҳ�зº���
//
//���ʣ�
//�������󣨷º�������һ���࣬����һ������

#include <iostream>

using namespace std;

//1. ����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ

class MyAdd {
public:
	int operator()(int& a, int& b) {
		return a + b;
	}
};

void FTest01() {
	MyAdd myadd;
	int a = 10, b = 10;
	cout << myadd(a, b) << endl;
}

//2. �������󳬳���ͨ�����ĸ����������������Լ���״̬
#include <string>

class MyPrint {
public:
	MyPrint() {
		this->m_count = 0;
	}
	void operator()(string s) {
		cout << s << endl;
		this->m_count++;
	}
	int m_count;
};

void FTest02() {
	MyPrint myprint;
	myprint("Hello");
	myprint("Hello");
	myprint("Hello");
	myprint("Hello");
	cout << myprint.m_count << endl;
}

//3. �������������Ϊ�������д���
void doPrint(MyPrint& m, string s) {
	m(s);
}

void FTest03() {
	MyPrint myprint;
	doPrint(myprint, "hello");
}

//int main() {
//	//FTest01();
//	//FTest02();
//	FTest03();
//	return 0;
//}