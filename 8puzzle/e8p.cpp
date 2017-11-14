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
node constructor
*/
node::node(const int array[N][N]) {
	//Node stores the configuration
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			_config[i][j] = array[i][j];
		}
	}
}

/*
e8p constructor
*/

e8p::e8p(const int s[N][N], const int f[N][N]):_solution(""),_game(s) {
	//e8p creates board
	//Board stores the unordered_map of nodes and queue of nodes
	//Board also stores the starting config in node _origin
}

/*
e8p destructor
*/
e8p::~e8p() {
	delete _game;
}

int e8p::get_num_moves() const {
	return _moves;
}

string e8p::get_solution() const {
	return _solution;
}

/*
board constructor
*/
board::board(const int s[N][N]):_solution(""),_origin(s) {
}

bool board::_isValid(char c) {
	int row = -1;
	int col = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int v = _origin [i][j];
			if (v == 0) {
				row = i;
				col = j;
				break;
			}
		}
	}

	if (c == 'U') {
		int newPosition = row - 1;
		return (newPosition >= 0);
	}
	else if (c == 'L') {
		int newPosition = col - 1;
		return (newPosition >= 0);
	}
	else if (c == 'D') {
		int newPosition = row + 1;
		return (newPosition < N);
	}
	else {
		int newPosition = col + 1;
		return (newPosition < N);
	}
}

node& board::configure(char c) {
	if (_isValid(c)) {
		node temp;
	}
}

//EOF

