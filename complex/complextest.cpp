/*----------------------------------------------------------------
Copyright (c) 2016 Author: Jagadeesh Vasudevamurthy
Filename: complextest.cpp
compile: g++ complex.cpp complextest.cpp
==27185== All heap blocks were freed -- no leaks are possible
-----------------------------------------------------------------*/
#include "complex.h"

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  complex c1(2,3) ;
  cout << c1 << endl ;
  complex c2(27,-200) ;
  cout << c2 << endl ;
  complex c3(-20,4) ;
  cout << c3 << endl ;
  complex c4(-18, -99) ;
  cout << c4 << endl ;
  c2.setxy(2,3) ;
  cout << c2 << endl ;
  if (c1 == c2) {
    cout << "c1 is equal to c2" << endl ;
  }else {
    cout << "c1 is NOT equal to c2" << endl ;
  }
  if (c1 != c3) {
    cout << "c1 is NOT equal to c3" << endl ;
  }else {
    cout << "c1 is equal to c3" << endl ;
  }

  complex *c5 = new complex(-200,-800) ;
  cout << *c5 << endl ;
  delete c5 ;
  c1 = c2 = c3 = c4 ;
  cout << c3 << endl ;
  return 0 ;
}
