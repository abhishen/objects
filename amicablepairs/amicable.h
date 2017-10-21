#include "../util/util.h"
#include "../darray/darray.h"

#ifndef AMICABLE_H
#define AMICABLE_H

typedef unsigned int ui;

class amicable {
public:
	amicable(ui number);
	~amicable();
private:
	bool _display;
	darray< darray <ui> > _array;
	darray< darray <ui> > _power;
	bool *_refArray;
	darray<int> _primeArray;
	//int* _map;
	ui _number;
	void _findFactors(ui number, int& index);
	void _sieveMultiples(ui);
	void _populatePrimeArray();
	ui _calculateSum(ui);
	//void _findSum(ui &sum, ui prime);
};

#endif
