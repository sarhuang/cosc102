//Name: Sarah Huang
//Program: lab3.cpp
//Purpose: Randomly generate 3 integers, store them in an array, and print them out.
//Date: 9/30/20


#include <iostream>
#include <random>

using namespace std;

int main(){
	//Initialize variables
	int seed;
	int slots[3];

	//Asks user to enter the seed, different seed = different results
	cout << "Input a seed: ";
	cin >> seed;
	default_random_engine rng(seed);
	uniform_int_distribution <int> rand_int(2, 7);

	//Fills each index with a random integer and prints them out
	for(int i = 0; i < 3; i++){
		slots[i] = rand_int(rng);
		cout << slots[i] << " ";
	}
	cout << "\n";

	return 0;
}
