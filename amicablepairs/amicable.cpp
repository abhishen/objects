#include "amicable.h"

amicable::~amicable() {
	delete[] _array;
}
amicable::amicable(ui number) :_number(number) {
	_array = new ui [number + 1];
	_array[0] = 0;
	_array[1] = 1;
	cout << "The following are amicable numbers" << endl;
	int index = 0;
	for ( ui i = 2; i <= number; i++) {
		_findFactors(i, index);
	}
}

 void amicable::_findFactors(ui number, int& index) {
	ui root = sqrt(number);
	ui sum = 1;
	//First find sum of factors
	for (ui i = 2; i <= root; i++) {
		if (number % i == 0) {
			sum += i;
			sum += (number / i);
		}
	}

	//Fill the position of that number in array with the sum
	_array[number] = sum;

	//Check the value against sum in the array.
	if (sum <= _number && _array[sum] == number && sum != number) {
		cout << setw(2) << index << setw(2) << ":" << setw(2) << sum << " and " << number << endl;
		index++;
	}
}