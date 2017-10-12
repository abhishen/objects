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
	ulongnum(int, bool);
	ulongnum(const char*, bool);
	ulongnum(const ulongnum&);
	int operator[](int i) const;
	ulongnum& operator=(const ulongnum&);
	friend ostream& operator <<(ostream&, const ulongnum&);
	friend ulongnum operator+(const ulongnum&, const ulongnum&);
	//friend ulongnum operator+(const ulongnum&, int);
	//friend ulongnum operator+(int, const ulongnum&);
	//friend bool operator==(const ulongnum&, const ulongnum&);
	//friend bool operator==(const ulongnum&, int);

private:
  bool _display;
  str _value;
  int _length;
  int _toint(const char&) const;
  str& _tostring(int);
  void _copy(const ulongnum&);
  
  //Cannot use any STL object
  //must use str object

  //Can have any private functions here
} ul;

#endif
//EOF

