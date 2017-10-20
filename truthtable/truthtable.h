#ifndef TRUTHTABLE_H
#define TRUTHTABLE_H

typedef class truthtable {
public:
	truthtable(int number, bool display = false);
	~truthtable();
private:
	char* _toBinString(long long int);
	void _iterateTillZero(long long int);
	long long int _digits;
	bool _display;
	long long int _rows;
} tt;






#endif
