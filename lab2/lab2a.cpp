//Name: Sarah Huang
//Program: lab2.cpp
//Date: 9/13/20
//Purpose: After receiving an integer input, identify whether the interstate is a primary or auxiliary highway 
//		   along with which direction the primary highway runs using a series of if-else statements. 
//		   Prints error if given input does not pass certain requirements.

#include <iostream>
using namespace std;

int main(){
	//Asking for an integer input and storing it in a variable
	int input; 
	cout << "Enter an interstate number: ";
	cin >> input;
	int divisibleBy100 = input % 100; //If the remainder is 0 after dividing the input by 100, it will not be valid

	
	if(input >= 1 && input <= 999 && divisibleBy100 != 0){	//Checking if the input passes all the requirements (within 1-999 and not divisible by 100)
		if(input <= 99){ //If input is between 1-99
			if(input % 2 == 0){	//Even number input
				cout << "I-" << input << " is a primary interstate, going east/west.\n";
			}
			else{	//Odd number input
				cout << "I-" << input << " is a primary interstate, going north/south.\n";
			}
		}
		else{	//If the input is between 101-999
			int primaryHighway = input % 100;	//The remainder is the primary highway
			if(input % 2 == 0){	//Even number input
				cout << "I-" << input << " is an auxiliary highway, serving I-" << primaryHighway << ", going east/west.\n";
			}
			else{	//Odd number input
				cout << "I-" << input << " is an auxiliary highway, serving I-" << primaryHighway << ", going north/south.\n";
			}
		}
	}
	else{	//Never passed any of the requirements
		cout << input << " is not a valid interstate number.\n";
	}
	return 0;
}

