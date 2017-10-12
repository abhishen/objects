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

/*
Default constructor
*/
str::str() :_string("") {}

/*
Constructor with char
*/

str::str(char c, bool d) :_display(d), _string(2,d) {
	
	int size = 1;
	cout << "In char constructor" << endl;
	//this->_string = darray<char> s;
	_string[0] = c;
	_string[1] = '\0';
	this->_length = size;
}

/*
Constructor with const char ptr 
*/

str::str(const char* c, bool d) :_display(d), _string(strlen(c)+1,d) {
	int size = strlen(c);
	cout << "In const char* constructor" << endl;
	for (int i = 0; i < size; i++) {
		this->_string[i] = c[i];
	}
	this->_string[size] = '\0';
	this->_length = size;
}

/*
Copy constructor util function
*/

void str::_copy(const str& rhs) {
	this->_length = rhs._length;
	this->_display = rhs._display;
	this->_string = rhs._string;
}

/*
Copy constructor
*/

str::str(const str& rhs) {
	cout << "In copy constructor" << endl;
	_copy(rhs);
}

/*
Assignment operator
*/
str& str::operator=(const str& rhs) {
	cout << "In = operator" << endl;
	if ((*this) != rhs) {
		_copy(rhs);
	}
	return *this;
}

/*
[] Operator
*/
const char& str::operator[](int i) const {
	if (i < 0 || i > _length + 1) {
		assert(0);
	}

	return _string[i];
}

/*
= Operator
*/

bool operator==(const str& s1, const str& s2) {
	cout << "In == operator" << endl;
	if (s1._length != s2._length) return false;
	for (int i = 0; i < s1._length; i++) {
		if (s1._string[i] != s2._string[i])
			return false;
	}

	return true;
}

/*
!= Operator
*/

bool operator!=(const str& s1, const str& s2) {
	cout << "In != operator" << endl;
	return !(s1 == s2);
}

/*
char c + str s
*/

str operator+(char c,const str& s) {
	str temp(c, true);
	return temp + s;
}

/*
str s + char c
*/

str operator+(const str& s, char c) {
	str temp(c, true);
	return s + temp;
}

/*
str s1 + "abc"
*/

str operator+(const str& s1, const char* s2) {
	str string(s2);
	return s1 + string;
}

/*
str s1 + str s2
*/

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

/*
Lexicographically compare two strings.
s1 < s2 - -1
s1 > s2 - 1
s1 == s2 - 0
*/

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

/*
Overload cout <<
*/

ostream& operator<<(ostream& o, const str& s) {
	int i = 0;
	while(s._string[i] != '\0') {
		o << s._string[i];
		i++;
	}

	return o;
}

/*
Reverse string
*/

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


