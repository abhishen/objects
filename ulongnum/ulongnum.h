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

private:
  bool _display;
  str _value;
  int _length;
  void _tostring(int);
  friend ostream& operator <<(ostream&, const ulongnum&);
  //Cannot use any STL object
  //must use str object

  //Can have any private functions here
};

#endif
//EOF

