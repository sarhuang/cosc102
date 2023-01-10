/*
 *Name: Sarah Huang
 *Program: lab4.cpp
 *Purpose: Utilize stringstream to print out the string the user inputs, 
		   count the number of characters, and print the input without whitespace.
 *Date: 10/21/20
 */

#include <iostream> 
#include <limits>	//Need this for error checking
#include <string>	//Need this for getline
#include <sstream>	//Need this for stringstream

using namespace std;

//Function prototypes
int NumWords(const string&); //Take string and return num words in string
int NumNonWSCharacters(const string&); //Return num char w/o whitespace
void CharReplace(string&, char, char); //Replace char with new char (don't use replace)
char PrintMenu(); //Output menu displayed and return single character input



int main(){
	//Variables
	string original;		
	char choice;		
	char old, replacement;	

	//Asks the user for a text input and repeats it back to the user
	cout << "Enter a line of text: ";
	getline(cin, original);
	cout << "\nYou entered: " << original << "\n\n";


	//Repeats until the user enters 'q'
	do{
		choice = PrintMenu();	//The function returns what char the user inputted and stores in it
		switch(choice){
			case 'w':	//Counts the number of words in the text (divided by whitespace)
				cout << "Number of words: " << NumWords(original) << "\n";
				break;

			case 'c':	//Counts all characters in text excluding whitespace
				cout << "Number of non-whitespace characters: " << NumNonWSCharacters(original) << "\n";
				break;

			case 'r':	//Replaces all the characters in the text with what the user wants
				cout << "Enter a character to find: ";	
				cin >> old;

				cout << "Enter a character to replace: ";
				cin >> replacement;
			
				CharReplace(original, old, replacement);
				cout << "\nNew string: " << original << "\n";
				break;

			case 'q':	//Quits program
				break;
		}
	
		if(choice != 'q')	//Spaces the program correctly when the user's choice is not 'q'
			cout << '\n';

	}while(choice != 'q');

	return 0;
}


//Calculates number of words 
int NumWords(const string& text){
	stringstream ss(text);	//Text is inserted into the stringstream
	string holder;			//Temporary string placeholder to transfer what's in stringstream to placeholder
	int words = 0;

	while(ss >> holder){	//The string stream puts a word (all characters before a space) in the placeholder and increments the int variable
		words++;			//The int variable continues to increment until there are no more words
	}
	return words;
}


//Calculates number of characters without whitespace
int NumNonWSCharacters(const string& text){
	int characters;
	stringstream ss;
	string noSpace;
	string holder;
	
	ss << text;						//Copies the user's inputted text into the stringstream
	while(ss >> noSpace){			//The string stream puts a word in the empty string placeholder
		holder += noSpace;			//Words will continued to be added to the placeholder (w/o spaces) until there are none left
	}
	
	characters = holder.length();	//Stores the number of characters in the placeholder (equivalent to original text but w/o whitespace)
	return characters;
}


//Replaces the old characters with the new characters
void CharReplace(string& text, char oldLetter, char newLetter){
	stringstream ss;
	string word;
	string holder;

	ss << text;															//Copies user's inputted text into stringstream
	while(ss >> word){															
		for(unsigned int index = 0; index < word.length(); index++){	//For each word, each character is checked for the wanted letter and replaced when found 
			if(word[index] == oldLetter){
				word[index] = newLetter;
			}
		}
		holder = holder + word + " ";									//Placed outside of the checking if the word does not need to be changed
																		//Adds the changed words and spaces to replicate the structure original text
	}

	text = holder;														//The original text is a reference of the placeholder (they are now the same!)
				
}


//Prints the options
char PrintMenu(){
	cout << "Options\n";
	cout << "w - Number of words\n";
	cout << "c - Number of non-whitespace characters\n";
	cout << "r - Replace a character\n";
	cout << "q - Quit\n";
	cout << "\nChoose an option: ";

	char input;

	while(!(cin >> input) || (input != 'w' && input != 'c' && input != 'r' && input != 'q')){	//The input has to be w, c, r, or q or it will ask again until changed
		
		//If the user inputs CTRL+D, the program also quits by returning 'q'
		if(!cin)
			return 'q';
		
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "\nOptions\n";
		cout << "w - Number of words\n";
		cout << "c - Number of non-whitespace characters\n";
		cout << "r - Replace a character\n";
		cout << "q - Quit\n";
		cout << "\nChoose an option: ";
	}
	
	if(input == 'c' || input == 'w')	//Formatting spaces
		cout << "\n";
	return input;
}
