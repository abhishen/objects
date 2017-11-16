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
#include <unordered_set>

/*----------------------------------------------------------------
Node definition
1. Node is the current configuration
2. Private member array
-----------------------------------------------------------------*/
class node {
public:
	static const int N = 3;
	node(const int s[N][N], bool);
	//~node();
	node(const node&);
	node& operator=(const node&);
	node configure(char);
	bool isValid() {
		return _valid == true;
	}

	void print_node() {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int v = _current[i][j];
				if (v) {
					cout << v << ' ';
				}
				else {
					cout << ' ' << ' ';
				}
			}
			cout << endl;
		}
	}

	friend bool operator==(const node&, const node&);

	size_t getHash() const {
		return _hash;
	}

private:
	int _current[N][N];
	bool _valid;
	size_t _hash;
	size_t _calculateHash();
	void _copy(const node&);
	string _substring;
	friend class board;
	friend class e8p;
};

struct NodeHasher {
	size_t operator()(const node& obj) const {
		return obj.getHash();
	}
};

struct NodeComparator {
	bool operator()(const node& obj1, const node& obj2) const {
		return obj1 == obj2;
	}
};

/*----------------------------------------------------------------
Declaration of board
	1. Board stores the map of nodes
	2. Board uses a queue to keep track of BFS traversal
-----------------------------------------------------------------*/
class board{
public:
	static const int N = 3;
	board(const int[N][N], const int[N][N]);
	//~board();
	void play();
private:
	unordered_set<node, NodeHasher, NodeComparator> _map;
	queue<node> _q;
	node _start;
	node _final;
	string _solution;
	int _moves;
	char _dirs[4] = { 'U', 'L', 'D', 'R' };
	friend class e8p;
};

/*----------------------------------------------------------------
Declaration of e8p class
-----------------------------------------------------------------*/
class e8p{
public:
  static const int N = 3 ;
  e8p(const int s[N][N], const int f[N][N]);
  ~e8p();
  e8p(const e8p& from) = delete;
  e8p& operator=(const e8p& from) = delete;
  
  int get_num_moves() const {
	  return _moves;
  }

  string get_solution() const {
	  return _solution;
  }

private:
	int _moves;
	string _solution;
	board _game;
	//int _start[N][N];
	//int _final[N][N];
};



#endif
//EOF

