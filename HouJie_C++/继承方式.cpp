#include <iostream>

using namespace std;

class Base {

//������Է��ʣ�������Է���
public:
	int m_A;
//������ʲ�����������Է���
protected:
	int m_B;

//������ʲ�����������ʲ���
private:
	int m_C;
};

//�����̳У� public->public, protected->protected, private->private
class son1 : public Base {
public:
	void func() {
		m_A = 100; //public, ������Է���
		m_B = 100; //protected, ���� ���Է���
		//m_C = 100;	//����������ʲ���
	}
};

//�����̳У� public->protected, protected->protected, private->private
class son2 : protected Base {
public:
	void func() {
		m_A = 100; //protected, ������Է���
		m_B = 100; //protected, ������Է���
		//m_C = 100; //����������ʲ���
	}
};

//˽�м̳У�public/protected/private -> private
class son3 : private Base {
public:
	void func() {
		m_A = 100; //�������б�Ϊ˽��
		m_B = 100; //�������б�Ϊ˽��
		//m_C = 100; //����
	}
};

class grandson3 : public son3 {
public:
	void func() {
		// ȫ������������Ա��son3�ж���˽�У�������ʲ���
		/*m_A = 100;
		m_B = 100;
		m_C = 100;*/
	}
};


//�鿴����ģ��
//�鿴���cl /d1 reportSingleClassLayout���� �ļ���.cpp
class Derived : public Base {
public:
	int m_D;
};

//int main() {
//	return 0;
//}