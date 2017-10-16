#include "../util/util.h"

#ifndef AMICABLE_H
#define AMICABLE_H

typedef unsigned int ui;

class amicable {
public:
	amicable(ui number);
	~amicable();
private:
	bool _display;
	ui* _array;
	ui _number;
	void _findFactors(ui number, int& index);

};

#endif