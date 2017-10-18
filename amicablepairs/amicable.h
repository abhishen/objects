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
<<<<<<< HEAD
	//ui* _array;
	darray<darray<ui>> _array;
	ui* _map;
=======
	ui* _array;
	ui** _matrix;
>>>>>>> 55a68b86fda6de73c3c7674ed0489c0682efb96d
	ui _number;
	void _findFactors(ui number, int& index);

};

#endif