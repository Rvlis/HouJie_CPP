#include <iostream>
using namespace std;

template<typename T>
class SharedPtr {
public:
	SharedPtr(T* _ptr=nullptr): _ptr(_ptr), _pcount(new int(1)){}
	SharedPtr(const SharedPtr &s): _ptr(s._ptr), _pcount(s._pcount){}
	SharedPtr<T>& operator=(const SharedPtr& s) {
		if (this != &s) {
			if (--(*this)._pcount == 0) {
				delete this->_ptr;
				delete this->_pcount;
			}
			_ptr = s._ptr;
			_pcount = s._pcount;
			*(_pcount)++;
		}
		return *this;
	}

	T& operator*() {
		return *_ptr;
	}

	T* operator->() {
		return _ptr;
	}

	~SharedPtr() {
		--(*_pcount);
		if (*_pcount == 0) {
			delete _ptr;
			_ptr = nullptr;
			delete _pcount;
			_pcount = nullptr;
		}
	}

private:
	T* _ptr;
	int* _pcount;
};