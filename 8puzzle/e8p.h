/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: e8p.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has e8p class declaration 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef e8p_H
#define e8p_H

#include "../util/util.h"
#include <unordered_map>
#include <queue>
#include <string>

/*----------------------------------------------------------------
Declaration of board
	1. Board stores the map of nodes
	2. Board uses a queue to keep track of BFS traversal
-----------------------------------------------------------------*/
class board{
public:
private:
	unordered_map<node,int> _map;
	queue<node> _q;
	node _original;
	node _final;
};

/*----------------------------------------------------------------
Node definition
	1. Node is the current configuration
	2. Private member array
-----------------------------------------------------------------*/
class node {
public:
	static const int N = 3;
	node(const int s[N][N]);
	node& node(const node&);
	node& operator=(const node&);
	bool isValid();
	node& configure();

private:
	int _current[N][N];
};

/*----------------------------------------------------------------
Declaration of e8p class
-----------------------------------------------------------------*/
class e8p{
public:
  static const int N = 3 ;
  e8p(const int s[N][N], const int f[N][N]) ;
  ~e8p();
  e8p(const e8p& from) = delete;
  e8p& operator=(const e8p& from) = delete;
  int get_num_moves() const ;
  string get_solution() const ;

private:
	int _moves;
	string _solution;
	int _start[N][N];
	int _final[N][N];
};



#endif
//EOF

