//Name: Sarah Huang
//Date: 8/26/20
//Program: lab1.cpp
//Purpose: Receive input from the user (their name) and display it in a print statement.


#include <iostream>
#include <string>

using namespace std;

int main(){

	//Variables
	string name;

	//Prompts user for name and stores it in variable "name"
	cout << "What is your name? ";
	cin >> name;
	
	//Prints out statement using the name given by user
	cout << "Hi there, " << name << ". \n";
	return 0;
}
