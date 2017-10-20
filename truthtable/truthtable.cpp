#include "truthtable.h"
#include "../util/util.h"

truthtable::truthtable(int number, bool display) : _digits(number),_display(display) {
	_rows = pow(2,number);
	for (long long int i = 0; i < _rows; i++) {
		if(display) {	
			char * binString = _toBinString(i);
			cout << setw(4) << i << setw(3) << ":" << "    " << binString << endl; 
			delete[] binString;
		 } else {
			 _iterateTillZero(i);
		 }
	}

	cout << "Number of rows for a truth table of" << " " << number << " = " << _rows << endl;
}

truthtable::~truthtable() {
}


char* truthtable::_toBinString(long long int number) {
	char *binString = new char[_digits + 1];
	binString[_digits] = '\0';
	long long int i = _digits - 1;
	while (i >= 0) {
		binString[i--] = '0' + (number & 1) ;
		number = number >> 1;
	}
	return binString;
}

void truthtable::_iterateTillZero(long long int number) {
	while(number!=0) {
		number = number >> 1;
	}
	return;
}
