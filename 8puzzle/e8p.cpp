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
board::board(const int s[N][N], const int f[N][N]) :_start(s), _final(f), _solution("") {
}

void board::play() {
	//Insert initial config into the queue and map
	_map.insert(_start);
	_q.push(_start);
	while (!_q.empty()) {
		node top = _q.front();
		_q.pop();
		for (int i = 0; i < 4; i++) {
			//Check if it is a valid configuration
			node next = top.configure(_dirs[i]);
			if (next.isValid()) {
				if (_map.insert(next).second == true) {
					_solution.append(to_string(_dirs[i]));
					_q.push(next);
				}
			}
		}
	}
}

/*
node constructor
*/
node::node(const int s[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			_current[i][j] = s[i][j];
		}
	}
}



//EOF

