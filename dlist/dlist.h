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
	node(const T& data) :_data(data), _next(nullptr), _nextPtr(0) {}
	~node() {
		_next = nullptr;
		_nextPtr = 0;
	}
	T& get_data() { return _data; }
	friend class dlist<T>; //dlist can access nodes private part
	friend class dlist_iterator<T>; //dlist_iterator can access dlist private part

private:
	T  _data;
	node<T>* _next;
	long long _nextPtr;
};

template <typename T>
class slist {
public:
	typedef dlist_iterator<T> iterator;
	friend class dlist_iterator<T>; //slist_iterator can access slist private part
	dlist(bool display, void(*pv) (T& c) = nullptr, int(*cf) (const T& c1, const T& c2) = nullptr);
	~dlist();

	int size() const;
	void append(const T& data);
	bool unlink_data(const T& data);
	bool display()const { return _display; }
	void set_display(bool x) {
		// darray<T>::set_display(x);
		_display = x;
	}

	/* for iterator */
	iterator begin() { return iterator(_first); }
	iterator end() { return iterator(); }

private:
	node<T>* _first;
	node<T>* _last;
	void(*_pntr_to_func_to_delete_data) (T& c);
	int(*_pntr_to_compare_func) (const T& c1, const T& c2);
	int _num_nodes_allocated;
	int _num_nodes_freed;
	bool _display;

	node<T>* _create_a_node(const T& data);
	void _delete_a_node(node<T> *n);
	node<T>* _find(const T& data);
	bool _unlink_data(const node<T>* p);

};


#include "dlist.hpp"
#endif

//EOF

