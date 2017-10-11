/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: str.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has str class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef str_H
#define str_H

#include "../darray/darray.h"

/*----------------------------------------------------------------
Declaration of str class
-----------------------------------------------------------------*/
class str {
public:
   //WRITE CODE HERE
	str();
	str(char c, bool display = false);
	str(const char* c, bool display = false);
	str(const str&);
	str& operator=(const str&);
	void reverse();
	friend int string_compare(const str&, const str&);
	friend ostream& operator <<(ostream&, const str&);
	friend bool operator==(const str& s1, const str& s2);
	friend bool operator!=(const str& s1, const str& s2);
	friend str operator+(char,const str&);
	friend str operator+(const str&, char);
	friend str operator+(const str&, const char*);
	friend str operator+(const str&, const str&);
private:
  bool _display;
  darray <char> _string;
  int _length;
  void _copy(const str&);
  int _getLength();
  //Cannot use any STL OBJECT
  //MUST USE darray 
  //Can have any number of private functions
};

#endif
//EOF

