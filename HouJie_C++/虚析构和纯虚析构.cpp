#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal构造函数" << endl;
	}

	/*virtual ~Animal() {
		cout << "Animal虚析构函数" << endl;
	}*/

	//Animal纯虚析构
	//纯虚析构函数，既要有声明，也要有实现
	virtual ~Animal() = 0;

	//父类定义虚函数
	virtual void speak() {
		cout << "Animal is speaking." << endl;
	}
};

Animal::~Animal() {
	cout << "Animal纯虚析构函数" << endl;
}


class Cat : public Animal {
public:
	Cat(string name) {
		cout << "Cat 构造函数" << endl;
		m_Name = new string(name);
	}

	//子类重写虚函数
	void speak() {
		cout << *m_Name << " Cat is speaking." << endl;
	}

	~Cat() {
		cout << "Cat析构函数" << endl;
		if (m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}

	string* m_Name;
};

void test003() {
	Animal* animal = new Cat("Tom");
	animal->speak();
	delete animal;
}

//int main() {
//	test003();
//	return 0;
//}