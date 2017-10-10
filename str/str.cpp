/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: str.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "str.h"

/*----------------------------------------------------------------
Definition of routines of str class

WRITE CODE IN THIS FILE
-----------------------------------------------------------------*/

str::str(char c, bool d) :_display(d) {
	int size = 1;
	cout << "In char constructor" << endl;
	//this->_string = darray<char> s;
	for (int i = 0; i < size; i++) {
		_string[i] = c;
	}
	_string[size] = '\0';
	this->_length = size;
}

str::str(const char* c, bool d) :_display(d) {
	int size = strlen(c);
	cout << "In const char* constructor" << endl;
	for (int i = 0; i < size; i++) {
		this->_string[i] = c[i];
	}
	this->_string[size] = '\0';
	this->_length = size;
}

void str::_copy(const str& rhs) {
	this->_length = rhs._length;
	this->_display = rhs._display;
	this->_string = rhs._string;
}

str::str(const str& rhs) {
	cout << "In copy constructor" << endl;
	_copy(rhs);
}

str& str::operator=(const str& rhs) {
	cout << "In = operator" << endl;
	if ((*this) != rhs) {
		_copy(rhs);
	}
	return *this;
}

bool operator==(const str& s1, const str& s2) {
	cout << "In == operator" << endl;
	if (s1._length != s2._length) return false;
	for (int i = 0; i < s1._length; i++) {
		if (s1._string[i] != s2._string[i])
			return false;
	}

	return true;
}

bool operator!=(const str& s1, const str& s2) {
	cout << "In != operator" << endl;
	return !(s1 == s2);
}

str operator+(char c,const str& s) {
	str temp(c, true);
	return temp + s;
}

str operator+(const str& s, char c) {
	str temp(c, true);
	return s + temp;
}

str operator+(const str& s1, const char* s2) {
	str string(s2);
	return s1 + string;
}

str operator+(const str& s1, const str& s2) {
	str result(s1);
	int i = result._length;
	int j = 0;
	while(s2._string[j] != '\0') {
		result._string[i+j] = s2._string[j];
		j++;
	}
	result._string[i + j] = '\0';
	result._length = i + j;
	return result;
}

int string_compare(const str& s1, const str& s2) {
	int ret = 0;
	int i = 0;
	int j = 0;

	while (i < s1._length && j < s2._length) {
		if (s1._string[i] == s2._string[j]) {
			i++;
			j++;
		}
		else if (s1._string[i] < s2._string[j]) {
			return -1;
		}
		else {
			return 1;
		}
	}

	if (i == s1._length && j == s2._length) return 0;
	
	//If j completed first. s1 is longer than s2. Hence lexi smaller.
	if (i < s1._length) return -1;
	//Else s1 is lexi bigger.
	else return 1;
}

ostream& operator<<(ostream& o, const str& s) {
	int i = 0;
	while(s._string[i] != '\0') {
		o << s._string[i];
		i++;
	}

	return o;
}

void str::reverse() {
	int i = 0;
	int j = this->_length - 1;
	int mid = j / 2;
	while(j >= mid) {
		char temp = this->_string[j];
		this->_string[j] = this->_string[i];
		this->_string[i] = temp;
		j--;
		i++;
	}
}




//EOF


