#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person{
public:
	char m_Name[64];
	int m_Age;
};

//������д�ļ�
void test006() {
	ofstream ofs("person.txt", ios::out | ios::binary);
	Person p = { "����", 18 };

	//������д�룺���ݵ�ַתΪconst char*�� �������ݴ�С
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}

//�����ƶ��ļ�
void test007() {
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;
	ifs.close();
}


//int main() {
//	//test006();
//	test007();
//	return 0;
//}