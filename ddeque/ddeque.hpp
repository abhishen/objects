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
ddeque<T>::ddeque(bool d): _bSize(0),_fSize(0),_frontQ(false),_backQ(false),_fStart(0),_bStart(0) {
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
	if (_fStart == 0) {
		_backQ[_bStart+_bSize] = object;
		++_bSize;
		return;
	}
	else if (_fStart > 0) {
		_frontQ[--_fStart] = object;
		++_fSize;
		return;
	}
}

template <typename T>
void ddeque<T>::push_front(T& object) {
	if (_bStart == 0) {
		_frontQ[_fStart+_fSize] = object;
		++_fSize;
		return;
	}
	else if (_bStart > 0) {
		_backQ[--_bStart] = object;
		++_bSize;
		return;
	}
}

template <typename T>
void ddeque<T>::pop_back() {
	if (!_isBackQEmpty()) {
		--_bSize;
		return;
	}
	else if (!_isFrontQEmpty()) {
		++_fStart;
		--_fSize;
		return;
	}
}

template <typename T>
void ddeque<T>::pop_front() {
	if (!_isFrontQEmpty()) {
		--_fSize;
		return;
	}
	else if (!_isBackQEmpty()) {
		++_bStart;
		--_bSize;
		return;
	}
}

template <typename T>
T& ddeque<T>::_front() {
	//If frontQ end pointer is < 0
	if (_fSize == 0) {
		return _backQ[_bStart];
	}
	return _frontQ[_fStart + _fSize - 1];
}

template <typename T>
T& ddeque<T>::front() {
	return _front();
}


template <typename T>
T& ddeque<T>::_back() {
	if (_bSize == 0) {
		return _frontQ[_fStart];
	}
	return _backQ[_bStart + _bSize - 1];
}

template <typename T>
T& ddeque<T>::back() {
	return _back();
}


template <typename T>
bool ddeque<T>::empty() {
	return (_isFrontQEmpty() && _isBackQEmpty());
}



template <typename T>
T& ddeque<T>::operator[](int index) {
	//If back queue is empty. Use front queue starting from end.
	if (index < 0) {
		assert(0);
	}
	
	if (_bSize == 0) {
		//Index has to be in range.
		if (index <= _fSize) {
			return _frontQ[_fStart+_fSize - index - 1];
		}
		else {
		//Out of range
			assert(0);
		}
	}
	else if (_fSize == 0) {
	//If front queue is empty, use backQueue starting from it's first position _bStart.
		if (index <= _bSize) {
			return _backQ[_bStart + index];
		}
		else {
		//Out of range
			assert(0);
		}
	}
	else {
	//If both are not empty.
		int difference = _fSize - 1 - index;
		//If difference is >=0, it means object is in backQueue.
		if (difference >= 0) {
			return _frontQ[difference];
		}
		else {
			//Use abs(difference)-1 as index
			return _backQ[abs(difference) - 1];
		}

	}

	assert(0);
}




//EOF


