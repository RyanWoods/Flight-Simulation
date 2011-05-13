#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>

using namespace std;

/*       Function Prototypes       */
void NumOfPrimes(float sqrtOfNum, float numOfInts, vector<float>* ints);
float NumSqrt(float numOfInt);
float PrimeFactor(float numOfInts, vector<float>* pow, vector<float>* ints);

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
	float numOfInt;

	// This variable holds the square root of numOfInt rounded
	// to the nearest integer
	float sqrtOfNumber;

	// This variable holds the number of prime numbers that exist up
	// to the square root of the numOfInt value
	float numOfPrimeNumbers;


	cout << "Please enter an integer greater than 1" << endl;

	cin >> numOfInt;
	
	vector<float> integers;
	vector<float>* ints = &integers;

	vector<float> powers;
	vector<float>* pow = &powers;
	
	float answer = 0.0;
	sqrtOfNumber = NumSqrt(numOfInt);

	NumOfPrimes(sqrtOfNumber, numOfInt, ints);
	cout << "This is inbetween NumOfPrimes and PrimeFactor" << endl;	

	answer = PrimeFactor(numOfInt, pow, ints);
	return 0;
}

/*********************************************************
 ** Input Arguments:  numOfInt (int)                    **
 **		      ints (vector<int>)                **
 ** Output Variables: numOfPrimes (int)                 **
 ** Calling Methods:  None                              **
 **							**			
 **    						        **      
 **							**			
 **						        **
 ** Purpose: This method will search from 1 to n and    **
 **          return a list containing all of the primes **
 **          up to n using the Sieve of Eratosthenes    **
 **          algorithm.					**		
 **							**
 *********************************************************/
void NumOfPrimes(float sqrtOfNumber, float numOfInts, vector<float>* ints) {

	// This loop fills the array ints with all numbers from
	// 1 to numOfInt
	for ( float i = 1; i<=numOfInts; i++)
	{
		ints->push_back(i);
		
	}

	// This loop removes all non-primes from
	// the  numOfInt
	for (float j = 2; j<= numOfInts; j++) {
		float k = j + j;
		for (k; k<= numOfInts; k=k+j) {			
				ints->at(k-1) = 0;			
		}
	}
	
	vector<float> primeshere;
	vector<float>* primes = &primeshere;
	int k = 0;

	// This loop assigns all of the primes in order
	// to the primeshere vector.
	for (float i = 0; i<numOfInts; i++) {
		if (ints->at(i) != 0) {
		primes->push_back(ints->at(i));
		k++;
		} 
	}

	// This loop prints primeshere out
	for (float i = 0; i<k; i++) {
		cout << primes->at(i) << endl;
	}
	return;
}
/*********************************************************/

/*********************************************************
 ** Input Arguments: numOfInt (int)        	  	**
 ** Output variables: x2 (int)    			**          
 ** Calling Methods: none				**
 **							**
 ** This method finds the square root of numOfInt and   **
 ** then rounds that number to the nearest int.         **
 **							**
*********************************************************/
float NumSqrt(float numOfInt) 
{
       	float numOfInts = numOfInt;
	float x1 = numOfInt;
	cout << "Hey" << endl;
	for (float i = 0; i<5; i++)
	{
		x1 = x1-(((x1)*(x1)-numOfInt)/(2*x1));
		cout << "Here is x1: " << x1 << endl;
	}
	float x2 = ceil(x1);
	cout << "here is x2: " << x2 << endl;
	return x2;
}
/*********************************************************/

/*********************************************************
 ** 
 **
 ** 
 *********************************************************/
float PrimeFactor(float numOfInt, vector<float>* pow, vector<float>* ints) 
{
	float answer = 0;
	vector<float> test;
	for (float n = 0; n <= ints->size(); n++) 
	{
		test.push_back(0);
		pow->push_back(0);
	}
        for (float i = 2; i <= numOfInt; i++) 
	{
		float k = i;
		for (float j = 1; j < ints->size(); j++) 
		{
			if ( fmodf(k, ints->at(j)) == 0)
			{
				test.at(j)++;
				k = k/ints->at(j);
				j = 1;
			}
			if (k == 1) 
			{ 
				j = ints->size();
			} 
		}
		for (float j = 0; j < ints->size(); j++)
		{
			cout << "this is j: " << j << " and this is pow.at(j) " << pow->at(j) << endl;
			if (test.at(j) > pow->at(j))
			{
				pow->at(j) = test.at(j);
				test.at(j) = 0;
			}
		}		
	}
	for (float j = 0; j < ints->size(); j++) 
	{
		cout << "There are " << pow->at(j) << " of " << ints->at(j) << endl;
	}	
	return answer;
}
