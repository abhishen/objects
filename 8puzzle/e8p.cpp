/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: e8p.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has e8p class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "e8p.h"

/*
e8p constructor
	1. Creates board
		1. Creates node
		2. Initializes map and queue
	2. Calls play on board
*/
e8p::e8p(const int s[N][N], const int f[N][N]): _moves(0),_solution(""),_game(s,f) {
	_game.play();
	this->_solution = _game._solution;
	this->_moves = _game._moves;
}

/*
e8p destructor
*/
e8p::~e8p() {
	_moves = 0;
	_solution = "";
}

/*
board constructor
*/
board::board(const int s[N][N], const int f[N][N]): _start(s,true), _final(f,true), _solution("") {
}

void board::play() {
	//If start and final are same, exit
	if (_start == _final) return;
	//Insert initial config into the queue and map
	_map.insert(_start);
	_q.push(_start);
	while (!_q.empty()) {
		node top = _q.front();
		_q.pop();
		for (int i = 0; i  < 4; i++) {
			//Check if it is a valid configuration
			node next = top.configure(_dirs[i]);
			cout << "---------" << endl;
			next.print_node();
			//cout << "---------" << endl;
			if (next.isValid()) {
				_moves++;
				//If the config is equal to start
				//Append direction to node's substring.
				//Final solution = node's substring
				//Return
				if (next == _final) {
					next._substring.push_back(_dirs[i]);
					_solution = next._substring;
					return;
				}

				//If not, insert in map if unique and append the direction to node's substring
				if (_map.insert(next).second == true) {
					next._substring.push_back(_dirs[i]);
					_q.push(next);
				}
				else {
				//Configuration is not unique and we have hit a loop
				continue;
				}
			}
		}
	}
}

/*
node constructor
*/
node::node(const int s[N][N], bool valid = true) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			_current[i][j] = s[i][j];
		}
	}
	_substring = "";
	_valid = valid;
	_hash = _calculateHash();
}

node::node(const node& rhs) {
	_copy(rhs);
}

node& node::operator=(const node& rhs) {
	if (this != &rhs) {
		_copy(rhs);
	}
	return *this;
}

void node::_copy(const node& rhs) {
	this->_hash = rhs._hash;
	this->_valid = rhs._valid;
	this->_substring = rhs._substring;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			this->_current[i][j] = rhs._current[i][j];
		}
	}
}

size_t node::_calculateHash() {
	size_t hash = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			hash = hash + (size_t) _current[i][j] * (i + N * j);
		}
	}

	return hash;
}

node node::configure(char dir) {
	int next[N][N];
	int row = -1;
	int col = -1;
	bool valid = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (_current[i][j] == 0) {
				row = i;
				col = j;
			}
			next[i][j] = _current[i][j];
		}
	}

	if (dir == 'U') {
		//If the vacant position is to be moved up.
		int next_row = row - 1;
		int next_col = col;
		if (next_row < 0) {
			valid = false;
		}
		else {
			next[row][col] = next[next_row][next_col];
			next[next_row][next_col] = 0;
		}
	}
	else if (dir == 'D') {
		int next_row = row + 1;
		int next_col = col;
		if (next_row >= N) {
			valid = false;
		}
		else {
			next[row][col] = next[next_row][next_col];
			next[next_row][next_col] = 0;
		}
	}
	else if (dir == 'L') {
		int next_row = row;
		int next_col = col - 1;
		if (next_col < 0) {
			valid = false;
		}
		else {
			next[row][col] = next[next_row][next_col];
			next[next_row][next_col] = 0;
		}
	}
	else {
		int next_row = row;
		int next_col = col + 1;
		if (next_col >= N) {
			valid = false;
		}
		else {
			next[row][col] = next[next_row][next_col];
			next[next_row][next_col] = 0;
		}
	}

	node nextNode(next, valid);
	nextNode._substring = this->_substring;
	return nextNode;
}

bool operator==(const node& obj1, const node& obj2) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int e1 = obj1._current[i][j];
			int e2 = obj2._current[i][j];
			if (e1 != e2) return false;
		}
	}
	return true;
}

//EOF

