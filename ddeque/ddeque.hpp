/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ddeque.hpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Write all code here
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Constructor
-----------------------------------------------------------------*/
template <typename T>
ddeque<T>::ddeque(bool d): _bSize(0),_fSize(0),_frontQ(false),_backQ(false) {
	if (display()) {
		cout << "In ddeque constructor" << endl;
	}
}

/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
template <typename T>
ddeque<T>::~ddeque() {
	if (display()) {
		cout << "In ddeque destructor" << endl;
	}
	_bSize = 0;
	_fSize = 0;
}


template <typename T>
int ddeque<T>::size() {
	return _bSize + _fSize;
}

template <typename T> 
void ddeque<T>::push_back(T& object) {
	_backQ[_bSize++] = object;
}

template <typename T>
void ddeque<T>::push_front(T& object) {
	_frontQ[_fSize++] = object;
}

template <typename T>
void ddeque<T>::pop_back() {
	--_bSize;
}

template <typename T>
void ddeque<T>::pop_front() {
	--_fSize;
}

template <typename T>
T& ddeque<T>::front() {
	return _frontQ[_fSize];
}

template <typename T>
T& ddeque<T>::back() {
	return _backQ[_bSize];
}

template <typename T>
bool ddeque<T>::empty() {
	return (_isFrontQEmpty() && _isBackQEmpty());
}

template <typename T>
const T& ddeque<T>::operator[](int index) const {
	//If back queue is empty. Use index - 1.
	if (_bSize == 0) {
		//Index has to be in range.
		if (index <= _fSize) {
			return _frontQ[index - 1];
		}
	}
	else if (_fSize == 0) {
	//If front queue is empty, use backQueue starting from end.
		if (index <= _bSize) {
			return _backQ[_bSize - index];
		}
	}
	else {
	//If both are not empty.
		int difference = _bSize - index;
		//If difference is >=0, it means object is in backQueue.
		if (difference >= 0) {
			return _backQ[_bSize - index];
		}
		else {
			//Use abs(difference)-1 as index
			return _frontQ[abs(difference) - 1];
		}

	}

	return -1;
}




//EOF


