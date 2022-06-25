#include <iostream>

using namespace std;

class Stone {
public:
	Stone(int weight) : _weight(weight) {}
	bool operator<(const Stone& s) {
		return _weight < s._weight;
	}
	int get_weight() const;
private:
	int _weight;
};

inline int Stone::get_weight() const {
	return _weight;
}

// function template
template <typename T>
inline const T& min(T& a, T& b) {
	return a < b ? a : b;
}

inline ostream& operator<< (ostream& os, const Stone& s) {
	return os << s.get_weight();
}

//int main() {
//	/*Stone a(10), b(3);
//	Stone c = min(a, b);
//	cout << c << endl;*/
//
//	return 0;
//}