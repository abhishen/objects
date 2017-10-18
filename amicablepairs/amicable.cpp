#include "amicable.h"

amicable::~amicable() {
	delete[] _array;
}

amicable::amicable(ui number) :_number(number) {
	_array = new ui [number];
	cout << "The following are amicable numbers" << endl;
	int index = 0;
	ui i = 2;
	while(i < number) {
		//if(_array[i] != 1)
		_findFactors(i, index);
		i++;
	}
}

 void amicable::_findFactors(ui& number, int& index) {
	ui root1 = sqrt(number);
	ui sum1 = 1;
	bool flag = false;

	//First find sum of factors
	for (ui i = 2; i <= root1; i++) {
		if (number % i == 0) {
			sum1 += i;
			sum1 += (number / i);
		}
	}

	if (sum1 > number) {
		_array[number] = sum1;
		return;
	} else if (sum1 < number) {
		if (_array[sum1] == number) {
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

	//Check the value against sum in the array.
	if (sum1 <= _number && sum1  && sum != number) {
		cout << setw(2) << index << setw(2) << ":" << setw(2) << sum << " and " << number << endl;
		index++;
	}*/
}