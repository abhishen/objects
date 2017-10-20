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
	darray < darray<int> > _array;
	bool *_refArray;
	darray<int> _primeArray;
	ui* _map;
	ui _number;
	void _findFactors(ui number, int& index);
	void _sieveMultiples(int);
	void _populatePrimeArray();
};

#endif