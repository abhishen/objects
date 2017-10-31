/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
Filename: dlist.cpp
compile: g++ ../util/util.cpp ../complex/complex.cpp dlist.cpp
==50764== All heap blocks were freed -- no leaks are possible
-----------------------------------------------------------------*/


/*----------------------------------------------------------------
NOTHING CAN BE CHANGED IN THIS FILE
-----------------------------------------------------------------*/
/*----------------------------------------------------------------
Only includes allowed
-----------------------------------------------------------------*/
#include "dlist.h"
#include "../complex/complex.h"
#include <list>  //FOR STL list. The Standard Template Library's list container is implemented as a doubly linked list
//http://www.cplusplus.com/reference/list/list/

/*----------------------------------------------------------------
Change only here if you need display
-----------------------------------------------------------------*/
static bool verbose = false;

/*----------------------------------------------------------------
printing help
-----------------------------------------------------------------*/
template <typename T>
static void print_help(const char *s, dlist<T>& list) {
  cout << s;
  typename dlist<T>::iterator itt = list.begin();
  while (itt != list.end()) {
    T& p = *(itt);
    cout << p << " ";
    ++itt;
  }
  cout << endl;
}

/*----------------------------------------------------------------
This checks whether gold list is exactly equivalent to your dlist
---------------------------------------------------------------- - */
template <typename T>
void assertlist(list<T>& g, dlist<T>& rg) {
  assert(g.size() == rg.size());
  typename list<T>::iterator itt = g.begin();
  int i = 0;
  while (itt != g.end()) {
    T& cg = *(itt);
    T& crg = rg.get_data(i++); 
    ++itt;
    assert(cg == crg);
  }
}


/*----------------------------------------------------------------
Test the append function of dlists
-----------------------------------------------------------------*/
template <typename T>
static void test_append(list<T>& g, dlist<T>& rg) {
  //append 1000 elements
  for (int i = 0; i < 1000; ++i) {
    T o(i);
    g.push_back(o);
    rg.append(o);
  }
  assertlist(g, rg);
  cout << "Your append function works as expected\n";
}

/*----------------------------------------------------------------
Integer dlist tests
-----------------------------------------------------------------*/
static void test_dlist_of_integers(){
  list<int> g; //GOLD
  dlist<int> rg(verbose,nullptr,int_descending_order); //ROLDGOLD
  test_append(g, rg);
}

/*----------------------------------------------------------------
complex dlist tests
-----------------------------------------------------------------*/
static void test_dlist_of_complex(){
  list<complex> g; //GOLD
  dlist<complex> rg(verbose, nullptr, complex_smaller_compare); //ROLDGOLD
  test_append(g, rg);
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  verbose = false; //Change only here
  complex::set_display(verbose);
  test_dlist_of_integers();
  test_dlist_of_complex();
  return 0;
}

//EOF
