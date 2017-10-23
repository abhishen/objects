/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ../complex/complex.cpp ddequetest.cpp

On linux:
g++ ../complex/complex.cpp ddequetest.cpp
valgrind a.out
valgrind --leak-check=full -v a.out
-- All heap blocks were freed -- no leaks are possible

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test ddeque object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ddeque.h"
#include "../complex/complex.h"
#include <deque> //Gold STL deque

/*--------------------------------------------------------
NOTHING CAN BE CHANGED IN THIS FILE
----------------------------------------------------------*/

/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = false;

/*----------------------------------------------------------------
Multiply integer by 10
-----------------------------------------------------------------*/
static void multiply_by_10(int& x){
  x = x * 10;
}

/*----------------------------------------------------------------
Multiply integer by 10
-----------------------------------------------------------------*/
static void multiply_by_10(int*& x){
  multiply_by_10(*x);
}

/*----------------------------------------------------------------
Multiply complex by 10
-----------------------------------------------------------------*/
static void multiply_by_10(complex& c){
  int x, y;
  c.getxy(x, y);
  x = x * 10;
  y = y * 10;
  c.setxy(x, y);
}

/*----------------------------------------------------------------
Multiply complex pointer by 10
-----------------------------------------------------------------*/
static void multiply_by_10(complex*& c){
  multiply_by_10(*c);
}

/*----------------------------------------------------------------
Print integer
-----------------------------------------------------------------*/
static void print_obj(int& x){
  cout << x << " ";
}

/*----------------------------------------------------------------
print pointer to integer
-----------------------------------------------------------------*/
static void print_obj(int*& x){
  print_obj(*x);
}

/*----------------------------------------------------------------
Print complex
-----------------------------------------------------------------*/
static void print_obj(complex& c){
  cout << c << " ";
}

/*----------------------------------------------------------------
Printcomplex pointer
-----------------------------------------------------------------*/
static void print_obj(complex*& c){
  print_obj(*c);
}


/*----------------------------------------------------------------
compare integer
-----------------------------------------------------------------*/
static bool compare(const int& x, const int& y){
  return (x == y);
}

/*----------------------------------------------------------------
compare integer pointer
-----------------------------------------------------------------*/
static bool compare(int* const& x, int* const& y){
  return compare(*x, *y);
}

/*----------------------------------------------------------------
compare complex
-----------------------------------------------------------------*/
static bool compare(const complex& x, const complex& y){
  return (x == y);
}

/*----------------------------------------------------------------
compare complex pointer
-----------------------------------------------------------------*/
static bool compare(complex* const& x, complex* const& y){
  return (*x == *y);
}



/*----------------------------------------------------------------
construct an integer object
-----------------------------------------------------------------*/
static void construct_an_integer_object(int x, int& o){
  o = x;
}

/*----------------------------------------------------------------
construct a integer* object
-----------------------------------------------------------------*/
static void construct_an_integer_star_object(int x, int*& o){
  o = new(int)(x);
}

/*----------------------------------------------------------------
construct a complex object
-----------------------------------------------------------------*/
static void construct_an_complex_object(int x, complex& o){
  o.setxy(x, -x);
}

/*----------------------------------------------------------------
construct a complex* object
-----------------------------------------------------------------*/
static void construct_an_complex_star_object(int x, complex*& o){
  o = new(complex)(x, -x);
}

/*----------------------------------------------------------------
delete an object
-----------------------------------------------------------------*/
template <typename T>
static void delete_obj(T& a) {
  delete(a);
}


/*----------------------------------------------------------------
swap
-----------------------------------------------------------------*/
template <typename T>
static void swap1(T& a, T& b) {
  T t = a;
  a = b;
  b = t;
}

/*----------------------------------------------------------------
print1
-----------------------------------------------------------------*/
template <typename T>
static void print1(const char* s, ddeque<T>& a, deque<T>& g, bool print = false) {
  cout << s << endl;
  cout << "-----------------" << endl;
  assert(a.size() == g.size());
  cout << "size = " << a.size() << " ";
  cout << endl;
  for (int i = 0; i < int(a.size()); i++) {
    assert(compare(a[i], g[i]));
    if (print) {
      cout << "a[" << i << "] = " << a[i] << " ";
    }
  }
  if (print) {
    cout << endl;
    cout << "-----------------" << endl;
  }
}

/*----------------------------------------------------------------
apply a function pf on elements of ddeque a
-----------------------------------------------------------------*/

/*
template <typename T>
static void apply(const char* s, ddeque<T>& a, deque<T>& g, void(*pf)(T& x)) {
  cout << s << endl;
  cout << "-----------------" << endl;
  typename ddeque<T>::iterator itt = a.begin(); //Note typename here.
  //WILL NOT COMPILE IN LINUX without typename but works on Visual studio
  //Hard to find this solution.
  typename deque<T>::iterator ittg = g.begin();
  while ((itt != a.end()) && (ittg != g.end())){
    T& p = *itt;
    T& pg = *ittg;
    assert(compare(p, pg));
    pf(p);
    pf(pg);
    ++itt;
    ++ittg;
  }
  cout << endl;
}
*/

/*----------------------------------------------------------------
a.front() -- Returns first element of the ddeque
a.back()  -- Returns last  element of the ddeque
a.push_front(v) -- v is inserted as the first element of the ddeque
a.push_back(v) -- v is inserted as the back element of the ddeque
a.pop_front() - First element of the ddeque is removed. Nothing is returned
a.pop_back() - Last element of the ddeque is removed. Nothing is returned
-----------------------------------------------------------------*/
template <typename T>
static void understanding_access(ddeque<T>& a, deque<T>& g, void(*pf)(int x, T& o)) {
  print1("begin with", a, g);
  const int MAX = 1000;
  Random r;
  for (int i = 0; i < MAX; i++){
    T o;
    T og;
    int y = i + 77;
    pf(y, o);
    pf(y, og);
    if (y % 2) {
      //Even number- Push in front
      a.push_back(o);
      g.push_back(og);
    } else {
      //Even number- Push in back
      a.push_front(o);
      g.push_front(og);
    }
  }
  print1("After insertiing 1000 elements", a, g);
  //shuffle now by MAX times

  for (int i = 0; i < MAX; i++){
    int x1 = i;
    int x2 = (7777 - i) % MAX;
    T& o1 = a[x1];
    T& o1g = g[x1];
    assert(compare(o1, o1g));
    T& o2 = a[x2];
    T& o2g = g[x2];
    assert(compare(o2, o2g));
    swap1(a[x1], a[x2]);
    swap1(g[x1], g[x2]);
    assert(compare(a[x1], g[x1]));
    assert(compare(a[x2], g[x2]));
  }
  print1("After Shuffle", a, g);
  T& y = a.front();
  T& yg = g.front();
  assert(compare(y, yg));
  cout << "The front of the ddeque has " << y << endl;
  T& z = a.back();
  T& zg = g.back();
  assert(compare(z, zg));
  cout << "The back of the ddeque has " << z << endl;

  print1("After front and back operation", a, g);

  int x = a.size() - 1;
  assert(compare(a[x], g[x]));
  cout << "Random access of a[" << x << "]= " << a[x] << endl;
}

/*----------------------------------------------------------------
a[0] ..... a[9]

begin() will point to a[0]
end() will NOT POINT to a[9], but to one element past a[9]
That means real end is: end()-1 ;
-----------------------------------------------------------------*/

/*
template <typename T>
static void understanding_iterator(ddeque<T>& a, deque<T>& g, bool display = false) {
  {
    cout << "Understanding forward traversal" << endl;
    typename ddeque<T>::iterator itt = a.begin();
    typename deque<T>::iterator ittg = g.begin();
    while ((itt != a.end()) && (ittg != g.end())) {
      assert(compare(*(itt), *(ittg)));
      if (display) {
        cout << *itt << " ";
      }
      ++itt;
      ++ittg;
    }
    if (display) {
      cout << endl;
    }
  }
  {
    cout << "Understanding reverse traversal" << endl;
    typename ddeque<T>::iterator itt = a.end();
    typename deque<T>::iterator ittg = g.end();
    //cout << *itt << endl ; ----------- CORE DUMPS
    while ((itt != a.begin()) && (ittg != g.begin())) {
      --itt; //decrement iterator before using
      --ittg;
      assert(compare(*(itt), *(ittg)));
      if (display) {
        cout << *itt << " ";
      }
    }
    if (display) {
      cout << endl;
    }
  }
  cout << "-----------------" << endl;
}

*/

/*----------------------------------------------------------------
delete until empty
-----------------------------------------------------------------*/
template <typename T>
static void delete_until_empty(ddeque<T>& a, deque<T>& g, void(*df) (T& c)) {
  cout << "Before deleteing the queue\n";
  bool done = false;
  while (!done) {
    if (a.empty()) {
      assert(g.empty());
      done = true;

    }
    if (g.empty()) {
      assert(a.empty());
      done = true;
    }
    if (done) {
      break;
    } else {
      /* delete back */
      assert(a.size() == g.size());
      T& z = a.back();
      T& zg = g.back();
      assert(compare(z, zg));
      if (df) {
        df(z);
        df(zg);
      }
      a.pop_back();
      g.pop_back();
      assert(a.size() == g.size());
    }
    if (a.empty()) {
      assert(g.empty());
      done = true;

    }
    if (g.empty()) {
      assert(a.empty());
      done = true;
    }
    if (done) {
      break;
    } else {
      /* delete front */
      assert(a.size() == g.size());
      T& z = a.front();
      T& zg = g.front();
      assert(compare(z, zg));
      if (df) {
        df(z);
        df(zg);
      }
      a.pop_front();
      g.pop_front();
      assert(a.size() == g.size());
    }
  }
  cout << "Before deleteing the queue\n";
}


/*----------------------------------------------------------------
test
-----------------------------------------------------------------*/
template <typename T>
static void test(ddeque<T>& a, deque<T>& g, void(*pf)(int x, T& o), void(*df) (T& c)) {
  print1("begin with", a, g);
//  understanding_access(a, g, pf);
  //understanding_iterator(a, g);
 // apply("multiply by 10", a, g, multiply_by_10);
  cout << endl;
  //apply("print using iterator after multiplying by 10", a, g, print_obj);
  cout << endl;
  delete_until_empty(a, g, df);
}


/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  complex::set_display(verbose);
  {
    ddeque<complex> a;
    a.push_back(complex(7, -8));
  }
  {
    //TEST INTEGER
    ddeque<int> a;
    deque<int>  g; //Gold
    test<int>(a, g, construct_an_integer_object, nullptr);
  }
  {
    //TEST pointer to INTEGER
    ddeque<int*> a;
    deque<int*>  g; //Gold
    test<int*>(a, g, construct_an_integer_star_object, delete_obj);
  }
  {
    //TEST complex
    ddeque<complex> a;
    deque<complex>  g; //Gold
    test<complex>(a, g, construct_an_complex_object, nullptr);
  }
  {
    //TEST pointer to complex

    ddeque<complex*> a;
    deque<complex*>  g; //Gold
    test<complex*>(a, g, construct_an_complex_star_object, delete_obj);
  }
  cout << "ALL TESTs PassED. You can rest in peace" << endl ;
  cout << "push, pop, front, back, a[i] must take O(1) in your ddeque operation\n";
  cout << "Otherwise, you will get C for this assignment\n" ;
  return 0;
}


//EOF

