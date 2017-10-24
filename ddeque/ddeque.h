/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ddeque.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ddeque class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ddeque_H
#define ddeque_H

#include "../util/util.h"
#include "../darray/darray.h"

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
template <typename T>
class ddeque;

template <typename T>
class ddeque_iterator;

/*--------------------------------------------------------
typename ddeque iterator
----------------------------------------------------------*/

template <typename T>
class ddeque_iterator {
public:
	//WRITE CODE
	ddeque_iterator(T* x = 0) :_current(x) {};
	~ddeque_iterator() {};
	
	T& operator*() {
		return *(_current);
	}
	
	ddeque_iterator& operator++() {
		//++_current;
		//return *this;

		//Current is in frontQ
		if (_current > &(_frontQ[_fStart])) {
			--_current;
			return *this;
		}

		//Current is at _fStart == 0 and _backQ is empty.
		if (_current == &(_frontQ[_fStart]) && _bSize == 0) {
			//No need to check if _fStart == 0. This will be handled by iterator end().
			_current = &_back() - 1;
			return *this;
		}

		//Current is at _fStart == 0 and _backQ is not empty.
		if (_current == &(_frontQ[_fStart]) && _bSize != 0) {
			_current = _backQ[_bStart];
			return *this;
		}

		//Current is in backQ
		++_current;
		return *this;
	}
		/*if (_fStart > 0 ) {
			//If all elements past frontStart
			_current = &(_back() - 1);
			return *this;
		}
		else if (_bStart == 0 && _bSize == 0) {
			//If elements end at fStart == 0
			_current = &(_back() - 1);
			return *this;
		}
		else {
			//If elements present in backQ
			_current = &(_back() + 1);
			return *this;
		}*/

	
	ddeque_iterator& operator--() {
		//--_current;
		//return *this;

		//Current is in frontQ
		if (_current >= &(_frontQ[_fStart])) {
			++_current;
			return *this;
		}

		//Current is at _bStart == 0 and _frontQ is empty.
		if (_current == &(_backQ[_bStart]) && _fSize == 0) {
			//No need to check if _bStart == 0. This will be handled by iterator end().
			_current = &_front() - 1;
			return *this;
		}

		//Current is at _bStart == 0 and _frontQ is not empty.
		if (_current == &(_backQ[_bStart]) && _fSize != 0) {
			_current = _frontQ[_fStart];
			return *this;
		}

		//Current is in backQ
		--_current;
		return *this;

	}

		/*if (_fStart > 0) {
			//If all elements past frontStart
			_current = &(_back() + 1);
			return *this;
		}
		else if (_bStart == 0 && _bSize == 0) {
			//If elements end at fStart == 0
			_current = &(_back() - 1);
			return *this;
		}
		else {
			//If elements present in backQ
			_current = &(_back() + 1);
			return *this;
		}
	}*/

	
	bool operator != (const ddeque_iterator& rhs) {
		return (_current != rhs._current);
	}
private:
  //WRITE CODE
	T* _current;
};

/*--------------------------------------------------------
class ddeque
----------------------------------------------------------*/
template <typename T>
class ddeque {
public:
  /* WRITE ALL PUBLIC FUNCTION HERE */
  /* CANNOT HAVE ANY PUBLIC DATA HERE */

	typedef ddeque_iterator<T> iterator;
	iterator begin() { return iterator(&(_front())); }
	iterator end() {
		if (_fStart > 0) {
			//If elements end in fQ itself
			return iterator (&_back() - 1);
		}
		else if (_bStart == 0 && _bSize == 0) {
			return iterator (&_back() - 1);
		}
		else {
			return iterator (&_back() + 1);
		}
	}
		
	ddeque(bool d = false);
	~ddeque();
	int size();
	void push_front(T&);
	void push_back(T&);
	void pop_front();
	void pop_back();
	T& front();
	T& back();
	bool empty();
	T& operator[](int i);
	//bool operator==(T&) const;

  //size(), push_front() push_back() pop_front() pop_back() front() back() a[i]
  //All the above functions must have O(1) time complexity
  //No credit will be given if takes O(n)
  //Write CODE here

	bool display() const { return _display; }
	void set_display(bool x) {
		darray<T>::set_display(x);
		_display = x;
	}

	friend class ddeque_iterator <T>;

private:
  /* MUST USE only darray<T>. You can use multiples of darray<T> */
  /* Can have some private variables */
  /* Write Code here */
	darray<T> _frontQ;
	darray<T> _backQ;
	int _bSize;
	int _fSize;
	int _bStart;
	int _fStart;
	T& _front();
	T& _back();

	bool _display;

	int _getFrontQSize() {
		return _fSize;
	}

	int _getBackQSize() {
		return _bSize;
	}
	bool _isFrontQEmpty() {
		return _fSize == 0;
	}

	bool _isBackQEmpty() {
		return _bSize == 0;
	}

  /* CAN HAVE ANY PRIVATE FUNCION */
  void _put(int pos, const T& a);
};

#include "ddeque.hpp"

#endif
//EOF

