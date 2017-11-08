/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
Filename: dlist.h
-----------------------------------------------------------------*/
#ifndef dlist_h
#define dlist_h

#include "../util/util.h"

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
template <typename T>
class node ;

template <typename T>
class dlist ;

template <typename T>
class dlist_iterator ;

template <typename T>
class node {
public:
	node(const T& data) :_data(data),_next(0) {}
	~node() {
		_next = nullptr;
		_next = 0;
	}
	T& get_data() { return _data; }
	friend class dlist<T>;	
	friend class dlist_iterator<T>;
	node<T>* get_next(node<T>* prev);
	
private:
	T  _data;
	node<T>* _next;
	node<T>* _xor(node<T>* &a, node <T>*& b) { return (node<T>*) ((unsigned int)(a) ^ (unsigned int)(b)); }
};

template <typename T>
class dlist {
public:
	typedef dlist_iterator<T> iterator;
	friend class dlist_iterator<T>;
	dlist(bool display, void(*pv) (T& c) = nullptr, int(*cf) (const T& c1, const T& c2) = nullptr) {};
	~dlist();

	int size() const {
		return _size;
	}
	void append(const T& data);
	//bool unlink_data(const T& data);
	bool display()const { return _display; }
	void set_display(bool x) {
		// darray<T>::set_display(x);
		_display = x;
	}
	T& get_data(int index);
	
	/* for iterator */
	iterator begin() { return iterator(_first); }
	iterator end() { return iterator(); }

private:
	node<T>* _first;
	node<T>* _last;
	void(*_pntr_to_func_to_delete_data) (T& c);
	int(*_pntr_to_compare_func) (const T& c1, const T& c2);
	int _num_nodes_allocated;
	int _size;
	int _num_nodes_freed;
	bool _display;
	node<T>* _xor(node<T>* &a, node <T>* &b) { return (node<T>*) ((unsigned int)(a) ^ (unsigned int)(b)); }
	node<T>* _create_a_node(const T& data);
	void _delete_a_node(node<T> *n);
	//node<T>* _find(const T& data);
	//bool _unlink_data(const node<T>* p);

};

template <typename T>
class dlist_iterator {
public:
	dlist_iterator(node<T>* x = nullptr) :_current(x) {}
	~dlist_iterator() {}
	dlist_iterator(const dlist_iterator<T>& x) { _current = x._current; }
	dlist_iterator& operator=(const dlist_iterator<T>& x) { _current = x._current; return *this; }
	// *(itt)
	T& operator*() const {
		return (_current->_data);
	}

	//++itt 
	dlist_iterator<T>& operator++() {
		_current = _current->_next;
		return *this;
	}

	//if (itt != x.end()
	bool operator!=(const dlist_iterator<T>& rhs) const {
		return (_current != rhs._current);
	}


private:
	node<T>* _current;
};


#include "dlist.hpp"
#endif

//EOF

