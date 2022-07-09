#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void test005() {
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	
	//读数据（4种）
	//第一种
	/*char buf[1024] = { 0 };
	while (ifs >> buf) {
		cout << buf << endl;
	}*/
	
	//第二种
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))) {
		cout << buf << endl;
	}*/

	//第三种
	string buf;
	while (getline(ifs, buf)) {
		cout << buf << endl;
	}

	//第四种
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