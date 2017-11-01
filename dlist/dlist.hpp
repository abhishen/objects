/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
Filename: dlist.hpp
-----------------------------------------------------------------*/
template <typename T>
node<T>* node<T>::get_next(node<T>* prev) {
	//Use prev to get next
	node<T>* next = _xor(prev,_next);
	return next;
}

template <typename T>
node<T>* dlist<T>::_create_a_node(const T& data) {
	_num_nodes_allocated++;
	node<T>* x = new(node<T>)(data); /* if T is by value, copy const will be called for T */
	return x;
}

template <typename T>
void dlist<T>::append(const T& data) {
	node<T> *c = _create_a_node(data);
	if (!_first) {
		//Store 0 in _next for now
		c->_next = 0;
		_first = c;
	}
	else {
		//Change _next of last node to this
		_last->_next = _xor(_last->_next,c);
		//Store last node's address as c's xorNext for now
		c->_next = _last;
	}
	_last = c;
	++_size;
}

template <typename T>
T& dlist<T>::get_data(int index) {
	node<T>* current = _first;
	node<T>* prev = 0;
	node<T>* next = 0;
	for (int i = 0; i < index; i++) {
		next = current->get_next(prev);
		prev = current;
		current = next;
	}
	return current->get_data();
}

//EOF

