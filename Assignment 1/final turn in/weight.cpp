// Dion Amini
// dionamini@my.smccd.edu
// Assignment 1: weight.cpp
#include <iostream>
using namespace std;


int ftToInch(int extra)
{
	return (extra - 5)*12;
}


int main()
{
	cout << "How many sets of weights do you want to determine?\n";
	int sets;
	cin >> sets;
	if (sets <= 0)
	{
		cout << "Invalid response.\n";
		return 0;
	}
	
	do
	{
		cout << "How tall are you in feet?\n";
		int footInput;
		cin >> footInput;
		
		if (footInput < 5)
		{
			cout << "Program only works with 5 feet or taller.\n";
		}
		else
		{
		
			cout << "You are " << footInput << "ft tall and how many inches?\n";
			int inchInput;
			cin >> inchInput;
			int extras = ftToInch(footInput);
	
			int weight = 110 + (extras + inchInput)*5;
	
			cout << "Your ideal body weight should be " << weight << " pounds.\n";
			sets--;
		
		}
	} while(sets > 0);
	return 0;
}
