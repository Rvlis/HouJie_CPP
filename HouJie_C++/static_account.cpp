#include <iostream>
using namespace std;

class Account {
public:
	static double m_rate;
	static void set_rate(const double& x) { m_rate = x; }
};

double Account::m_rate = 8.0;

/*
int main() {
	Account::set_rate(5);
	Account a;
	cout << a.m_rate << endl;
	a.set_rate(10);
	cout << a.m_rate << endl;
	return 0;
}
*/