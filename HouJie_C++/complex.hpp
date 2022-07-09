//guard(防卫式声明)
#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>
#include <iostream>


template<typename T> class complex {
public:
	complex(T r = 0, T i = 0) :re(r), im(i) {}
	// 以下构造函数重载不可，因为上面已经存在默认值
	// complex(): re(0), im(0) {}	//重载，overloading
	complex<T>& operator += (const complex<T>&);
	T real() const { return re; }
	T imag() const { return im; }
private:
	T re, im;

	template<typename T>
	friend complex<T>& __doapl(complex<T>*, const complex<T>&);
};

template<typename T>
inline complex<T>& __doapl(complex<T>* ths, const complex<T>& r) {
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

template<typename T>
inline complex<T>& complex<T>::operator += (const complex<T>& r) {
	return __doapl(this, r);
}

template<typename T>
inline T imag(const complex<T>& x) {
	return x.imag();
}

template<typename T>
inline T real(const complex<T>& x) {
	return x.real();
}

template<typename T>
inline complex<T> operator + (const complex<T>& x, const complex<T>& y) {
	return complex<T>(real(x) + real(y), imag(x) + imag(y));
}

template<typename T>
inline complex<T> operator +(const complex<T>& x, T y) {
	return complex<T>(real(x) + y, imag(y));
}

template<typename T>
inline complex<T> operator +(T x, const complex<T>& y) {
	return complex<T>(x + real(y), imag(y));
}

template<typename T>
inline complex<T> operator +(const complex<T>& x) {
	return x;
}

template<typename T>
inline complex<T> operator -(const complex<T>& x) {
	return complex<T>(-real(x), -imag(x));
}

template<typename T>
inline bool operator == (const complex<T>& x, const complex<T>& y) {
	return real(x) == real(y) && imag(x) == imag(y);
}

template<typename T>
inline bool operator == (const complex<T>& x, T y) {
	return real(x) == y && imag(x) == 0;
}

template<typename T>
inline bool operator == (T x, const complex<T>& y) {
	return x == real(y) && imag(y) == 0;
}

template<typename T>
inline bool operator != (const complex<T>& x, const complex<T>& y) {
	return real(x) != real(y) || imag(x) != imag(y);
}

template<typename T>
inline bool operator != (const complex<T>& x, T y) {
	return real(x) != y || imag(x) != 0;
}

template<typename T>
inline bool operator != (T x, const complex<T>& y) {
	return x != real(y) || imag(y) != 0;
}


template<typename T>
inline complex<T> conj(const complex<T>& x) {
	return complex<T>(real(x), -imag(x));
}

template<typename T>
std::ostream& operator << (std::ostream& os, const complex<T>& x) {
	return os << '(' << real(x) << ',' << imag(x) << ')';
}

#endif
