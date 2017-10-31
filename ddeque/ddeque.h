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
	ddeque_iterator(ddeque<T> &dq, T* x = 0) :_current(x) {
		_ifStart = dq._fSize-1;
		_ibStart = dq._bSize-1;
		_iBack = &(dq._backQ[0]);
		_iFront = &(dq._frontQ[0]);
		_ifSize = dq._fSize;
		_ibSize = dq._bSize;
	}
	~ddeque_iterator() {}
	
	T& operator*() {
		return *(_current);
	}

	ddeque_iterator& operator++() {
		//Iterator in frontQ
		if (_ifStart > 0 && _ifStart < _ifSize) {
			--_current;
			--_ifStart;
			return *this;
		}

		//Iterator has reached 0th position
		if (_ifStart == 0) {
			--_ifStart;
			_ibStart = 0;
			_current = _iBack;
			return *this;
		}

		//Iterator in backQ
		if (_ibStart >= 0 && _ibStart < _ibSize) {
			++_current;
			++_ibStart;
			return *this;
		}
	}
	
	ddeque_iterator& operator--() {
		//Iterator in backQ
		if (_ibStart >= 0 && _ibStart < _ibSize) {
			--_current;
			--_ibStart;
			return *this;
		}

		//Iterator has reached 0th position
		if (_ibStart < 0 ) {
			_ifStart = 0;
			_ibStart = _ibSize;
			_current = _iFront;
			return *this;
		}

		//Iterator in frontQ
		if (_ifStart >= 0 && _ifStart < _ifSize) {
			++_current;
			++_ifStart;
			return *this;
		}
	}

	bool operator != (const ddeque_iterator& rhs) {
		return (_current != rhs._current);
	}

private:
  //WRITE CODE
	T* _current;
	T* _iFront;
	T* _iBack;
	int _ifStart;
	int _ibStart;
	int _ifSize;
	int _ibSize;
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
	
	iterator begin() { return iterator(*this, &(_front())); }
	
	iterator end() {
		if (_fStart > 0) {
			return iterator (*this, &_back() - 1);
		}
		else if (_bStart == 0 && _bSize == 0) {
			return iterator (*this, &_back() - 1);
		}
		else {
			return iterator (*this, &_back() + 1);
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

  //size(), push_front() push_back() pop_front() pop_back() front() back() a[i]
  //All the above functions must have O(1) time complexity
  //No credit will be given if takes O(n)
  //Write CODE here

	bool display() const { return _display; }
	void set_display(bool x) {
		darray<T>::set_display(x);
		_display = x;
	}

	friend class ddeque_iterator<T>;


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

	bool _isFrontQEmpty() {
		return _fSize == 0;
	}

	bool _isBackQEmpty() {
		return _bSize == 0;
	}


  /* CAN HAVE ANY PRIVATE FUNCION */
  //void _put(int pos, const T& a);
};

#include "ddeque.hpp"

#endif
//EOF

