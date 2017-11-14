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
-----------------------------------------------------------------*/
class board{
public:
	static const int N = 2;
	board(const int arr[N][N]);
	
	const node& configure(char);
	bool insert_map(node);
	void push(node);
	node pop();
	bool empty();

private:
	char _dirs [4] = { 'U', 'L', 'D', 'R' };
	bool _isValid(char c);
	node _origin;
	unordered_map <node,int> _map;
	queue <node> _q;
	string _solution;
};

/*----------------------------------------------------------------
Node definition
-----------------------------------------------------------------*/
class node {
public:
	static const int N = 3;
	node(const int array[N][N]);
private:
	vector<vector<int>> _config;
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
	board _game;
	string _solution;
};



#endif
//EOF

