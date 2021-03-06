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
//str::str() :_string(), _display(false) {}

/*
Constructor with char
*/

//CIC - Instead of passing char c - passing const char c is a better practice
str::str(char c, bool d) :_display(d), _string(2,d) {
	
	int size = 1;
	//cout << "In char constructor" << endl;
	//this->_string = darray<char> s;
	_string[0] = c;
	_string[1] = '\0';

	//CIC
	/*
	int i = 0;
	if ( c != '') {
		_string[i++] = c;
		}
		_string[i] = '\0';
	*/

	this->_length = size;
}

/*
Constructor with const char ptr 
*/

str::str(const char* c, bool d) :_display(d), _string(strlen(c)+1,d) {
	int size = strlen(c);
	//cout << "In const char* constructor" << endl;
	for (int i = 0; i < size; i++) {
		this->_string[i] = c[i];
	}

	//CIC
	//int i  = 0;
	//while(c[i]) { _string[i] = c[i]; i++ } _string[i] = '\0';
	
	this->_string[size] = '\0';
	this->_length = size;
}

/*
Substring function
*/
str str::substr(int start, int end) {
	if (start < 0 || start > this->_length) {
		assert(0);
	}

	str temp("");
	int last = ((end > this->_length) ? this->_length : end);
	
	for (int i = start; i < last; i++) {
		temp = temp + this->_string[i];
	}

	return temp;
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
//CIC - Need not do anything here. Darray would take care, ALL you need is baseline init
//_display(rhs._display), _str(rhs._str)
str::str(const str& rhs):_length(rhs._length), _display(rhs._display), _string(rhs._string) {
	//cout << "In copy constructor" << endl;
	//CIC - commented
	//_copy(rhs);
}

/*
Assignment operator
*/

//CIC - Again nothing needed here only copy string. _str = rhs._str
str& str::operator=(const str& rhs) {
	//cout << "In = operator" << endl;
	if (this != &rhs) {
		_copy(rhs);
	}
	return *this;
}

/*
[] Operator
*/

//CIC - Overload [] to have a modifiable []
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
	//cout << "In == operator" << endl;
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
	//cout << "In != operator" << endl;
	return !(s1 == s2);
}

/*
char c + str s
*/

str operator+(char c,const str& s) {
	str temp(c);
	int i = 0;
	while(s[i] != '\0') {
		temp._string[temp._length++] = s[i];
		i++;
	}
	temp._string[temp._length] = '\0';
	return temp;
}

/*
str s + char c
*/

str operator+(const str& s, char c) {
	str temp(s);
	temp._string[temp._length++] = c;
	temp._string[temp._length] = '\0';
	return temp;
}

/*
str s1 + "abc"
*/

//This one addition would have been sufficient. All other + would have first called a str constructor and added this. That was kind of my previous implementation.
//Changed it because I thought it causes bottlenecks. It probably isnt the bottle neck
str operator+(const str& s1, const char* s2) {
	str temp(s1);
	int i = 0;
	//CIC - while(s1[i]) { } is better as you dont have to mess around with lngth
	while(i < strlen(s2)) {
		temp._string[temp._length++] = s2[i];
		i++;
	}
	temp._string[temp._length] = '\0';
	return temp;
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
	int mid = (j + 1) / 2;
	while(j >= mid) {
		swap(this->_string[i],this->_string[j]);
		//char temp = this->_string[j];
		//this->_string[j] = this->_string[i];
		//this->_string[i] = temp;
		j--;
		i++;
	}
}


//EOF


