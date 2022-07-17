#include <iostream>
#include <map>

using namespace std;

void printMap(const map<int, int>& m) {
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << ": " << it->second << endl;
	}
	cout << endl;
}

void mapTest01() {
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40; //不建议用这种方式插入数据: 如果插错数，会将一个没有的数创建为(key，0)存入map中
	//比如直接打印 m[5]，会输出 m[5]=0
	m[4] = 100;

	printMap(m);
	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(4);
	printMap(m);

	m.erase(10);
	printMap(m);

	//m.erase(m.begin(), m.end());
	//printMap(m);

	m.clear();
	printMap(m);
}

class MyCompare {
public:
	bool operator()(int a, int b) const {
		return a > b;
	}
};

//map容器排序，利用仿函数
void mapTest02() {
	map<int, int, MyCompare> mp;
	mp.insert(make_pair(1, 10));
	mp.insert(make_pair(2, 20));
	mp.insert(make_pair(3, 30));
	mp.insert(make_pair(4, 40));
	mp.insert(make_pair(5, 50));
	//printMap(mp);

	for (map<int, int, MyCompare>::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << (*it).first << ": " << it->second << endl;
	}
	cout << endl;

}

//int main() {
//	//mapTest01();
//	mapTest02();
//	return 0;
//}