#include "amicable.h"

amicable::~amicable() {
	delete[] _refArray;
}

void amicable::_sieveMultiples(ui root) {
	ui j = 2;
	while (j <= root ) {
		if (_refArray[j] == true) {
			ui id = j;
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
	ui j = 0;
	for (ui i = 0; i <= _number; i++) {
		if (_refArray[i]) {
			_primeArray[j++] = i;
		}
	}
}

amicable::amicable(ui number) :_number(number),_array(false),_primeArray(false),_power(false) {
	_refArray = new bool[number + 1];
	for (ui i = 0; i <= number; i++) {
		_refArray[i] = true;
	}
	_sieveMultiples(sqrt(number));
	_populatePrimeArray();

	cout << "The following are amicable numbers" << endl;
	int index = 0;
	ui i = 2;
	while(i < number) {
		if(i%6 == 0) { 
			i++; 
			continue; 
		}
		//cout << i << endl;
		_findFactors(i, index);
		i++;
	}
}

ui amicable::_calculateSum(ui number) {
	ui sum = 1;
	ui sum2 = 1;
	ui id = 1;
	ui tempNumber = number;
	while (_array[number][id] != 0) {
		sum = 1;
		//Take prime factor
		ui prime = _array[number][id];
		ui power = _power[number][id];
		
		//While power != 0
		while (power > 0) {
			sum += pow(prime,power);
			power--;
		}

		sum2 = sum2 * sum;

		id++;
	}

//	if (tempNumber > 1) {
	//	sum = sum * (number + 1);
	//}

	return sum2 - number;

}


void amicable::_findFactors(ui number, int& index) {
	if (number == 110) {
		cout << "Here" << endl;
	}
	//Find prime factor
	ui root = sqrt(number);
	ui sum1 = 1;
	ui iter = 1;
	_array[number][0] = 0;
	
	//If number is prime. Store 0 at 1st index and exit.
	if (_refArray[number] == true) {
		//_array[number][1] = 0;
		_array[number][1] = 1;
		_array[number][2] = 0;
		//Store it's power in the power array
		_power[number][1] = 1;
		_power[number][2] = 0;
		return;
	}
	
	ui i = 2;
	while ( _primeArray[i] <= root) {

		ui prime = _primeArray[i];
		//Prime number is a factor
		if (number%prime == 0) {
			//Store that prime number as a factor
			_array[number][iter] = prime;
			//Store it's power at same index
			_power[number][iter++] = _power[prime][1]; 

			ui other = number / prime;
			if (other == prime) {
				_power[number][iter - 1] = 1 + _power[prime][1];
				break;
			}
			if (_refArray[other] == true) {
				//If other number is prime.
				_array[number][iter] = other;
				_power[number][iter++] = _power[other][1];
				//You are done now. The two factors were prime.
				break;
			}
			else {
				//Store other number's prime factors, if they dont already exist in the array.
				ui otherIter = 1;
				//Iterate through other's factors until you reach the end.
				while (_array[other][otherIter] != 0) {
					bool otherFactorFlag = false;
					ui otherFactor = _array[other][otherIter];
					ui k = 0;
					for (k = 0; k < iter; k++) {
						if (_array[number][k] == otherFactor) {
							_power[number][k] = 1 + _power[other][k];
							otherFactorFlag = true;
							break;
						}
					}
					if (!otherFactorFlag) {
						_array[number][iter] = otherFactor;
						_power[number][iter++] = _power[otherFactor][1];
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
	//if(_array[number][0] == -1) return;

	/*
	ui id = 1;
	ui tempNumber = number;
	while (_array[number][id] != 0) {
		
		//Take prime factor
		ui prime = _array[number][id];
		ui power = 0;

		
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

	*/

	sum1 = _calculateSum(number);
	
	
	if( ( sum1%2 == 0 && number%2 != 0 ) || ( sum1%2 != 0 && number%2 == 0 ) ) {
		return;
	}
	
	
	if (sum1 > number) {
		_array[number][0] = sum1;
		return;
	}
	else if (sum1 < number) {
		//if (sum1 % 6 == 0 || number % 6 == 0) return;
		//if( ( sum1%2 == 0 && number%2 != 0 ) || ( sum1%2 != 0 && number%2 == 0 ) )
		if (_array[sum1][0] == number) {
			cout << setw(2) << index << setw(2) << " : " << setw(3) << sum1 << " and " << number << endl;
			index++;
		} else {
			return;
		}
	}
}
