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

//template <typename T>
//class ddeque_iterator;

/*--------------------------------------------------------
typename ddeque iterator
----------------------------------------------------------*/
/*
template <typename T>
class ddeque_iterator {
public:
	//WRITE CODE
	ddeque_iterator(T* x = 0) :_current(x) {};
	~ddeque_iterator() {};
	
	const T& operator*() const {
		return *(_current);
	}
	
	ddeque_iterator& operator++() {
		if (!_isBackQEmpty()) {
			--(_current);
		}
		else {

		}
	}
	
	bool operator != (const ddeque_iterator& rhs) {
		return (_current != rhs._current);
	}
private:
  //WRITE CODE
	T* _current;
};
*/
/*--------------------------------------------------------
class ddeque
----------------------------------------------------------*/
template <typename T>
class ddeque {
public:
  /* WRITE ALL PUBLIC FUNCTION HERE */
  /* CANNOT HAVE ANY PUBLIC DATA HERE */
	//friend class ddeque_iterator;
  
	//typedef ddeque_iterator<T> iterator;
	//iterator begin() {};
	//iterator end() {};
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
	bool operator==(T&) const;

  //size(), push_front() push_back() pop_front() pop_back() front() back() a[i]
  //All the above functions must have O(1) time complexity
  //No credit will be given if takes O(n)
  //Write CODE here

	bool display() const { return _display; }
	void set_display(bool x) {
		darray<T>::set_display(x);
		_display = x;
	}

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

