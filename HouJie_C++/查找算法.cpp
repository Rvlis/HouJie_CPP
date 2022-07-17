#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//内置类型查找
void FindTest01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) v.push_back(i);
	auto it = find(v.begin(), v.end(), 5);
	if (it != v.end()) cout << "Find " << *it << endl;
	else cout << "Not found." << endl;
}

//自定义类型查找
class Person {
public:
	Person(string name, int age) : m_Name(name), m_Age(age) {};

	//自定义类型使用find查找，一定要重载==
	bool operator==(const Person& p) {
		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
	}

	int getAge() { return m_Age; }
	string getName() { return m_Name; }

private:
	string m_Name;
	int m_Age;
};

void FindTest02() {
	Person p1("张三", 20);
	Person p2("李四", 30);
	Person p3("王五", 40);
	Person p4("赵六", 50);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	auto it = find(v.begin(), v.end(), p2);
	if (it != v.end()) {
		cout << "Find" << endl;
	}
	else cout << "Not found." << endl;

	v.push_back(p1);
}

class Greater20 {
public:
	bool operator()(Person& p) {
		return p.getAge() > 20;
	}
};

void FindTest03() {
//find_if: 按条件查找
	vector<Person> v;
	Person p1("张三", 20);
	Person p2("李四", 30);
	Person p3("王五", 40);
	Person p4("赵六", 50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	auto it = find_if(v.begin(), v.end(), Greater20());
	while (it != v.end()) {
		cout << (*it).getName() << endl;
		it = find_if(it + 1, v.end(), Greater20());
	}
}

void FindTest04() {
//adjacent_find: 查找相邻重复元素, 如果面试题中遇到，直接用
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(3);

	auto pos = adjacent_find(v.begin(), v.end());
	if (pos != v.end()) {
		cout << *pos << endl;
	}
	else cout << "Not found." << endl;
}

//int main() {
//	//FindTest01();
//	//FindTest02();
//	//FindTest03();
//	FindTest04();
//	return 0;
//}