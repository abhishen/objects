/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ddeque.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ddeque class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ddeque_H
#define ddeque_H

#include "../util/util.h"
#include "../darray/darray.h"

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
template <typename T>
class ddeque;

template <typename T>
class ddeque_iterator;

/*--------------------------------------------------------
typename ddeque iterator
----------------------------------------------------------*/
template <typename T>
class ddeque_iterator {
public:
  //WRITE CODE

private:
  //WRITE CODE
};

/*--------------------------------------------------------
class ddeque
----------------------------------------------------------*/
template <typename T>
class ddeque {
public:
  /* WRITE ALL PUBLIC FUNCTION HERE */
  /* CANNOT HAVE ANY PUBLIC DATA HERE */
  typedef ddeque_iterator<T> iterator;
  
  //size(), push_front() push_back() pop_front() pop_back() front() back() a[i]
  //All the above functions must have O(1) time complexity
  //No credit will be given if takes O(n)
  //Write CODE here

  bool display() const { return _display; }
  void set_display(bool x) {
    darray<T>::set_display(x);
    _display = x;
  }

private:
  /* MUST USE only darray<T>. You can use multiples of darray<T> */
  /* Can have some private variables */
  /* Write Code here */
  
  /* CAN HAVE ANY PRIVATE FUNCION */
  void _put(int pos, const T& a);
};

#include "ddeque.hpp"

#endif
//EOF

