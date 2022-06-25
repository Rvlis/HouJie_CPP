#include <iostream>

using namespace std;

class Fraction {
public:
	explicit Fraction(int num, int den = 1) : m_num(num), m_den(den) {}

	Fraction operator+ (const Fraction& f) {
		return Fraction(m_num * f.m_den + f.m_num * m_den, m_den * f.m_den);
	}

	operator double() const {
		return double(m_num) / m_den;
	}

	int get_num() const { return m_num; }
	int get_den() const { return m_den; }
private:
	int m_num;
	int m_den;
};

ostream& operator<<(ostream& os, const Fraction& f) {
	return os << "(" << f.get_num() << "/" << f.get_den() << ")";
}

//int main() {
//	Fraction f(3, 5);
//	//Fraction d2 = f+4;
//	cout << Fraction(4)+f << endl;
//	return 0;
//}