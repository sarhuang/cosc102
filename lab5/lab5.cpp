/*Name: Sarah Huang
 *Program: lab5.cpp
 *Purpose: The shopping cart simulator program stores, manipulates, and prints items with names, descriptions, prices, and quantity.
		   It continually asks the user to choose from a variety of actions:
			-Add item
			-Delete item
			-Change item quantity
			-Print all item descriptions in shopping cart
			-Print all item costs and total cost in shopping cart
			-Quit
			Entering Ctrl-D or 'q' will exit the program.
		   
 * Date: 11/13/20
 */


#include <iostream>
#include <vector>
#include <string>	//for getline
#include <iomanip>	//for the two decimal place prices
#include <limits>	//for error checking

using namespace std;


class Item{
	public:
		//Prototypes
		Item(string, string, double, int);	//Constructor
		
		void SetName(const string&);		//Mutators
		void SetPrice(double);
		void SetQuantity(int);
		void SetDescription(const string&);

		string GetName() const;				//Accessors
		double GetPrice() const;
		int GetQuantity() const;
		void Print();
		string GetDescription() const;
		void PrintDescription();

	private:
		//Variables
		string name;
		string description;
		double price;
		int quantity;
};

Item::Item(string n = "none", string d = "none", double p = 0.0, int q = 0) : name(n), description(d), price(p), quantity(q){		//Constructor
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

void Item::SetDescription(const string& productDescription){	//Sets user's input description into item's quantity variable
	description = productDescription;
}

string Item::GetName() const{			//Returns name of item
	return name;
}

double Item::GetPrice() const{			//Returns price of item
	return price;
}

int Item::GetQuantity() const{			//Returns quantity of item
	return quantity;
}	

string Item::GetDescription() const{	//Returns description of item
	return description;
}

void Item::Print(){		//Prints out the item name, price, and quantity
	cout << name << ": " << quantity << " at $" << setprecision(2) << fixed << price << " = $" << setprecision(2) << fixed << (quantity*price) << "\n";

}

void Item::PrintDescription(){
	cout << name << ": " << description << "\n";
}









class ShoppingCart{
	public:
		//Prototypes
		ShoppingCart(string, string);	//Constructor
		
		void AddItem(const Item&);		//Mutators
		void RemoveItem(const string&);
		void ChangeQuantity(const string&, int);
		
		string GetCustomerName() const;	//Accessors
		string GetDate() const;
		int GetTotalQuantity() const;
		double GetTotalCost() const; 
		void PrintTotal();
		void PrintDescriptions();

	private:
		//Variables
		string customerName;
		string date;
		vector<Item> cart;

		//Accessor
		int FindItemIndex(const string&) const;
};

ShoppingCart::ShoppingCart(string nm = "None", string dt = "April 1, 2020") : customerName(nm), date(dt) {	//Constructor
}

void ShoppingCart::AddItem(const Item& newItem){			//Takes in Item object and adds it to the vector
	cart.push_back(newItem);
}

void ShoppingCart::RemoveItem(const string& selected){		//Finds the index of the object if found and deletes it from vector
	int selectedIndex = FindItemIndex(selected);			//If object is not found, the user will be notified
	if(selectedIndex != -1)
		cart.erase(cart.begin() + selectedIndex);
	else
		cout << "Item not found in cart.\n";
}

void ShoppingCart::ChangeQuantity(const string& selected, int newQuantity){	//Finds the index of the object if found and changes its quantity
	int selectedIndex = FindItemIndex(selected);							//If object is not found, the user will be notified
	if(selectedIndex != -1)
		if(newQuantity == 0)
			RemoveItem(selected);
		else
			cart.at(selectedIndex).SetQuantity(newQuantity);
	else
		cout << "Item not found in cart.\n";
}

string ShoppingCart::GetCustomerName() const{				//Retuns customer's name
	return customerName;
}

string ShoppingCart::GetDate() const{						//Returns date
	return date;
}

int ShoppingCart::FindItemIndex(const string& search) const{	//Searches the vector for the object's name and returns its index if found
	int indexFound = -1;								
	for(unsigned int index = 0; index < cart.size(); index++){
		string currItem = cart.at(index).GetName();
		if(currItem == search)
			indexFound = index;
	}
	return indexFound;
}

int ShoppingCart::GetTotalQuantity() const{					//Returns the total quantity of all items in vector
	int totalQ = 0;
	for(unsigned int index = 0; index < cart.size(); index++){
		Item currItem = cart.at(index);
		totalQ = totalQ + currItem.GetQuantity();
	}
	return totalQ;
}

double ShoppingCart::GetTotalCost() const{					//Returns the total cost (quantity x price) of all items in vector
	double totalC = 0.0;
	for(unsigned int index = 0; index < cart.size(); index++){
		Item currItem = cart.at(index);
		totalC = totalC + (currItem.GetPrice() * currItem.GetQuantity());
	}
	return totalC;
}

void ShoppingCart::PrintTotal(){														//Prints the total cost of each item and overall cost
	cout << "\n" << GetCustomerName() << "'s Shopping Cart - " << GetDate() << "\n";	//If the vector is empty, the user will be notified
	cout << "Number of items: " << GetTotalQuantity() << "\n\n";
	if(cart.size() > 0){
		for(unsigned index = 0; index < cart.size(); index++){
			Item currItem = cart.at(index);
			cout << currItem.GetName() << ": " << currItem.GetQuantity() << " at $" << setprecision(2) << fixed << currItem.GetPrice();
			cout << " = $" << setprecision(2) << fixed << (currItem.GetQuantity() * currItem.GetPrice()) << "\n";
		}
	}
	else
		cout << "Shopping cart is empty.\n";
	cout << "\nTotal: $" << setprecision(2) << fixed << GetTotalCost() << "\n";
}

void ShoppingCart::PrintDescriptions(){													//Prints all items and their respective descriptions
	cout << "\n" << GetCustomerName() << "'s Shopping Cart - " << GetDate() << "\n\n";	//If the vector is empty, the user will be notified
	cout << "Item Descriptions\n";
	if(cart.size() > 0){
		for(unsigned int index = 0; index < cart.size(); index++){
			Item currItem = cart.at(index);
			currItem.PrintDescription();
		}
	}
	else
		cout << "Shopping cart is empty.\n";
}






char PrintMenu(){	//Prints the entire option menu and returns the user's input
	char choice;
	cout << "MENU\n";
	cout << "a - Add item to cart\n";
	cout << "d - Remove item from cart\n";
	cout << "c - Change item quantity\n";
	cout << "i - Output item descriptions\n";
	cout << "o - Output shopping cart\n";
	cout << "q - Quit\n\n";
	cout << "Choose an option: ";

	cin >> choice;
	cin.ignore();
	return choice;
}









int main(){
	//Customer Variables
	string userName;
	string userDate;
	char decision;
	bool ctrlD = false;	//Keeps track if Ctrl-D was pressed

	//Customer and date input
	cout << "Enter customer name: ";
	getline(cin, userName);
	cout << "Enter today's date: ";
	getline(cin, userDate);
	ShoppingCart shopcart(userName, userDate);
	cout << "\nCustomer name: " << shopcart.GetCustomerName() << "\n";
	cout << "Today's date: " << shopcart.GetDate() << "\n\n";


	//Item Variables
	string thingName;
	string thingDescription;
	double thingPrice;
	int thingQuantity;
	Item newThing;

	//The first decision - the loop will not run if Ctrl-D is pressed first
	decision = PrintMenu();
	if(cin.eof())
		ctrlD = true;

	
	while(decision != 'q' || ctrlD){
		switch(decision){
			case 'a':												//Add item to cart option
				cout << "\nADD ITEM TO CART\n";	
				cout << "Enter the item name: ";					//Item NAME input
				getline(cin, thingName);
				if(!cin){											//If Ctrl-D is pressed, the program will quit
					ctrlD = true;
					break;
				}
				else
					newThing.SetName(thingName);
				cout << "Enter the item description: ";				//Item DESCRIPTION input	
				getline(cin, thingDescription);
				if(!cin){											//If Ctrl-D is pressed, the program will quit
					ctrlD = true;
					break;
				}
				else
					newThing.SetDescription(thingDescription);
				cout << "Enter the item price: $";					//Item PRICE input
				while(!(cin >> thingPrice) || thingPrice < 0){		//Will run as long as it is a number and not negative
					if(cin.eof()){									//If Ctrl-D is pressed, the program will quit (break out of while loop and then swtich)
						ctrlD = true;
						break;
					}
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout << "Enter the item price: $";		
				}	
				if(ctrlD)
					break;
				else
					newThing.SetPrice(thingPrice);
				cout << "Enter the item quantity: ";				//Item QUANTITY input
				while(!(cin >> thingQuantity) || thingQuantity < 0){//Will run as long as it is an integer and not negative
					if(cin.eof()){									//If Ctrl-D is pressed, the program will quit (break out of while loop and then switch)
						ctrlD = true;
						break;
					}
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter the item quantity: ";
				}
				if(ctrlD)
					break;
				else
					newThing.SetQuantity(thingQuantity);
				shopcart.AddItem(newThing);
				break;	
	
									
			case 'd':												//Delete item option					
				cout << "\nREMOVE ITEM FROM CART\n";
				cout << "Enter the item name to remove: ";			//Item NAME input
				getline(cin, thingName);
				if(!cin){											//If Ctrl-D is pressed, the program will quit
					ctrlD = true;
					break;
				}
				else
					shopcart.RemoveItem(thingName);
				break;


			case 'c':												//Change item quantity option
				cout << "\nCHANGE ITEM QUANTITY\n";
				cout << "Enter the item name: ";					//Item NAME input
				getline(cin, thingName);
				if(!cin){											//If Ctrl-D is pressed, the program will quit
					ctrlD = true;
					break;
				}
				cout << "Enter the new quantity: ";					//Item QUANTITY input
				while(!(cin >> thingQuantity) || thingQuantity < 0){//Will run as long as it is an integer and not negative
					if(cin.eof()){									//If Ctrl-D is pressed, the program will quit (while and then switch)
						ctrlD = true;
						break;
					}
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout << "Enter the new quantity: ";
				}
				if(ctrlD)
					break;
				else
					shopcart.ChangeQuantity(thingName, thingQuantity);
				break;


			case 'i':												//Print descriptions option
				shopcart.PrintDescriptions();
				break;
	

			case 'o':
				shopcart.PrintTotal();								//Print totals option
				break;


			case 'q':												//Quit program option
				break;


			default:												//Quit program with Ctrl-D option
				if(cin.eof())
					ctrlD = true;
				break;
		}
		if(ctrlD)
			break;
		cout << "\n";
		decision = PrintMenu();										//If an incorrect input is given, the program will ask again until one is given
	}
	return 0;
}
