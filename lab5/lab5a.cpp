/*Name: Sarah Huang
 *Program: lab5.cpp
 *Purpose: Simulate a shopping cart. 
		   The program continually asks the user for items, prices, and quantities until the user quits. 
		   A summary is printed and the total amount of money spent is printed.
 * Date: 11/5/20
 */


#include <iostream>
#include <vector>
#include <string>	//for getline
#include <iomanip>	//for the two decimal place prices
#include <limits>	//for error checking

using namespace std;

class Item{
	public:
		//Default constructor
		Item();
		
		//Mutators
		void SetName(const string&);
		void SetPrice(double);
		void SetQuantity(int);

		//Accessors
		string GetName() const;
		double GetPrice();
		int GetQuantity();
		void Print();

	private:
		string name;
		double price;
		int quantity;
};

Item::Item(){		//Default constructor
	name = "none";
	price = 0.0;
	quantity = 0;
}

		
void Item::SetName(const string& productName){	//Sets user's input name into item's name variable
	name = productName;	
}

void Item::SetPrice(double productPrice){		//Sets user's input price into item's price variable
	price = productPrice;
}

void Item::SetQuantity(int productQuantity){	//Sets user's input quantity into item's quantity variable
	quantity = productQuantity;
}


string Item::GetName() const{	//Returns name of item
	return name;
}

double Item::GetPrice(){		//Returns price of item
	return price;
}

int Item::GetQuantity(){		//Returns quantity of item
	return quantity;
}

void Item::Print(){		//Prints out the item name, price, and quantity
	cout << name << ": " << quantity << " at $" << setprecision(2) << fixed << price << " = $" << setprecision(2) << fixed << (quantity*price) << "\n";

}



int main(){
	//Variables
	string itemName;
	double itemPrice;
	int itemQuantity;
	bool realItem = true;		//Used to break the loop if ctrl+D pressed
	bool realItemFirst = true;	//Used to break the loop and prevent summary from printing if ctrl+D is pressed first
	unsigned int counter = 1;	//Used to keep track of number of items
	
	vector<Item> cart;
	Item currItem;
	

	//The first item - Ctrl+D will print nothing by not entering the while loop
	cout << "Item " << counter << "\n";
	cout << "Enter the item name: ";
	getline(cin, itemName);
	if(!cin)
		realItemFirst = false;
	
	
	while(realItem && realItemFirst){
		//Sets name officially to Item object
		currItem.SetName(itemName);

		//Sets price to Item object
		cout << "Enter the item price: $";
		while(!(cin >> itemPrice)){
			if(cin.eof()){	//Checks if ctrl+D is pressed - will break out of price while loop if entered
				realItem = false;
				break;
			}
			//This error checking is for everything not a valid input or ctrl+D
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Enter the item price: $";
		}
		
		//If ctrl+D was pressed, it will break out of entire input while loop
		if(realItem == false)
			break;
		else
			currItem.SetPrice(itemPrice);	
		
				
		//Sets quantity to Item object
		cout << "Enter the item quantity: ";
		while(!(cin >> itemQuantity)){
			if(cin.eof()){	//Checks if ctrl+D is pressed - will break out of quantity while loop if entered
				realItem = false;
				break;
			}
			//Error checking for everything not valid input or ctrl+D
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Enter the item quantity: ";
		}
		//If ctrl+D was pressed, it will break out of entire input while loop
		if(realItem == false)
			break;
		else
			currItem.SetQuantity(itemQuantity);
				
			
		//Adds Item object to vector
		cart.push_back(currItem);
		
		//Refresh cin to avoid getline errors, and increment to next item
		cin.ignore();
		counter++;


		//Asks for another item - Ctrl+D will not print anything
		cout << "\nItem " << counter << "\n";
		cout << "Enter the item name: ";
		getline(cin, itemName);
		if(!cin)
			realItem = false;
	}
	
	//If ctrl+D was entered for the first input (realItemFirst = false), nothing will print afterwards
	if(realItemFirst){		
		cout << "\n\nTotals\n";
		double cartTotal = 0.0;
		
		//Prints out every item (name, price, and quantity) in the cart vector
		for(unsigned int i = 0; i < cart.size(); i++){
			currItem = cart.at(i);
			cartTotal += (currItem.GetPrice() * currItem.GetQuantity());
			currItem.Print();
		}
		
		//Print out total cost of all items
		cout << "\nTotal: $" << setprecision(2) << fixed << cartTotal << "\n";
	}

	return 0;
}
