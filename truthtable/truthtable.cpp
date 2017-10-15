#include "truthtable.h"
#include "../util/util.h"

truthtable::truthtable(int number, bool display) : _digits(number),_display(display), _rows(1 << number) {
	_build(_rows);
	if (display) {
		for (int i = 0; i < _rows; i++) {
			cout << setw(1) << i << ":" << setw(2) << _matrix[i] << endl;
		}
	}

	cout << "Number of rows for a truth table of" << " " << number << " = " << _rows << endl;
}

void truthtable::_build(long long rows) {
	_matrix = new char*[rows];
	for (long long i = 0; i < rows; i++) {
		_matrix[i] = _toBinString(i);
	}
} 

char* truthtable::_toBinString(long long number) {
	char *binString = new char[_digits];
	binString[_digits] = '\0';
	int i = _digits - 1;
	while (i >= 0) {
		binString[i--] = '0' + (number % 2);
		number = number / 2;
	}
	return binString;
}

