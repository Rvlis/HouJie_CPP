#include <iostream>

using namespace std;

class Animal {
public:
	//���ඨ���麯��
	virtual void speak() {
		cout << "Animal is speaking." << endl;
	}
};

class Cat : public Animal {
public:
	//������д�麯��
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