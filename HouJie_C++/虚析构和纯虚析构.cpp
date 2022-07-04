#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal���캯��" << endl;
	}

	/*virtual ~Animal() {
		cout << "Animal����������" << endl;
	}*/

	//Animal��������
	//����������������Ҫ��������ҲҪ��ʵ��
	virtual ~Animal() = 0;

	//���ඨ���麯��
	virtual void speak() {
		cout << "Animal is speaking." << endl;
	}
};

Animal::~Animal() {
	cout << "Animal������������" << endl;
}


class Cat : public Animal {
public:
	Cat(string name) {
		cout << "Cat ���캯��" << endl;
		m_Name = new string(name);
	}

	//������д�麯��
	void speak() {
		cout << *m_Name << " Cat is speaking." << endl;
	}

	~Cat() {
		cout << "Cat��������" << endl;
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