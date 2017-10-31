/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: slist.hpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Definition of routines of slist class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
slist Constructor
-----------------------------------------------------------------*/
template <typename T>
slist<T>::slist(void(*pv) (T& c), int(*cf) (const T& c1, const T& c2)) :
_first(nullptr), _last(nullptr), _pntr_to_compare_func(cf), _pntr_to_func_to_delete_data(pv),
_num_nodes_allocated(0), _num_nodes_freed(0)
{
  if (display()) {
    cout << "in slist constructor:" << endl;
  }
}

/*----------------------------------------------------------------
slist Destructor
-----------------------------------------------------------------*/
template <typename T>
slist<T>::~slist() {
  if (display()) {
    cout << "in slist destructor:" << endl;
  }
  node<T>* t = _first;
  while (t) {
    node<T>* ct = t;
    t = t->_next;
    _delete_a_node(ct);
  }
  if (_num_nodes_allocated != _num_nodes_freed) {
    assert(0);
  }
  _first = nullptr;
  _last = nullptr;
}

/*----------------------------------------------------------------
change function
-----------------------------------------------------------------*/
template <typename T>
void slist<T>::change_functions(void(*pv) (T& c), int(*cf) (const T& c1, const T& c2)) {
  _pntr_to_compare_func = cf;
  _pntr_to_func_to_delete_data = pv;
}

/*----------------------------------------------------------------
How many elements are in the list
-----------------------------------------------------------------*/
template <typename T>
int slist<T>::size() const {
  int i = 0;
  node<T> *f = _first;
  while (f) {
    i++;
    f = f->_next;
  }
  return i;
}

/*----------------------------------------------------------------
create a node in slist
-----------------------------------------------------------------*/
template <typename T>
node<T>* slist<T>::_create_a_node(const T& data){
  _num_nodes_allocated++;
  node<T>* x = new(node<T>)(data); /* if T is by value, copy const will be called for T */
  return x;
}

/*----------------------------------------------------------------
delete a node from slist
-----------------------------------------------------------------*/
template <typename T>
void slist<T>::_delete_a_node(node<T> *n){
  _num_nodes_freed++;
  if (_pntr_to_func_to_delete_data) {
    _pntr_to_func_to_delete_data(n->_data); /* Distructor of T will be called*/
  }
  delete(n);
}

/*----------------------------------------------------------------
append data to the end of the slist
-----------------------------------------------------------------*/
template <typename T>
void slist<T>::append(const T& data) {
  node<T> *c = _create_a_node(data);
  if (!_first) {
    _first = c;
  }
  else {
    _last->_next = c;
  }
  _last = c;
}

/*----------------------------------------------------------------
append data after p.
if p is not there, add data at the end
-----------------------------------------------------------------*/
template <typename T>
void append_after(const T& p, const T& data) {
  //WRITE YOUR CODE HERE
}

/*----------------------------------------------------------------
find data in the slist
-----------------------------------------------------------------*/
template <typename T>
node<T>* slist<T>::_find(const T& data){
  if (!(_pntr_to_compare_func)) {
    return NULL;
  }
  node<T> *f = _first;
  while (f) {
    if (_pntr_to_compare_func(data, f->_data) == 0) {
      return f;
    }
    f = f->_next;
  }
  return NULL;
}

/*----------------------------------------------------------------
find data in the slist
-----------------------------------------------------------------*/
template <typename T>
bool slist<T>::find(const T& data){
  node<T>* f = _find(data);
  return (f) ? true : false;
}

/*----------------------------------------------------------------
Unlink node p from slist
-----------------------------------------------------------------*/
template <typename T>
bool slist<T>::_unlink_data(const node<T>* f) {
  node<T> *p = _first; //Previous
  node<T> *c = _first; //Current
  while (c) {
    if (c == f)  {
      /* found is true */
      if (c == _first) {
        /* f is the first item */
        _first = c->_next;
      }
      if (c == _last) {
        /* f is the last item */
        if (!_first) {
          /* Only one item in the list and it is the last  */
          _last = NULL;
        }
        else {
          /* many items in the list, but f is last */
          _last = p;
        }
      }
      p->_next = c->_next; //unlinked
      break;
    }
    p = c;
    c = c->_next;
  }
  if (c) {
    /* found is true */
    _delete_a_node(c);
    return true;
  }
  return false;
}

/*----------------------------------------------------------------
Unlink node p from slist
-----------------------------------------------------------------*/
template <typename T>
bool slist<T>::unlink_data(const T& data) {
  node<T>* f = _find(data);
  if (f) {
    return _unlink_data(f);
  }
  return false;
}

/*----------------------------------------------------------------
1->4->8->7

7->8->4->1
-----------------------------------------------------------------*/
template <typename T>
void slist<T>::reverse() {
  node<T>* c = _first;
  if (c) {
    _last = _first;
    node<T>* n = c->_next;
    while (n) {
      node<T>* t = n->_next;
      n->_next = c;
      c = n;
      n = t;
    }
    _first = c;
    _last->_next = NULL;
  }
}



/*----------------------------------------------------------------

-----------------------------------------------------------------*/
template <typename T>
void  slist<T>::_reverse_recur(node<T>* f)  {
  //WRITE CODE
}

/*----------------------------------------------------------------
1->4->8->7

7->8->4->1
-----------------------------------------------------------------*/
template <typename T>
void slist<T>::reverse_recur() {
  node<T>* f = _first;
  if (f) {
    node<T>* l = _last;
    _reverse_recur(_first);
    _last = f;
    _first = l;
  }
}


/*----------------------------------------------------------------
create a loop
-----------------------------------------------------------------*/
template <typename T>
void slist<T>::create_a_loop(int from, int to) {
  int i = 0;
  node<T> *fp = NULL;
  node<T> *tp = NULL;
  node<T> *f = _first;
  while (f) {
    i++;
    if (i == from) {
      fp = f;
    }
    if (i == to) {
      tp = f;
    }
    f = f->_next;
  }
  if (fp && tp) {
    fp->_next = tp;
  }
}

/*----------------------------------------------------------------
detect a loop
Slow ptr moves at a distance of one 0,1,2,3,... n
fast ptr moves at a distance of two 1,3, 5, 7 ..
-----------------------------------------------------------------*/
template <typename T>
bool slist<T>::detect_loop() const {
  node<T> *slow_ptr = _first;
  node<T> *fast_ptr = _first;
  if (fast_ptr) {
    fast_ptr = fast_ptr->_next;
  }

  while (slow_ptr && fast_ptr) {
    if (fast_ptr == slow_ptr) {
      return true;
    }
    slow_ptr = slow_ptr->_next;
    fast_ptr = fast_ptr->_next;
    if (fast_ptr) {
      fast_ptr = fast_ptr->_next;
    }
  }
  return false;
}




//EOF

