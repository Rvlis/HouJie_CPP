#include <iostream>

using namespace std;

class Animal {
public:
	int m_Age;
};

class Yang : virtual public Animal {

};

class Tuo : virtual public Animal {

};

class YangTuo : public Yang, public Tuo {
};

void ltest01() {
	YangTuo yt;
	yt.Yang::m_Age = 18;
	yt.Tuo::m_Age = 28;
	cout << yt.m_Age << endl;
}

int main() {
	ltest01();
	return 0;
}