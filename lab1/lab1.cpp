//Name: Sarah Huang
//Date: 8/26/20
//Program: lab1.cpp
//Purpose: Taking in input to print out name, street address, difference in property value, and estimated monthly mortgage. 

#include <iostream>
#include <string>

using namespace std;

int main(){

	//Variables
	string name;
	int streetNumber;
	string streetName;
	string streetType;
	int lastMonthProperty;
	int nowMonthProperty;
	
	
	//Part A - Asking the user for a name and storing it in a variable
	cout << "What is your name? ";
	cin >> name;
	cout << "Hi there, " << name << ". \n";
	

	//Ask user for information and store in respective variables
	cout << "Enter the property street number, name, and type: ";
	cin >> streetNumber >> streetName >> streetType;
	cout << "Last month's property value: $";
	cin >> lastMonthProperty;
	cout << "This month's property value: $";
	cin >> nowMonthProperty;
	

	//Print out full street name, difference in property value, and monthly mortgage
	cout << "\nThis property is located at " << streetNumber << " " << streetName << " " << streetType << ".\n";
	cout << "Its value has changed by $" << (nowMonthProperty - lastMonthProperty) << " since last month.\n";
	
	double nowMortgage = (nowMonthProperty * 0.050) / 12;	//Calculations to find estimated monthly mortgage
	cout << "The estimated monthly mortgage is $" << nowMortgage << ".\n";
	


	//Part C - Calculate and present last month's monthly mortgage and average monthly mortgage
	double lastMortgage = (lastMonthProperty * 0.050) / 12;
	double averageMortgage = (lastMortgage + nowMortgage) / 2;

	cout << "Last month's estimated monthly mortgage was $" << lastMortgage << ".\n";
	cout << "The average monthly mortgage is $" << averageMortgage << ".\n";



	return 0;
}
