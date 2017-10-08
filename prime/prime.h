#ifndef PRIME_H
#define PRIME_H
#include "../util/util.h"
/*
class node {
	private:
		int _data;
		node *_next;

	public:
		node(int);
};

class list {
	private:
		node *_head;
		node *_tail;
		int _size;
	public:
		list();
		void insertAtTail();
};
*/

class prime {
	private:
		bool *_refArray; //This contains all the numbers.

		int _range;
		int _algos;
		//Array on the heap. Number of elements = second argument of constructor
		int *_number_of_primes; //Update at every insert
		int *_number_of_steps; //Update at every step
		
		//Array of lists. Initialized to row = second argument of constructor.
		int **_primeList;

		//Allocate memory for all arrays.
		void _initialize(int,int);
		void _calculateBruteMethod(int);
		void _calculateUptoPrimeMethod(int);
		void _calculateSieveMethod(int);
		void _sieveMultiples(int,int&);
		void _updatePrimeArray(int);
		void _updateStepsArray(int,int);

		int _sqrt(int);
		bool _isPrime(int,int&);

	public:
		//First arg = Number of algos. Second arg = Range
		prime(int, int);
		~prime();
		int number_of_primes(int);
		int number_of_steps(int);
		int get_prime_number(int,int);
	
};

#endif


