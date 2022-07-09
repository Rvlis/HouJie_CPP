#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person{
public:
	char m_Name[64];
	int m_Age;
};

//二进制写文件
void test006() {
	ofstream ofs("person.txt", ios::out | ios::binary);
	Person p = { "张三", 18 };

	//二进制写入：数据地址转为const char*， 加上数据大小
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}

//二进制读文件
void test007() {
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
	ifs.close();
}


//int main() {
//	//test006();
//	test007();
//	return 0;
//}