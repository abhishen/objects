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
  
};

/*----------------------------------------------------------------
Node definition
-----------------------------------------------------------------*/
class node {
public:
  
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
 
};



#endif
//EOF

