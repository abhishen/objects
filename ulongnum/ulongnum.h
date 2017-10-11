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
class ulongnum {
public:
  //WRITE CODE HERE
	ulongnum(int, bool);
	ulongnum(const char*, bool);
	ulongnum(const ulongnum&);
	friend ostream& operator <<(ostream&, const ulongnum&);
	friend ulongnum operator+(const ulongnum&, const ulongnum&);
	friend ulongnum operator+(const ulongnum&, int);
	friend ulongnum operator+(int, const ulongnum&);
	friend bool operator==(const ulongnum&, const ulongnum&);
	friend bool operator==(const ulongnum&, int);

private:
  bool _display;
  str _value;

  void _tostring(int);
  void _copy(const ulongnum&);
  
  //Cannot use any STL object
  //must use str object

  //Can have any private functions here
};

#endif
//EOF

