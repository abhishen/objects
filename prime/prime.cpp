#include "../util/util.h"
#include "prime.h"

prime::prime(int algos, int range) {
	_initialize(algos,range);
	_calculateBruteMethod(range);
	_calculateUptoPrimeMethod(range);
	_calculateSieveMethod(range);
}

void prime::_initialize(int algos, int range) {
	_algos = algos;
	_range = range;
	
	//Ref Array used for 3rd Algo contains [0,range]
	_refArray = new bool [range+1];
	for(int i = 0; i <= range; i++) {
		_refArray[i] = true;
	}
	_refArray[0] = false;
	_refArray[1] = false;

	_number_of_primes = new int [algos];
	memset(_number_of_primes,0,algos*sizeof(int));

	_number_of_steps = new int [algos];
	memset(_number_of_steps,0,algos*sizeof(int));

	_primeList = new int * [algos];
	for(int i = 0; i < algos; i++) {
		_primeList[i] = new int [range+1];
		for(int j = 0; j <= range; j++) {
			_primeList[i][j] = 0;
		}
	}
}

void prime::_calculateBruteMethod(int range) {
	int steps = 0;
	int j = 2;
	for(int i = 2; i <= range; i++) {
		if(_isPrime(i,steps)) {
			_updatePrimeArray(0);
			_primeList[0][j++] = i;  
		}
	}
	_updateStepsArray(0, steps);
}

void prime::_calculateUptoPrimeMethod(int range) {
	int steps = 0;
	int j = 2;
	int i = 2;

	while(i<=range) {
		int sqrt = _sqrt(i);
		bool result = true;
		_primeList[1][2] = 2;
		
		int *k = _primeList[1] + 2;
		while(*k <= sqrt && *k != 0) {	
			steps++;
			if(i % *k == 0 ) {
				result = false;
				break;
			}
			k++;
		}

		if(result) {
			_primeList[1][j++] = i;
			_updatePrimeArray(1);
		}
		i++;
	}

	_updateStepsArray(1, steps);
}

void prime::_calculateSieveMethod(int range) {
	int steps = 0;
	int i = 2;
	int k = 2;
	int sqrt = _sqrt(range);
	_sieveMultiples(sqrt, steps);
	i++;
	
	int j = 2;
	while(j <= range) {
		if(_refArray[j]) {
			_primeList[2][k++] = j;
			_updatePrimeArray(2);
		}
		j++;
	}
	_updateStepsArray(2, steps);
}

void prime::_sieveMultiples(int sqrt, int& steps) {
	int j = 2;
	while(j <= sqrt) {
		int index = j;
		while(index < _range) {
			index = index + j;
			if(index <= _range && _refArray[index] == true ) {
				steps++;
				_refArray[index] = false;
			}
		}
		j++;
	}
}

void prime::_updatePrimeArray(int algo) {
	this->_number_of_primes[algo]++;
	//cout << algo << " " << _number_of_primes[algo] << endl;
}

void prime::_updateStepsArray(int algo, int steps) {
	this->_number_of_steps[algo] = steps;
}

int prime::number_of_primes(int algo) {
	return _number_of_primes[algo];
}

int prime::number_of_steps(int algo) {
	return _number_of_steps[algo];
}

int prime::get_prime_number(int algo, int kth) {
	return _primeList[algo][kth];
}

int prime::_sqrt(int number) {
	long long low = 0;
	long long high = number;
	while(high - low > 1) {
		long long mid = low + ((high - low) >> 1);
		long long midSq = mid * mid;
		if (midSq <= number) low = mid;
		else high = mid;
	}

	return low;
}

bool prime::_isPrime(int number, int& steps) {
	int sqrt = _sqrt(number);
	int i = 2;
	while(i <= sqrt) {
		steps++;
		if(number < 2) return false;
		if(number % i == 0) {
			return false;
		}
		i++;
	}

	return true;
}

prime::~prime() {
	delete [] _refArray;
	delete [] _number_of_primes;
	delete [] _number_of_steps;

	for(int i = 0; i < _algos; i++) {
		delete [] _primeList[i];
	}

	delete [] _primeList;
}
