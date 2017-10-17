/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: truthtabletest.cpp

On linux:
g++ truthtable.cpp truthtabletest.cpp
valgrind a.ou0t

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test truthtable object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "truthtable.h"
#include "../util/util.h"

/*----------------------------------------------------------------
You cannot change anything in this file

for n = 3 (say), the output must look like this
0: 000
1: 001
2: 010
3: 011
4: 100
5: 101
6: 110
7: 111
Number of rows for a truth table of 3 = 8
Run time for truthtable for n = 3 is 0.004 secs

after n > 8 the answers should like this:

Number of rows for a truth table of 9 = 512
Run time for truthtable for n = 9 is 0.003 secs
Number of rows for a truth table of 10 = 1024
Run time for truthtable for n = 10 is 0.003 secs
Number of rows for a truth table of 11 = 2048
Run time for truthtable for n = 11 is 0.002 secs
Number of rows for a truth table of 12 = 4096
Run time for truthtable for n = 12 is 0.001 secs
Number of rows for a truth table of 13 = 8192

Number of rows for a truth table of 31 = 2147483648
Run time for truthtable for n = 31 is 288.325 secs
Number of rows for a truth table of 32 = 4294967296
Run time for truthtable for n = 32 is 578.154 secs
-----------------------------------------------------------------*/
int main() {
  for (int n = 1; n < 35; ++n) {
    clock_t start = clock();
    bool verbose = (n < 9) ? true : false ;
    truthtable a(n,verbose);
    clock_t end = clock();
    double d = double(end - start) / CLOCKS_PER_SEC;
    cout << "Run time for truthtable for n = " << n << " is " << d << " secs" << endl;
  }
  return 0 ;
}

//EOF

