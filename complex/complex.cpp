/*----------------------------------------------------------------
Copyright (c) 2016 Author: Jagadeesh Vasudevamurthy
Filename: complex.cpp
compile: g++ complex.cpp
Memory leaked: 0 bytes
-----------------------------------------------------------------*/
#include "complex.h"

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
bool complex::_display = true;


/*----------------------------------------------------------------
Constructor
-----------------------------------------------------------------*/
complex::complex(int x, int y) :_x(x), _y(y), _string(nullptr){
  if (display()) {
    cout << "in complex constructor:" << endl;
  }
  _buildstring();
}

/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
complex::~complex() {
  if (display()) {
    cout << "In complex Destructor " << _string << endl;
  }
  _release();
}

/*----------------------------------------------------------------
Helper: copy function
-----------------------------------------------------------------*/
void complex::_copy(const complex& from) {
  _x = from._x;
  _y = from._y;
  int l = strlen(from._string) + 1;
  _alloc(l);
  strcpy(_string, from._string);
}

/*----------------------------------------------------------------
Copy constructor
-----------------------------------------------------------------*/
complex::complex(const complex& b){
  if (display()) {
    cout << "In complex copy Constructor " << b._string << endl;
  }
  _copy(b);
}

/*----------------------------------------------------------------
equal operator
-----------------------------------------------------------------*/
complex& complex::operator=(const complex& rhs) {
  if (rhs.display()) {
    cout << "In  complex equal operator " << rhs._string << endl;
  }
  if (this != &rhs) {
    _release();
    _copy(rhs);
  }
  return *this;
}

/*----------------------------------------------------------------
Equal Equal operator
-----------------------------------------------------------------*/
bool operator==(const complex& c1, const complex& c2){
  if (c1.display()) {
    cout << "in complex == operator \n";
  }
  return ((c1._x == c2._x) && (c1._y == c2._y)) ? true : false;
}

/*----------------------------------------------------------------
NOT Equal operator
-----------------------------------------------------------------*/
bool operator!=(const complex& c1, const complex& c2){
  if (c1.display()) {
    cout << "in  complex != operator \n";
  }
  return (!(c1 == c2));
}

/*----------------------------------------------------------------
< operator is used by set,map and hashmap
-----------------------------------------------------------------*/
bool operator<(const complex& s1, const complex& s2) {
  int x1, y1;
  s1.getxy(x1, y1);
  int x2, y2;
  s2.getxy(x2, y2);
  return (x1 < x2) ? true : false;
}

/*----------------------------------------------------------------
Print
-----------------------------------------------------------------*/
ostream& operator<<(ostream& o, const complex& c){
  o << c._string;
  return o;
}

/*----------------------------------------------------------------
Print
-----------------------------------------------------------------*/
ostream& operator<<(ostream& o, complex* const& c){
  return (o << *c);
}

/*----------------------------------------------------------------
build a string from x and y
2, 3 == 2+i3
2,-200 == 2-i200 ;
-2,4 == -2+i4;
-2,-4 == -2-i4;

strlen() returns the length of a string, excluding the null
char *j = "jag" ;
strlen = 3;  j[0] = j j[1] = a j[2] = g ; j[3] = '\0' ;
-----------------------------------------------------------------*/
void complex::_buildstring() {
  char sx[20], sy[20];
  sprintf(sx, "%d", _x);
  char s[20];
  s[0] = '\0';
  strcat(s, sx);
  int m = _y;
  if (_y < 0) {
    m = -(_y);
    strcat(s, "-i");
  }
  else {
    strcat(s, "+i");
  }
  sprintf(sy, "%d", m);
  strcat(s, sy);
  int l = strlen(s) + 1;
  _alloc(l);
  strcpy(_string, s);
}

/*----------------------------------------------------------------
print a complex number
-----------------------------------------------------------------*/
void print_complex(const complex& c){
  cout << c << " ";
}

/*----------------------------------------------------------------
print a complex number
-----------------------------------------------------------------*/
void print_complex(const complex*& c){
  cout << *c << " ";
}

/*----------------------------------------------------------------
print a complex number
-----------------------------------------------------------------*/
void print_complex(complex& c){
  cout << c << " ";
}

/*----------------------------------------------------------------
print a complex number
-----------------------------------------------------------------*/
void print_complex(complex*& c){
  cout << *c << " ";
}

/*----------------------------------------------------------------
c1 > c2
-----------------------------------------------------------------*/
int complex_larger_compare(const complex& c1, const complex& c2){
  int r1, i1, r2, i2;
  c1.getxy(r1, i1);
  c2.getxy(r2, i2);

  if ((r1 == r2) && (i1 == i2)) {
    return 0;
  }
  if ((r1 > r2) && (i1 > i2)) {
    return 1;
  }
  return -1;
}

/*----------------------------------------------------------------
c1 < c2
-----------------------------------------------------------------*/
int complex_smaller_compare(const complex& c1, const complex& c2){
  int x = complex_larger_compare(c1, c2);
  return -x;
}

/*----------------------------------------------------------------
c1 > c2
complex* const& c1
Constant pointer, non constant data
-----------------------------------------------------------------*/
int complex_larger_compare(complex* const& c1, complex* const& c2){
  return (complex_larger_compare(*c1, *c2));
}

/*----------------------------------------------------------------
c1 < c2
complex* const& c1
Constant pointer, non constant data
-----------------------------------------------------------------*/
int complex_smaller_compare(complex* const& c1, complex* const& c2){
  return (complex_smaller_compare(*c1, *c2));
}

/*----------------------------------------------------------------
Delete a complex object
-----------------------------------------------------------------*/
void delete_complex(complex*& c){
  delete(c);
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
int complex_ascending_order(const complex& c1, const complex& c2){
  int r1, i1, r2, i2;
  c1.getxy(r1, i1);
  c2.getxy(r2, i2);
  int x1 = r1 + i1;
  int x2 = r2 + i2;
  if (x1 == x2) {
    return 0;
  }
  if (x1 < x2) {
    return 1;
  }
  return -1;
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
int complex_ascending_order(complex* const& c1, complex* const& c2){
  return (complex_ascending_order(*c1, *c2));
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
int complex_descending_order(const complex& c1, const complex& c2){
  int x = complex_ascending_order(c1, c2);
  return -x;
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
int complex_descending_order(complex* const& c1, complex* const& c2){
  return (complex_descending_order(*c1, *c2));
}


//EOF