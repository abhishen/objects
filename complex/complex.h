/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
Filename: complex.h
-----------------------------------------------------------------*/
#ifndef complex_h
#define complex_h

#include "../util/util.h"

class complex {
public:
  complex(int x = 0, int y = 0);
  ~complex() ;
  complex(const complex& b) ;
  complex& operator=(const complex& rhs) ; 
  friend bool operator==(const complex& c1,const complex& c2);
  friend bool operator!=(const complex& c1,const complex& c2);
  friend bool operator<(const complex& s1, const complex& s2) ;
  friend ostream& operator<<(ostream& o, const complex& c);
  friend ostream& operator<<(ostream& o, complex* const& c);
  void setxy(int x, int y) {_x = x; _y = y; _release();_buildstring();}
  void getxy(int& x, int &y) const {x = _x; y = _y;} ;
  bool display() const { return _display;}
  static void set_display(bool x) {
    _display = x;
  }

private:
  int _x ;
  int _y ;
  char* _string ;
  static bool _display ; /* ONLY ONCE for all object */
  void _alloc(int l) {
    _string = new char[l]; 
  }
  void _release() {
    delete[] _string; 
  }
  void _copy(const complex& from) ; 
  void _buildstring() ;
};

/*----------------------------------------------------------------
extern functions
-----------------------------------------------------------------*/
extern void print_complex(const complex& c);
extern void print_complex(const complex*& c);
extern void print_complex(complex& c);
extern void print_complex(complex*& c);
extern int complex_larger_compare(const complex& c1, const complex& c2);
extern int complex_smaller_compare(const complex& c1, const complex& c2);
extern int complex_larger_compare(complex* const& c1, complex* const& c2);
extern int complex_smaller_compare(complex* const& c1, complex* const& c2);
extern void delete_complex(complex*& c);
extern int complex_ascending_order(const complex& c1, const complex& c2);
extern int complex_ascending_order(complex* const& c1, complex* const& c2);
extern int complex_descending_order(const complex& c1, const complex& c2);
extern int complex_descending_order(complex* const& c1, complex* const& c2);

#endif

