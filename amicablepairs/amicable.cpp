#include "amicable.h"

amicable::~amicable() {
	delete[] _map;
}

amicable::amicable(ui number) :_number(number), _array(number,false) {

	cout << "The following are amicable numbers" << endl;
	int index = 0;
	ui i = 2;
	_map = new ui[number];
	while(i < number) {
		//if(_array[i] != 1)
		_findFactors(i, index);
		i++;
	}
}

 void amicable::_findFactors(ui& number, int& index) {
	ui root1 = sqrt(number);
	ui sum1 = 1;
	ui iter = 1;
	_array[number][0] = 1;
	
	//First find sum of factors
	for (ui i = 2; i <= root1; i++) {
		if (number % i == 0) {
			_array[number][iter++] = i;
			sum1 += i;
			ui j = 1;
			while (_array[i][j] != 0) {
				bool skip = false;
				for (ui k = 0; k < iter; k++) {
					if (_array[number][k] == _array[i][j]) {
						skip = true;
						break;
					}
				}

				if (!skip) {
					_array[number][iter++] = _array[i][j];
					_array[number][iter++] = i * _array[i][j];
					sum1 += _array[i][j] + (i * _array[i][j]);
				}
				j++;
			}

			j = 1;
			while (_array[number / i][j] != 0) {
				bool skip = false;
				for (ui k = 0; k < iter; k++) {
					if (_array[number][k] == _array[number / i][j]) {
						skip = true;
						break;
					}
				}

				if (!skip) {
					_array[number][iter++] = _array[number / i][j];
					_array[number][iter++] = i * _array[number / i][j];
					sum1 += _array[number / i][j] + (i * _array[number / i][j]);
				}
				j++;
			}

			_array[number][iter++] = number / i;
			_array[number][iter] = 0;
			break;
		}
	}

	//Find sum of the factors of sum1

	if (sum1 > number) {
		_map[number] = sum1;
		return;
	}
	else if (sum1 < number) {
		if (_map[sum1] == number) {
			cout << setw(2) << index << setw(2) << ":" << setw(2) << sum1 << " and " << number << endl;
			index++;
		}
		else {
			return;
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
	*/
	//Fill the position of that number in array with the sum
	/*
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

	//Check the value against sum in the array.
	if (sum1 <= _number && sum1  && sum != number) {
		cout << setw(2) << index << setw(2) << ":" << setw(2) << sum << " and " << number << endl;
		index++;
	}*/
}