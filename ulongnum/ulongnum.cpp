/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ul.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ulongnum.h"
/*----------------------------------------------------------------

Definition of routines of ul class

WRITE ALL CODE HERE
-----------------------------------------------------------------*/

void ul::_tostring(int number) {
	while (number != 0) {
		_value = number % 10 + '0' + _value;
		number = number / 10;
	}
}


ul::ulongnum(int number, bool display = false) :_display(display), _value("") {
	_tostring(number);
	_length = _value.length();
}


ul::ulongnum(const char* number, bool display = false) : _display(display), _value("") {
	_value = number;
	_length = _value.length();
}


ul::ulongnum(const ul& rhs) {
	cout << "In ulongnum copy constructor" << endl;
	_copy(rhs);
}

void ul::_copy(const ul& rhs) {
	this->_display = rhs._display;
	this->_value = rhs._value;
	this->_length = rhs._length;
}

ul& ul::operator=(const ul& rhs) {
	cout << "In ulongnum equal operator" << endl;
	if (this != &rhs) {
		_copy(rhs);
	}
	return *this;
}

const char& ul::operator[](int i) const {
	if (i < 0 || i > _length + 1) {
		assert(0);
	}
	return _value[i];
}

/*
ul operator+(const ul& u1, const ul& u2) {
	ul temp(u1);
	temp._value = u1._value + u2._value;
	return temp;
}

ul operator+(const ul& u1, int number) {
	ul u2(number);
	return u1 + u2;
}

ul operator+(int number, const ul& u2) {
	ul u1(number);
	return u1 + u2;
}
*/
ostream& operator<<(ostream& o, const ul& number) {
	o << number._value;
	return o;
}

/*bool operator==(const ul& u1, const ul& u2) {
	return (u1._value == u2._value);
}

bool operator==(const ul& u1, int number) {
	ul temp(number);
	return (u1._value == temp._value);
}
*/

//EOF


