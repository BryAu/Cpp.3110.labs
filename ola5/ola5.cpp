//Bryce Ault
//Project: ola5
//File: ola5.cpp

#include <iostream>
#include "parameters.h"
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::getline;
using std::string;

//function declarations
int fibonacci(int n);
int sum(int n);
int longest(const int intArray[], int posSequence = 0, int tempSequence = 0, int index = 0);
int shortest(std::stringstream& ss, string shortestWord = "", string nextWord = "", int length = 0);

//main function
//calls all other functions in this cpp file
//and prints their corresponding results
int main()
{
	//call and print function results
	cout << "Fibonacci result: " << fibonacci(FibVal) << endl;
	cout << "Sum result: " << sum(SumVal) << endl;
	cout << "Longest Sequence of positive integers: " << longest(LongestVal) << endl;

	//varible declaration for stringstream
	//converts string into stringstream
	std::stringstream ss(SentenceVal);
	cout << "Length of the shortest string: " << shortest(ss) << endl;

	return 0;
}

//function returns the character length of the
//shortest word in a given string, once the string
//is converted into a stringstream
int shortest(std::stringstream& ss, string shortestWord, string nextWord, int length)
{
	//separater to grab individual words as strings
	const char DELIMITER = ' ';

	//grab the next word (nextWord) string from stringstream
	getline(ss, nextWord, DELIMITER);

	//if at the end of stringstream
	if (nextWord == "")
		return length;	//return shortest word length

	//if the next word grabbed is shorter in legnth than current shortestWord
	//or if shortestWord is an empty string (will happen on first execution)
	else if (nextWord.length() < shortestWord.length() || shortestWord == "")
	{
		//get length of new word
		//and set new word to current shortestWord
		length = nextWord.length();
		return shortest(ss, nextWord, "", length);
	}

	//if shortestWord is shorter in length
	//keep shortestWord value
	else
		return shortest(ss, shortestWord, "", length);

}


//function returns the length of the longest sequence of
//positive integers in a pass by value array
int longest(const int intArray[], int posSequence, int currentSequence, int index)
{
	//if max index value is reached
	if (index == 20)
		return posSequence;	//return sequence length

	//if the value at the given index is a non-positive
	else if (intArray[index] <= 0)

		//if the current working sequence length is greater than
		//the previously stored sequence length
		if (posSequence < currentSequence)

			//then pass the current sequence length
			longest(intArray, currentSequence, 0, index + 1);
		else

			//else keep the previously stored sequence length
			longest(intArray, posSequence, 0, index + 1);

	//if the value at the given index is positive
	else if (intArray[index] > 0)

		//if previous stored sequence is less than 
		//current working sequence
		if (posSequence <= currentSequence)

			//then store new currently working sequence length and increment
			longest(intArray, currentSequence + 1, currentSequence + 1, index + 1);
		else
			//else keep previously stored sequence length
			longest(intArray, posSequence, currentSequence + 1, index + 1);
}

//function returns the sum of n natural numbers
//recursively for any given value n
int sum(int n)
{
	//base case
	if (n == 1)
		return 1;	//return 1
	else
		//add n-1 to n
		return n + sum(n - 1);
}

//function returns the fibonacci result
//of any integer n
int fibonacci(int n)
{
	//2 base cases
	//for adding the 2 previous n values together
	if (n == 0)
		return 0;	//return 0

	else if (n == 1)
		return 1;	//return 1
	else
		//add the value n-2 to the value n-1
		return fibonacci(n-2) + fibonacci(n-1);
}