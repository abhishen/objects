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
	//str();
	str(char c, bool display = false);
	//Changed in class - Better - str(const char ch = '', bool d = false); Take care to pass default arguments for both.
	//It is necessary for implementing a SINGLE + operator.
	str(const char* c, bool display = false);
	str(const str&);
	str& operator=(const str&);
	//Changed in class - const ... [] is only used for read
	const char& operator[](int i) const;
	//Changed in class - Write additional [] to modify for non const object
	//char& operator[](int i);
	void reverse();
	friend int string_compare(const str&, const str&);
	friend ostream& operator <<(ostream&, const str&);
	friend bool operator==(const str& s1, const str& s2);
	friend bool operator!=(const str& s1, const str& s2);

	//Whenever + operation. always return by value. Never reference.
	friend str operator+(char,const str&);
	friend str operator+(const str&, char);
	friend str operator+(const str&, const char*);
	friend str operator+(const str&, const str&);
	//CIC - No need for so many + operators. operator+(const str&, const str&) would have been enough
	str substr(int start, int end);
	int length() const { return _length; };
	//CIC - This wasn't even needed.
	char getCharAt(int index) const { return _string[index]; };
private:
  bool _display;
  darray <char> _string;
  int _length;
  void _copy(const str&);
  //Cannot use any STL OBJECT
  //MUST USE darray 
  //Can have any number of private functions
};

#endif
//EOF

