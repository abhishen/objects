#include "amicable.h"

amicable::~amicable() {
	delete[] _map;
}

amicable::amicable(ui number) :_number(number),_array(false) {

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
	
	ui root1 = sqrt(number);
	ui sum1 = 1;
	ui iter = 1;
	_array[number][0] = number;
	
	//First find sum of factors
	for (ui i = 2; i <= root1; i++) {
		if (number % i == 0) {
			//Store that factor
			_array[number][iter++] = i;
			_array[number][iter++] = number / i;
			sum1 += i + (number/i);

			//Iterate through factor's factors. Insert if they don't already exist in number's factor-list.
			ui j = 1;
			while (_array[i][j] != 0) {
				bool iFactorFlag = false;
				bool iiFactorFlag = false;

				int iFactor = _array[i][j];
				int iiFactor = i * _array[i][j];

				for (ui k = 0; k < iter; k++) {
					if (_array[number][k] == iFactor) {
						iFactorFlag = true;
						break;
					}
				}

				for (ui k = 0; k < iter; k++) {
					if (_array[number][k] == iiFactor) {
						iiFactorFlag = true;
						break;
					}
				}

				if (!iFactorFlag) {
					_array[number][iter++] = iFactor;
					sum1 += iFactor;
				}

				if (!iiFactorFlag) {
					_array[number][iter++] = iiFactor;
					sum1 += iiFactor;
				}

				j++;
			}

			//Iterate through number/factor's factors.
			j = 1;
			while (_array[number/i][j] != 0) {
				bool iFactorFlag = false;
				bool iiFactorFlag = false;

				int iFactor = _array[number/i][j];
				int iiFactor = i * _array[number/i][j];

				for (ui k = 0; k < iter; k++) {
					if (_array[number][k] == iFactor) {
						iFactorFlag = true;
						break;
					}
				}

				for (ui k = 0; k < iter; k++) {
					if (_array[number][k] == iiFactor) {
						iiFactorFlag = true;
						break;
					}
				}

				if (!iFactorFlag) {
					_array[number][iter++] = iFactor;
					sum1 += iFactor;
				}

				if (!iiFactorFlag) {
					_array[number][iter++] = iiFactor;
					sum1 += iiFactor;
				}

				j++;
			}

			break;
		}
	}

	_array[number][iter] = 0;
	//Find sum of the factors of sum1
	/*
	for (ui i = 2; i <= root1; i++) {
		if (number % i == 0) {
			sum1 += i;
			sum1 += number / i;
		}
	}


	if (sum1 > number) {
		return;
	}

	*/
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
	/*

	ui sum2 = 1;
	ui root2 = sqrt(sum1);
	for (ui i = 2; i <= root2; i++) {
		if (sum1%i == 0) {
			sum2 += i;
			sum2 += (sum1 / i);
		}
	}

	//Fill the position of that number in array with the sum
	

	if (number == sum2 && sum1 != sum2) {
		ui a = ((number < sum1) ? number : sum1);
		ui b = ((a == number) ? sum1 : number);
		//_array[a] = 1;
		//_array[b] = 1;
		//int i = 2;
		//while (i*a < _number && i*b < _number) {
			//_array[i*a] = 1;
			//_array[i*b] = 1;
			//i++;
		//}
		cout << setw(2) << index << setw(2) << ":" << setw(2) << a << " and " << b << endl;
		index++;
		//number = sum1;
	}
	*/
	//Check the value against sum in the array.
	

	/*
	if (sum1 <= _number && sum1 != number) {
		cout << setw(2) << index << setw(2) << ":" << setw(2) << sum1 << " and " << number << endl;
		index++;
	}
	*/
