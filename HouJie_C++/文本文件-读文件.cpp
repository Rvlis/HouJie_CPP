#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void test005() {
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	
	//�����ݣ�4�֣�
	//��һ��
	/*char buf[1024] = { 0 };
	while (ifs >> buf) {
		cout << buf << endl;
	}*/
	
	//�ڶ���
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))) {
		cout << buf << endl;
	}*/

	//������
	string buf;
	while (getline(ifs, buf)) {
		cout << buf << endl;
	}

	//������
	/*char c;
	while ((c = ifs.get()) != EOF) {
		cout << c;
	}*/

	ifs.close();
}

//int main() {
//	test005();
//	return 0;
//}