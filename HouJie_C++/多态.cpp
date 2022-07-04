#include <iostream>

using namespace std;

class Animal {
public:
	//父类定义虚函数
	virtual void speak() {
		cout << "Animal is speaking." << endl;
	}
};

class Cat : public Animal {
public:
	//子类重写虚函数
	void speak() {
		cout << "Cat is speaking." << endl;
	}
};

void test01(Animal& animal) {
	animal.speak();
}

//int main() {
//	Cat cat;
//	test01(cat);
//	return 0;
//}