#include <iostream>
#include <fstream> //1.����ͷ�ļ�

using namespace std;

void test004() {
	ofstream ofs; //2.����������
	ofs.open("text.txt", ios::out); //3.ָ����·���ͷ�ʽ
	//4. д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	//5. �ر��ļ�
	ofs.close();
}

//int main() {
//	test004();
//	return 0;
//}