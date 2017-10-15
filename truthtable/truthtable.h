#ifndef TRUTHTABLE_H
#define TRUTHTABLE_H

typedef class truthtable {
public:
	truthtable(int number, bool display = false);

private:
	//Matrix used to store the output
	char** _matrix;
	void _build(long long);
	char* _toBinString(long long);
	int _digits;
	bool _display;
	long long _rows;
} tt;






#endif