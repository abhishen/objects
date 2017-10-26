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
	ddeque_iterator(ddeque<T> &dq, T* x = 0) :_current(x), _obj(dq) {
		cout << T(*x) << endl;
		if (_obj.display()) {
			cout << "In iterator constructor" << endl;
		}
	}
	~ddeque_iterator() {}
	
	T& operator*() {
		return *(_current);
	}

	ddeque_iterator& operator++() {
		//Condition 1.
		//Iterator is in the middle or end of frontQ.
		//Decrement current pointer to point at next element ie. prev element in darray frontQ.
		//if (_current > &(_obj._frontQ[_obj._fStart]) && _current < &(_obj._frontQ[_obj._fSize - 1])) {
		if (_current > &(_obj._frontQ[_obj._fStart]) && _current <= &(_obj._frontQ[_obj._fSize - 1])) {
			--_current;
			return *this;
		}

		//Condition 2.
		//Iterator is at first element in frontQ. Can be 0 or more in frontQ
			//Either backQ is not empty and has elements.
				//Move pointer to 0th position of backQ. Not bStart. fStart and bStart MUST be 0 in this case. Else there is a bug.
			//backQ is empty and iterator is actually at the last position possible
				//Move pointer to end position

		if (_current == &(_obj._frontQ[_obj._fStart]) && _obj._bSize > 0) {
			assert(_obj._fStart == 0);
			assert(_obj._bStart == 0);
			_current = &(_obj._backQ[0]);
			return *this;
		}

		if (_current == &(_obj._frontQ[_obj._fStart]) && _obj._bSize == 0) {
			//Either _fStart can be 0.
			if (_obj._fStart == 0) {
				_current = 0;
				return *this;
			}

			//Or fStart can be in the middle of frontQ
			if (_obj._fStart > 0) {
				//Here cannot assign it to fStart - 1 as there could be an element there.
				_current = 0;
				return *this;
			}
		}

		//Condition 3.
		//Iterator is at the bStart == 0 and rest of backQ is empty.
		//Again assign 0 to pointer. bStart MUST be 0 and bSize MUST be 1 for rest of the backQ to be empty.
		if (_current == &(_obj._backQ[_obj._bStart]) && _obj._bSize == 1) {
			assert(_obj._bStart == 0);
			_current = 0;
			return *this;
		}

		//Condition 4.
		//Iterator is somewhere in backQ
			//Either at bStart or more and less than bSize-1
			//In the last position possible in backQ ie. bSize-1
		if (_current >= &(_obj._backQ[_obj._bStart]) && _current < &(_obj._backQ[_obj._bSize - 1])) {
			++_current;
			return *this;
		}

		if (_current >= &(_obj._backQ[_obj._bStart]) && _current == &(_obj._backQ[_obj._bSize - 1])) {
			_current = 0;
			return *this;
		}
	}

	
	ddeque_iterator& operator--() {
		//Condition 1.
		//Iterator is in the middle or end of backQ.
		//Decrement current pointer to point at prev element ie. prev element in darray backQ.
		if (_current > &(_obj._backQ[_obj._bStart])) {
			--_current;
			return *this;
		}

		//Condition 2.
		//Iterator is at first element in backQ. Can be 0 or more in backQ
			//Either frontQ is not empty and has elements.
				//Move pointer to 0th position of frontQ. Not fStart. fStart and bStart MUST be 0 in this case. Else there is a bug.
			//frontQ is empty and iterator is actually at the first position possible
				//Move pointer to end position

		if (_current == &(_obj._backQ[_obj._bStart]) && _obj._fSize > 0) {
			assert(_obj._fStart == 0);
			assert(_obj._bStart == 0);
			_current = &(_obj._frontQ[0]);
			return *this;
		}

		if (_current == &(_obj._backQ[_obj._fStart]) && _obj._fSize == 0) {
			//Either _bStart can be 0.
			if (_obj._bStart == 0) {
				_current = 0;
				return *this;
			}

			//Or bStart can be in the middle of backQ
			if (_obj._bStart > 0) {
				//Here cannot assign it to bStart - 1 as there could be an element there.
				_current = 0;
				return *this;
			}
		}

		//Condition 3.
		//Iterator is at the fStart == 0 and rest of frontQ is empty.
		//Again assign 0 to pointer. fStart MUST be 0 and fSize MUST be 1 for rest of the frontQ to be empty.
		if (_current == &(_obj._frontQ[_obj._fStart]) && _obj._fSize == 1) {
			assert(_obj._fStart == 0);
			_current = 0;
			return *this;
		}

		//Condition 4.
		//Iterator is somewhere in frontQ
		//Either at fStart or more and less than fSize-1
		//In the last position possible in frontQ ie. first position possible in deque ie. fSize - 1
		if (_current >= &(_obj._frontQ[_obj._fStart]) && _current < &(_obj._frontQ[_obj._fSize - 1])) {
			++_current;
			return *this;
		}

		if (_current >= &(_obj._frontQ[_obj._fStart]) && _current == &(_obj._frontQ[_obj._fSize - 1])) {
			_current = 0;
			return *this;
		}
	}

	bool operator != (const ddeque_iterator& rhs) {
		return (_current != rhs._current);
	}

private:
  //WRITE CODE
	T* _current;
	ddeque <T> _obj;
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
	friend class iterator;
	
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

