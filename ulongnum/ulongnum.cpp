/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ulongnum.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ulongnum.h"
/*----------------------------------------------------------------

Definition of routines of ulongnum class

WRITE ALL CODE HERE
-----------------------------------------------------------------*/
void ulongnum::_tostring(int number) {
	while (number != 0) {
		_value = number % 10 + '0' + _value;
		number = number / 10;
	}
}


ulongnum::ulongnum(int number, bool display = false) :_display(display), _value("") {
	_tostring(number);
}

ulongnum::ulongnum(const char* number, bool display = false) : _display(display), _value("") {
	_value(number);
}

ulongnum::ulongnum(const ulongnum& rhs) {
	_copy(rhs);
}

void ulongnum::_copy(const ulongnum& rhs) {
	_display = rhs._display;
	_value = rhs._value;
}

ulongnum operator+(const ulongnum& u1, const ulongnum& u2) {
	ulongnum temp(u1);
	temp._value = u1._value + u2._value;
	return temp;
}

ulongnum operator+(const ulongnum& u1, int number) {
	ulongnum u2(number);
	return u1 + u2;
}

ulongnum operator+(int number, const ulongnum& u2) {
	ulongnum u1(number);
	return u1 + u2;
}

ostream& operator<<(ostream& o, const ulongnum& number) {
	o << number._value;
	return o;
}

bool operator==(const ulongnum& u1, const ulongnum& u2) {
	return (u1._value == u2._value);
}

bool operator==(const ulongnum& u1, int number) {
	ulongnum temp(number);
	return (u1._value == temp._value);
}

//EOF


