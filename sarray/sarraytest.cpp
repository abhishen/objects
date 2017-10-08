/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ../complex/complex.cpp sarraytest.cpp

On linux:
g++ ../complex/complex.cpp sarraytest.cpp
valgrind a.out
-- All heap blocks were freed -- no leaks are possible

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
static array test 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "../complex/complex.h"

/*----------------------------------------------------------------
array of integers
-----------------------------------------------------------------*/
void test_array_of_integers(){
  const int N = 5;
  int a[N];
  for (int i = 0; i < N; i++) {
    a[i] = i * 10;
  }
  int b[N];
  //b = a; CANNOT DO:  error C2106: '=' : left operand must be l-value
  for (int i = 0; i < N; i++) {
    b[i] = a[i];
  }
  for (int i = 0; i < N; i++) {
    cout << " b[" << i << "]=" << b[i];
  }
  cout << endl;
  /* this won't work */
  if (a == b) {
    cout << " a eq b " << endl;
  }
  else {
    cout << " a !eq b " << endl;
  }
  bool equal = true;
  for (int i = 0; i < N; i++) {
    if (a[i] != b[i]) {
      equal = false;
      break;
    }
  }
  if (equal) {
    cout << "array a and b is equal\n";
  }
  else {
    cout << "array a and b is NOT equal\n";
  }
}

/*----------------------------------------------------------------
array of integer pointers
-----------------------------------------------------------------*/
void test_array_of_ptr_integers(int n){
  int** a = new int*[n];
  for (int i = 0; i < n; i++) {
    int *p = new int(i * 10);
    a[i] = p;
  }
  int** b = new int*[n];
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
  }
  bool equal = true;
  for (int i = 0; i < n; i++) {
    if (*(a[i]) != *(b[i])) {
      equal = false;
      break;
    }
  }
  if (equal) {
    cout << "array a and b is equal\n";
  }
  else {
    cout << "array a and b is NOT equal\n";
  }
  for (int i = 0; i < n; i++) {
    /* we allocated contents in a. So we delete it */
    delete(a[i]);
  }
  delete [] a;
  /* Why you should NOT do this */
  /*
  for (int i = 0; i < n; i++) {
  delete(b[i]) ;
  }
  */
  delete [] b;
}

/*----------------------------------------------------------------
array of user defined type
-----------------------------------------------------------------*/
void test_array_of_udt(){
  const int N = 5;
  complex a[N];
  for (int i = 0; i < N; i++) {
    a[i].setxy(i, -i);
  }
  complex b[N];
  for (int i = 0; i < N; i++) {
    b[i] = a[i];
  }
  bool equal = true;
  for (int i = 0; i < N; i++) {
    if (a[i] != b[i]) {
      equal = false;
      break;
    }
  }
  if (equal) {
    cout << "array a and b is equal\n";
  }
  else {
    cout << "array a and b is NOT equal\n";
  }
}

/*----------------------------------------------------------------
array of user defined pointer type
-----------------------------------------------------------------*/
void test_array_of_ptr_udt(int n){
  complex** a = new complex*[n];
  for (int i = 0; i < n; i++) {
    complex *c = new complex (i, -i);
    a[i] = c;
  }
  complex** b = new complex*[n];
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
  }
  bool equal = true;
  for (int i = 0; i < n; i++) {
    if (*(a[i]) != *(b[i])) {
      equal = false;
      break;
    }
  }
  if (equal) {
    cout << "array a and b is equal\n";
  }
  else {
    cout << "array a and b is NOT equal\n";
  }
  for (int i = 0; i < n; i++) {
    /* we allocated contents in a. So we delete it */
    delete(a[i]);
  }
  delete[] a;
  /* Why you should NOT do this */
  /*
  for (int i = 0; i < n; i++) {
  delete(b[i]) ;
  }
  */
  delete[] b;
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  test_array_of_integers();
  test_array_of_ptr_integers(5);
  test_array_of_udt();
  test_array_of_ptr_udt(5);
  return 0;
}


//eof
