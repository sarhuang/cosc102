/*
 *Name: Sarah Huang
 *Program: lab4.cpp
 *Purpose: Utilize stringstream to print out the string the user inputs, 
		   count the number of characters, and print the input without whitespace.
 *Date: 10/11/20
 */

#include <iostream>
#include <string>	//Need this for getline
#include <sstream>	//Need this for stringstream

using namespace std;

int main(){
	stringstream ss;
	string original;

	
	//Ask user to input a string and prints it back out into the console
	cout << "Enter a line of text: ";
	getline(cin, original);
	cout << "\nOrignal: " << original << "\n";

	//Prints the number of characters that make up the user's input
	int numCharacters = original.length();
	cout << "Characters: " << numCharacters << "\n";

	//The input is stored in the stringstream and printed back out without whitespace
	ss << original;	
	string noSpace;
	cout << "Without whitespace: ";
	while(ss >> noSpace){	//Removes whitespace
		cout << noSpace;	//Prints the string without whitespace on the same line as "Without whitespace: "
	}
	cout << "\n";

	return 0;
}
