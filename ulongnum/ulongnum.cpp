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
	while (number != 1) {
		_value = number % 10 - '0' + _value;
		number = number / 10;
	}
}


ulongnum::ulongnum(int number, bool display = false) :_display(display), _value("") {
	_tostring(number);
}

ulongnum::ulongnum(const char* number, bool display = false) : _display(display), _value("") {
	_value = number;
}

ostream& operator<<(ostream& o, const ulongnum& number) {
	o << number._value;
	return o;
}


//EOF


