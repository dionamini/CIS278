// Dion Amini
// dionamini@my.smccd.edu
// Assignment 1 : creditCard.cpp
#include <iostream>
using namespace std;

int ctoi(char s)
{
	return s - '0';
}

int sum2Digits(int dd)
{
	if(dd < 10)
		return dd;
	else
		return (dd - dd/10*10) + dd/10;
}

string checkNumber(string number) 
{
	if (number.length() != 16 && number.length() != 8)
		return "Invalid";
	
	int d1 = ctoi(number[0]);
	int d2 = ctoi(number[1]);
	int d3 = ctoi(number[2]);
	int d4 = ctoi(number[3]);
	int d5 = ctoi(number[4]);
	int d6 = ctoi(number[5]);
	int d7 = ctoi(number[6]);
	int d8 = ctoi(number[7]);
	int d9 = ctoi(number[8]);
	int d10 = ctoi(number[9]);
	int d11 = ctoi(number[10]);
	int d12 = ctoi(number[11]);
	int d13 = ctoi(number[12]);
	int d14 = ctoi(number[13]);
	int d15 = ctoi(number[14]);
	int d16 = ctoi(number[15]);

	int creditCard;
	
	if(number.length() == 16) 
	{
		int creditCard1 = d16 + d14 + d12 + d10 + d8 + d6 + d4 + d2;
		int creditCard2 = sum2Digits(d15 * 2); 
		creditCard2 += sum2Digits(d13 * 2);
		creditCard2 += sum2Digits(d11 * 2);			
		creditCard2 += sum2Digits(d9 * 2);			
		creditCard2 += sum2Digits(d7 * 2);			
		creditCard2 += sum2Digits(d5 * 2);			
		creditCard2 += sum2Digits(d3 * 2);			
		creditCard2 += sum2Digits(d1 * 2);	
	
		creditCard = creditCard1 + creditCard2;
	} 
	else if(number.length() == 8) 
	{
		int creditCard1 = d8 + d6 + d4 + d2;
		int creditCard2 = sum2Digits(d7 * 2);			
		creditCard2 += sum2Digits(d5 * 2);			
		creditCard2 += sum2Digits(d3 * 2);			
		creditCard2 += sum2Digits(d1 * 2);	
	
		creditCard = creditCard1 + creditCard2;
	}	
	
	if(creditCard % 10 == 0)
		return "Valid";
	else
		return "Invalid";	
}

int main()
{
	while(true) 
	{
		string input;
		cin >> input;
	
		double i = atof(input.c_str());
		if(i < 0) 
		{
			cout << "End of Program\n";
			return 0;
		}
		else
		{
			cout << input << " is " << checkNumber(input) << "\n";
			cout << "Continue\n";
		}
	}			
}