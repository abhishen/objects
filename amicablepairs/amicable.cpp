#include "amicable.h"

amicable::~amicable() {
	delete[] _map;
	delete[] _refArray;
}

void amicable::_sieveMultiples(int root) {
	int j = 2;
	while (j <= root ) {
		if (_refArray[j] == true) {
			int id = j;
			while (id < _number) {
				id = id + j;
				if (id <= _number && _refArray[id] == true) {
					_refArray[id] = false;
				}
			}
		}
		j++;
	}
}

void amicable::_populatePrimeArray() {
	int j = 0;
	for (int i = 0; i <= _number; i++) {
		if (_refArray[i]) {
			_primeArray[j++] = i;
		}
	}
}

amicable::amicable(ui number) :_number(number),_array(false),_primeArray(false) {
	_refArray = new bool[number + 1];
	for (int i = 0; i <= number; i++) {
		_refArray[i] = true;
	}
	_sieveMultiples(sqrt(number));
	_populatePrimeArray();

	cout << "The following are amicable numbers" << endl;
	int index = 0;
	ui i = 2;
	_map = new ui[number];
	while(i < number) {
		_findFactors(i, index);
		i++;
	}
}

void amicable::_findFactors(ui number, int& index) {
	
	ui sum1 = 1;
	ui iter = 1;

	//First find all prime factors and their powers
	ui numberIndex = number;
	ui i = 2;
	while(_primeArray[i] <= sqrt(number)) {
		int primeFactor = _primeArray[i];
		if (number%primeFactor != 0) {
			i++;
			continue;
		}
		int power = 0;
		while (number%primeFactor == 0) {
			//if (_array[number / primeFactor][primeFactor] > 0) {
				//power = 1 + _array[number / primeFactor][primeFactor];
			//}
			//else {
				power++;
				number = number / primeFactor;
			//}
		}
		_array[numberIndex][primeFactor] = power;
		
		int sum2 = 1;
		while (power > 0) {
			sum2 += pow(primeFactor, power);
			power--;
		}

		sum1 = sum1 * sum2;
		i++;
	}

	if (number > 1) {
		sum1 = sum1 * (number + 1);
	}
	sum1 = sum1 - numberIndex;

	if (sum1 > numberIndex) {
		_map[numberIndex] = sum1;
		return;
	}
	else if (sum1 < numberIndex) {
		if (_map[sum1] == numberIndex) {
			cout << setw(2) << index << setw(2) << ":" << setw(2) << sum1 << " and " << numberIndex << endl;
			index++;
		} else {
			return;
		}
	}
}
