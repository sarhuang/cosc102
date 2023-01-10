//Name: Sarah Huang
//Program: lab3.cpp
//Purpose: Manage the user's coins, determine if the user won on the "slot machine", add
//		   and subtract the appropriate amounts of coins, and run continously until the 
//		   user has run out of coins or no longer wants to bet.
//		   The program checks the user's input every time for non-integer values.
//		   The program also prints a summary of all bets and transactions.
//Date: 9/30/20


#include <iostream>
#include <random>
#include <limits>

using namespace std;


int main(){
	//Initialize variables
	int seed;
	int slots[3];
	int coins = 100;
	int bet;
	bool all_7s = false; //Will be used to determine if the slot machine numbers are all 7s
	vector<int> all_bets;
	vector<int> all_wins;


	//Asks user to enter the seed, different seed = different results
	//Asks user again if given a non-integer answer
	cout << "Input a seed: ";
	while(!(cin >> seed)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Input a seed: ";
	}
	default_random_engine rng(seed);
	uniform_int_distribution <int> rand_int(2, 7);
	cout << "\n";



	//First remind the user how many coins they have and ask how much to bet
	//Will only take integers 0 and above
	cout << "You currently possess " << coins << " coins.\n";
	cout << "Bet how many coins? ";
	while(!(cin >> bet) || bet < 0 || bet > coins){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bet how many coins? ";
	}

	
	//If the user enters 0 for the first bet, the program will stop running
	if(bet == 0){
	
	}
	else{

		//This is the START of the loop that will continue until the user has 0 coins or places 0 bets
		while(bet >= 0){ 
			if(bet == 0){
				cout << "\n";	
				break;	
			}
			else{
				coins -= bet; //Subtracts the bet from the total coins
				all_bets.push_back(bet);
			}

			//Fills each index with a random integer and prints them out
			for(int i = 0; i < 3; i++){
				slots[i] = rand_int(rng);
				cout << slots[i] << " ";
			}
			cout << "\n";
		

			//If all three numbers equal 7, the all_7s variable will be true
			//It is used to differentiate between all 7s or all of numbers 1-6
			if(slots[0] == 7 && slots[1] == 7 && slots[2] == 7)
				all_7s = true;
			else
				all_7s = false;
		
	
			if(slots[0] != slots[1] && slots[1] != slots[2] && slots[0] != slots[2]){		//No matching numbers
				cout << "You did not win.";
				all_wins.push_back(0);
			}
			else if(all_7s){																//All numbers are 7s
				cout << "You won " << (bet*10) << " coins!";
				coins += (bet*10);
				all_wins.push_back(bet*10);
			}
			else if(slots[0] == slots[1] && slots[1] == slots[2] && slots[0] == slots[2]){	//3 numbers are the same
				cout << "You won " << (bet*5) << " coins!";
				coins += (bet*5);
				all_wins.push_back(bet*5);
			}
			else if(slots[0] == slots[1] || slots[1] == slots[2] || slots[0] == slots[2]){	//2 numbers are the same
				cout << "You won " << (bet*2) << " coins!";
				coins += (bet*2);
				all_wins.push_back(bet*2);
			}
			cout << "\n\n";
		
		
			//If the user runs out of coins, the program stops
			if(coins == 0)
				break;

	
			//Updates the user on how many coins in possession and asks for another bet
			//Asks again until an integer is 0 or greater
			cout << "You currently possess " << coins << " coins.\n";
			cout << "Bet how many coins? ";
			while(!(cin >> bet) || bet < 0 || bet > coins){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Bet how many coins? ";
			}
		}




		//Play summary
		cout << "Play Summary:\n";

		//Initialize all maximums and minimums to a value in case it's already correct
		int max_bet = all_bets.at(0); 
		int min_bet = all_bets.at(0);
		int max_win = all_wins.at(0);
		int min_win = all_wins.at(0);

		for(int unsigned i = 0; i < all_bets.size(); i++){
			if(all_bets.at(i) > max_bet)	//Checks for max wager
				max_bet = all_bets.at(i);
			if(all_bets.at(i) < min_bet)	//Checks for min wager
				min_bet = all_bets.at(i);
			if(all_wins.at(i) > max_win)	//Checks for max prize
				max_win = all_wins.at(i);
			if(all_wins.at(i) < min_win)	//Checks for min prize
				min_win = all_wins.at(i);

			cout << "You wagered " << all_bets.at(i) << " coins and won " << all_wins.at(i) << " coins.\n";
		}
		
		cout << "\nYour minimum wager was " << min_bet << " coins.\n";
		cout << "Your maximum wager was " << max_bet << " coins.\n";
		cout << "Your minimum prize was " << min_win << " coins.\n";
		cout << "Your maximum prize was " << max_win << " coins.\n";
			

	}

	return 0;
}
