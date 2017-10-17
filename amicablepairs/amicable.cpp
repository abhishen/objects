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
	ui root1 = sqrt(number);
	ui sum1 = 1;
	if (number == 220) {
		cout << "Here" << endl;
	}

	//First find sum of factors
	for (ui i = 2; i <= root1; i++) {
		if (number % i == 0) {
			sum1 += i;
			sum1 += (number / i);
		}
	}

	//Find sum of the factors of sum1
	ui sum2 = 1;
	ui root2 = sqrt(sum1);
	for (ui i = 2; i <= root2; i++) {
		if (number%i == 0) {
			sum2 += i;
			sum2 += (number / i);
		}
	}

	//Fill the position of that number in array with the sum
	
	if (sum1 == sum2) {
			cout << setw(2) << index << setw(2) << ":" << setw(2) << number << " and " << sum2 << endl;
			index++;
	}

	//Check the value against sum in the array.
	/*if (sum1 <= _number && sum1  && sum != number) {
		cout << setw(2) << index << setw(2) << ":" << setw(2) << sum << " and " << number << endl;
		index++;
	}*/
}