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
	_q.push(_start);
	while (!_q.empty()) {

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

