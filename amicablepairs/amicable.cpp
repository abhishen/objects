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

amicable::amicable(ui number) :_number(number),_primeArray(false),_array(false) {
	_refArray = new bool[number + 1];
	for (ui i = 0; i <= number; i++) {
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
	//Find prime factor
	if (number == 220 || number == 284) {
		cout << "Here" << endl;
	}
	ui root = sqrt(number);
	ui sum1 = 1;
	ui iter = 1;
	_array[number][0] = number;
	int i = 2;
	while (_primeArray[i] <= root) {
		int prime = _primeArray[i];
		//Prime number is a factor
		if (number%prime == 0) {
			//Store that prime number as a factor
			_array[number][iter++] = prime;

			int other = number / prime;
			if (_refArray[other] == true) {
				//If other number is prime.
				_array[number][iter++] = other;
			}
			else {
				//Store that number's prime factors, if they dont already exist in the array.
				int otherIter = 1;
				while (_array[other][otherIter] != 0) {
					bool otherFactorFlag = false;
					int otherFactor = _array[other][otherIter];
					for (int k = 0; k < iter; k++) {
						if (_array[number][k] == otherFactor) {
							otherFactorFlag = true;
							break;
						}
					}
					if (!otherFactorFlag) {
						_array[number][iter++] = otherFactor;
					}
					otherIter++;
				}

				//At this point you have all the factors needed.
				break;
			}
		}
		//Else move to next prime number
		i++;
	}

	//Put 0 at final index.
	_array[number][iter] = 0;

	//Now calculate sum using the prime factor array.
	int id = 1;
	int tempNumber = number;
	while (_array[number][id] != 0) {
		
		//Take prime factor
		int prime = _array[number][id];
		int power = 0;

		
		//Find power
		while (tempNumber%prime == 0) {
			power++;
			tempNumber = tempNumber / prime;
		}

		ui sum2 = 1;

		while (power > 0) {
			sum2 += pow(prime, power);
			power--;
		}

		sum1 = sum1 * sum2;
		id++;
	}

	if (tempNumber > 1) {
		sum1 = sum1 * (number + 1);
	}

	sum1 = sum1 - number;

	
	if (sum1 > number) {
		_map[number] = sum1;
		return;
	}
	else if (sum1 < number) {
		if (_map[sum1] == number) {
			cout << setw(2) << index << setw(2) << ":" << setw(2) << sum1 << " and " << number << endl;
			index++;
		} else {
			return;
		}
	}
}
