/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ulongnum.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ulongnum class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ulongnum_H
#define ulongnum_H

#include "../str/str.h"

/*--------------------------------------------------------
class ulongnum
----------------------------------------------------------*/
typedef class ulongnum {
public:
  //WRITE CODE HERE
	ulongnum(int number = 0, bool d = false);
	ulongnum(const char*, bool d = false);
	ulongnum(char c, bool d = false);
	ulongnum(const ulongnum&);
	int operator[](int i) const;
	ulongnum& operator=(const ulongnum&);
	friend ostream& operator <<(ostream&, const ulongnum&);
	friend ulongnum operator+(const ulongnum&, const ulongnum&);
	friend ulongnum operator+(const ulongnum&, int);
	friend ulongnum operator+(int, const ulongnum&);
	friend ulongnum operator*(const ulongnum&, const ulongnum&);
	friend ulongnum mult(const ulongnum&, const ulongnum&);
	friend ulongnum operator-(const ulongnum&, const ulongnum&);
	friend bool operator==(const ulongnum&, const ulongnum&);
	friend bool operator==(const ulongnum&, const char*);
	friend bool operator==(const ulongnum&, int);
	void set_display(bool display) { _display = display; }
	void factorial(int);

private:
  bool _display;
  str _value;
//  int _length;
  int _toint(const char&) const;
  str _tostring(int);
  void _copy(const ulongnum&);

  //Cannot use any STL object
  //must use str object

  //Can have any private functions here
} ul;

#endif
//EOF

