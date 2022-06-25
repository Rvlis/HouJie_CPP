#define _CRT_SECURE_NO_WARNINGS
#ifndef __MYSTRING__
#define __MYSTRING__

#include <cstring>
#include <iostream>

class String {
public:
	String(const char* cstr = 0);
	String(const String& str);
	String& operator =(const String& str);
	~String();
	char* get_c_str() const { return m_data; }
private:
	char* m_data;
};

inline String::String(const char* cstr) {
	if (cstr) {
		m_data = new char[strlen(cstr) + 1];
		// strcpy报错: 项目-属性- C/C++ -SDL检查：否
		strcpy(m_data, cstr);
	}
	else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline String::String(const String& str) {
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

//拷贝赋值函数
inline String& String::operator=(const String& str) {
	if (this == &str) {
		return *this;
	}
	delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);

	return *this;
}

inline String::~String() {
	delete[] m_data;
}

std::ostream& operator <<(std::ostream& os, const String& str) {
	os << str.get_c_str();
	return os;
}

#endif // !__MYSTRING__
