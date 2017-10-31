/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: slisttest.cpp
you require: ../util/util.cpp ../complex/complex.cpp slisttest.cpp
On linux:
g++  ../util/util.cpp ../complex/complex.cpp slisttest.cpp
valgrind a.out
-- All heap blocks were freed -- no leaks are possible
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test slist object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "slist.h"
#include "../complex/complex.h" 

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
//template <typename T>
//
/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = true;

/*----------------------------------------------------------------
printing help
-----------------------------------------------------------------*/
template <typename T>
static void print_help(const char *s, slist<T>& list) {
  cout << s;
  typename slist<T>::iterator itt = list.begin();
  while (itt != list.end()) {
    T& p = *(itt);
    cout << p << " ";
    ++itt;
  }
  cout << endl;
}

/*----------------------------------------------------------------
store int in linked list
-----------------------------------------------------------------*/
static void test_slist_of_integers(){
  const int N = 10;
  //slist<int>::set_display(verbose);
  slist<int> a(NULL, int_descending_order);
  for (int i = 0; i < N; i++) {
    a.append(i);
  }
  print_help("After appending:", a);
  for (int i = 0; i < N; i = i + 2) {
    a.unlink_data(i);
  }
  print_help("After unlinking even items:", a);
  cout << "Printing linked list in reverse order using recusion\n";
 // a.print_in_reverse_order_with_recursion();
  cout << "Printing linked list in reverse order without using recusion\n";
 // a.print_in_reverse_order_without_recursion();
  //a.reverse();
  print_help("After reverse:", a);
  //a.reverse_recur();
  print_help("After reverse recursive:", a);
  bool k = a.find(1);
  if (k) {
    cout << "data 1 is there in the slist. I am going to unlink it \n";
    a.unlink_data(1);
  }
  else {
    cout << "data 1 is NOT there in the slist \n";
  }
  print_help("After unlinking data 1:", a);
  k = a.find(100);
  if (k) {
    a.unlink_data(100);
  }
  print_help("After unlinking data 100:", a);
  k = a.find(9);
  if (k) {
    a.unlink_data(9);
  }
  print_help("After unlinking data 9:", a);
}

/*----------------------------------------------------------------
store UDT in linked list
-----------------------------------------------------------------*/
static void test_slist_of_udt(){
  const int N = 10;
  //set_display(verbose);
  slist<complex> a(NULL, complex_larger_compare);
  complex c;
  for (int i = 0; i < N; i++) {
    c.setxy(i, i);
    a.append(c);
  }

  print_help("After appending:", a);

  for (int i = 0; i < N; i = i + 2) {
    c.setxy(i, i);
    a.unlink_data(c);
  }
  print_help("After unlinking even items:", a);
  //a.reverse();
  print_help("After reverse:", a);
  //a.reverse_recur();
  print_help("After reverse recursive:", a);
  c.setxy(1, 1);
  bool k = a.find(c);
  if (k) {
    cout << "data " << c << " is there in the slist. I am going to unlink it \n";
    a.unlink_data(c);
  }
  else {
    cout << "data " << c << " is NOT there in the slist \n";
  }

  print_help("After unlinking data 1+i1:", a);

  c.setxy(100, 100);
  k = a.find(c);
  if (k) {
    a.unlink_data(c);
  }
  print_help("After unlinking data 100+i100:", a);
  c.setxy(9, 9);
  k = a.find(c);
  if (k) {
    a.unlink_data(c);
  }
  print_help("After unlinking data 9+i9:", a);
}

/*----------------------------------------------------------------
store pointers to UDT in linked list
-----------------------------------------------------------------*/
static void test_slist_of_ptr_to_udt(){
  const int N = 10;
 //set_display(verbose);
  slist<complex*> a(delete_complex, complex_larger_compare); 
  for (int i = 0; i < N; i++) {
    complex* c = new complex(i, i);
    a.append(c);
  }
  print_help("After appending:", a);
  complex c;
  for (int i = 0; i < N; i = i + 2) {
    c.setxy(i, i);
    a.unlink_data(&c);
  }
  print_help("After unlinking even items:", a);
  //a.reverse();
  print_help("After reverse:", a);
  //a.reverse_recur();
  print_help("After reverse recursive:", a);
  c.setxy(1, 1);
  bool k = a.find(&c);
  if (k) {
    cout << "data " << c << " is there in the slist. I am going to unlink it \n";
    a.unlink_data(&c);
  }
  else {
    cout << "data " << c << " is NOT there in the slist \n";
  }
  print_help("After unlinking data 1+i1 ", a);

  c.setxy(100, 100);
  k = a.find(&c);
  if (k) {
    a.unlink_data(&c);
  }
  print_help("After unlinking data 100+i100 ", a);
  c.setxy(9, 9);
  k = a.find(&c);
  if (k) {
    a.unlink_data(&c);
  }
  print_help("After unlinking data 9+i9:", a);
}

/*----------------------------------------------------------------
Detect loop
-----------------------------------------------------------------*/
static void test_loop(){
  const int N = 10;
  //set_display(verbose);
  slist<int> a(NULL, int_descending_order);
  for (int i = 0; i < N; i++) {
    a.append(i);
  }
  print_help("After appending:", a);
  bool p = a.detect_loop();
  if (p) {
    cout << "There is a loop in the list \n";
  }
  else {
    cout << "There is NO loop in the list\n";
  }

  a.create_a_loop(7, 1);
  //print_help("After making a loop:",a) ; -- LOOP FOR EVER
  p = a.detect_loop();
  if (p) {
    cout << "There is a loop in the list \n";
  }
  else {
    cout << "There is NO loop in the list\n";
  }
  //PROGRAM WILL CRASH HERE.
}

/*----------------------------------------------------------------
Properties -> Configuration Properties -> Linker -> System -> Stack Reserve Size 100000000

Run time Without recursion = 0.005 secs
Run time Without recursion = 0.021 secs
----------------------------------------------------------------*/
static void test_reverse(){
  //const int N = 1000000 ; //Stack overflow
  const int N = 500;
 // set_display(verbose);
  slist<int> a(NULL, int_descending_order);
  for (int i = 0; i < N; i++) {
    a.append(i);
  }
  clock_t start1 = clock();
  a.reverse();
  clock_t end1 = clock();
  cout << "Run time Without recursion = " << double(end1 - start1) / CLOCKS_PER_SEC << " secs" << endl;

  clock_t start2 = clock();
  a.reverse_recur();
  clock_t end2 = clock();
  cout << "Run time With recursion = " << double(end2 - start2) / CLOCKS_PER_SEC << " secs" << endl;

}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  complex::set_display(verbose);
 // test_reverse();
  test_slist_of_integers();
  cout << "____________________________" << endl;
  test_slist_of_udt();
  cout << "____________________________" << endl;
  test_slist_of_ptr_to_udt();
  cout << "____________________________" << endl;
  if (0) { //Change to 1 to test. The program crash. But OK
    test_loop();
  }
  cout << "____________________________" << endl;
  return 0;
}

//EOF

