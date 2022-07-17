//概念：
//- 返回bool类型的仿函数成为谓词
//- 如果operator()接受一个参数，称为一元谓词，两个为二元谓词

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

//一元谓词
void PredTest01() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	//函数传入的参数一定是对象，所以这里GreaterFive()是一个匿名对象
	//而set，map是容器，容器本质是模板，<>内传的模板参数列表，模板参数列表要求传数据类型，而类名就是数据类型
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterFive());
	while (it != v1.end()) {
		cout << *it << endl;
		it = find_if(it+1, v1.end(), GreaterFive());
	}
}

//二元谓词
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
