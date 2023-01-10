/*
 *Name: Sarah Huang
 *Date: 11/20/20
 *Program: lab6.cpp
 *Purpose: Create a vector class manually using points and dynamic memory.
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

class doublevector{
	static constexpr double DOUBLE_DEFAULT_VALUE = -5.55;
	double *mValues; //All data stored here
	int mNumValues;	 //Stores how many values will be inside mValues (0 if mValues = nullptr)

	public: 
		doublevector();
		~doublevector();
		void resize(int new_size, double initial_value = DOUBLE_DEFAULT_VALUE); 

		void push_back(double value);
		double &at(int index);
		const double &at(int index) const;
		unsigned long size() const;
};

void print_all(const doublevector &v){
	if(v.size() == 0){
		cout << "Vector is empty.\n";
	}
	else{
		unsigned long i;
		for(i = 0; i < v.size(); i++){
			cout << "[" << setfill('0') << right << setw(3) << i << "] = " << fixed << setprecision(4) << v.at(i) << '\n';
		}
	}
}

int main(){
	doublevector v;
	do{
		string command;
		cout << "Enter a command ('quit' to quit): ";
		if(!(cin >> command) || command == "quit"){
			break;
		}
		else if(command == "push_back"){
			double value; 
			cin >> value;
			v.push_back(value);
			cout << "Pushed back " << fixed << setprecision(4) << value << '\n';
		}
		else if(command == "resize"){
			string line;
			int new_size;
			double initial;
			cin >> new_size;
			getline(cin, line);
			istringstream sin(line);
			if(sin >> initial){
				v.resize(new_size, initial);
			}
			else{
				v.resize(new_size);
			}
		}
		else if(command == "size"){
			cout << v.size() << '\n';
		}
		else if(command == "print"){
			print_all(v);
		}
		else if(command == "get"){
			int index;
			cin >> index;

			try{
				cout << "Value at " << index << " = " << setprecision(4) << fixed << v.at(index) << '\n';
			}
			catch(out_of_range &err){
				cout << err.what() << '\n';
			}
		}
		
		else if(command == "set"){
			double d;
			int index;
			cin >> index >> d;

			try{
				v.at(index) = d;
				cout << "SET: " << index << " = " << setprecision(4) << fixed << v.at(index) << '\n';
			}
			catch(out_of_range &err){
				cout << err.what() << '\n';
			}
		}
		
		else if(command == "clear"){
			v.resize(0);
		}
		
		else{
			cout << "Invalid command '" << command << "'\n";
		}
	}while(true);

	cout << '\n';
	return 0;
}






//Construct new doublevector whose size is 0
doublevector::doublevector(){
	mValues = nullptr;
	mNumValues = 0;
}


//Destruct doublevector - free any resources in mValues
doublevector::~doublevector(){
	if(mNumValues > 0)
		delete mValues;
}


void doublevector::resize(int new_size, double initial_value){
	if(new_size == 0){				//Deletes everything in mValues
		if(mNumValues > 0){
			delete mValues;
			mValues = nullptr;
		}
		mNumValues = 0;
	}
	else if(new_size > mNumValues){	//Grow the vector
		double *newptr = new double [new_size];
		for(int index = 0; index < new_size; index++){
			if(index < mNumValues)	//Copy values to new pointer
				newptr[index] = mValues[index];
			else
				newptr[index] = initial_value;	//Populate new spaces with default values
		}
		if(mNumValues > 0)	//Delete old values in mValues
			delete mValues;
		mValues = newptr;	//mValues now has larger vector
		mNumValues = new_size;
	}
	else if(new_size < mNumValues){//Shrink the vector
		double *newptr = new double [new_size];
		for(int index = 0; index < new_size; index++){
			newptr[index] = mValues[index];	//Copy values to new pointer
		}
		if(mNumValues > 0)
			delete mValues;
		mValues = newptr; //mValues now has smaller vector
		mNumValues = new_size;
	}
}


//Increase size of vector by 1, adding value to bottom of vector
void doublevector::push_back(double value){
	resize(mNumValues + 1, value);
}


//Return a reference to the value at given index
double& doublevector::at(int index){		
	if(index >= mNumValues){	//Check validity of index
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}
	return mValues[index];
}


//Return read-only reference to value at given inde
const double& doublevector::at(int index) const{	
	if(index >= mNumValues){	//Check validity of index
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}
	return mValues[index];
}


//Typecast mNumValues into unsigned long and return it
unsigned long doublevector::size() const{
	return (unsigned long) mNumValues;
}
