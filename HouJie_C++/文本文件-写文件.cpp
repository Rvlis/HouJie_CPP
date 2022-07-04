#include <iostream>
#include <fstream> //1.引入头文件

using namespace std;

void test004() {
	ofstream ofs; //2.创建流对象
	ofs.open("text.txt", ios::out); //3.指定打开路径和方式
	//4. 写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	//5. 关闭文件
	ofs.close();
}

//int main() {
//	test004();
//	return 0;
//}