#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*       Function Prototypes       */
void NumOfPrimes(int numOfInt, vector<int>* ints);
int numSqrt(int numOfInt);

/*********************************************************
 ** Input Arguments: numOfInt (Int)                     **
 ** Output Variable: SmallestValue (Int)                **
 ** Calling Methods: NumOfPrimes                        **
 **                                                     **
 **                                                     **
 **                                                     **
 ** Purpose: This is the main program. It will call     **
 **          all of the other programs in order to      **
 **          to determine the smallest number that      **
 **          is divisible by all integers ranging       **
 **          from 1 to n, where n represents a value    **
 **          that is stored in numOfInt and is recieved **
 **          via keyboard from the user.                **
 *********************************************************/

int main()
{
	// This variable holds the number that is input by the user and
	// represents the the largest value that is going to divide
	// into our final number
	int numOfInt;

	// This variable holds the square root of numOfInt rounded
	// to the nearest integer
	int sqrtOfNumber;

	// This variable holds the number of prime numbers that exist up
	// to the square root of the numOfInt value
	int numOfPrimeNumbers;


	cout << "Please enter an integer greater than 1" << endl;

	cin >> numOfInt;
	
	vector<int> integers;
	vector<int>* ints = &integers;

	sqrtOfNumber = numSqrt(numOfInt);

	NumOfPrimes(sqrtOfNumber, ints);
	delete ints;
	return 0;
}

/*********************************************************
 ** Input Arguments:  numOfInt (int)                    **
 **		      ints (vector<int>)                **
 ** Output Variables: numOfPrimes (int)                 **
 ** Calling Methods:  None                              **
 **							**			**						       **      
 **							**			**						       **
 ** Purpose: This method will search from 1 to n and    **
 **          return a list containing all of the primes **
 **          up to n using the Sieve of Eratosthenes    **
 **          algorithm.					**		
 **							**
 *********************************************************/
void NumOfPrimes(int numOfInt, vector<int>* ints) {

	// This loop fills the array ints with all numbers from
	// 1 to numOfInt
	for (int i = 1; i<=numOfInt; i++)
	{
		ints->push_back(i);
		
	}

	// This loop removes all non-primes from
	// the  numOfInt
	for (int j = 2; j<=numOfInt; j++) {
		int k = j + j;
		for (k; k<=numOfInt; k=k+j) {			
				ints->at(k-1) = 0;			
		}
	}
	
	vector<int> primeshere;
	vector<int>* primes = &primeshere;
	int k = 0;

	// This loop assigns all of the primes in order
	// to the primeshere vector.
	for (int i = 0; i<numOfInt; i++) {
		if (ints->at(i) != 0) {
		primes->push_back(ints->at(i));
		k++;
		} 
	}

	// This loop prints primeshere out
	for (int i = 0; i<k; i++) {
		cout << primes->at(i) << endl;
	}
	int z = 1;
	while ( z != 0) {
	}
	vector<int> num(5);
	return;
}
/*********************************************************/

/**********************************************************
 ** Input Arguments: numOfInt (int)        		 **
 ** Output variables: x2 (int)    			 **          
 ** Calling Methods: none				 **
 **							 **
 ** This method finds
 **
**********************************************************/
int numSqrt(int numOfInt) 
{
       	float numOfInts = numOfInt;
	float x1 = numOfInt;
	cout << "Hey" << endl;
	for (int i = 0; i<5; i++)
	{
		x1 = x1-(((x1)*(x1)-numOfInt)/(2*x1));
		cout << "Here is x1: " << x1 << endl;
	}
	int x2 = x1;
	cout << "here is x2: " << x2 << endl;
	return x2;
}

