//Dion Amini
//dionamini@my.smccd.edu
//paint.cpp
#include <iostream>
#include <cmath>
using namespace std;

const double LABOR_COST = 18.00;
const double PAINT_COST = 15.00;
const double SQFT_PER_GAL = 115.00;

void getRoomSize(int& squareFt)  
// prompts user for the size of the ‘next’ room, 
// and returns this size by reference. This function 
// would be called once for every room to be painted
{
	int sqftInput;
	cout << "How many square feet is your room?" << endl;
	cin >> sqftInput;
	if (sqftInput < 50)
	do
	{
		cout << "Invalid square footage input." << endl;
		cout << "How many square feet is your room?" << endl;
		cin >> sqftInput;
	} while(sqftInput < 50);
	
	squareFt += sqftInput;
}

int paintRequired(int squareFt) 
	// returns gallons of paint required 
	// This function is to be written RECURSIVELY!!  You may assume
    // that Joe will only buy full gallons of paint, so, a job that is 150 sq ft will take 2 gallons.
{

	if (squareFt <= 0)
		return 0;
	if (squareFt <= 115)
		return 1;
	else
		return 1 + (paintRequired(squareFt - 115));
	
	// double paint;
	// paint = ceil(squareFt / SQFT_PER_GAL);
	// return paint;
}

double computeLabor(int squareFt) 
	// returns the hours of labor required
{
	double laborHours;
	laborHours = ((squareFt / SQFT_PER_GAL) * 8.0);
	
	return laborHours;
}
 
double jobCost(int gallons, double hours) 
	// returns the cost of the job, provided with 
	// paint quantity and labor hours required 
{
	
	double paintCost;
	paintCost = gallons * PAINT_COST;
	double laborCharge;
	laborCharge = hours * LABOR_COST;
	
	return paintCost + laborCharge;
}
int main()
{
	
	int numberOfRooms;

	
	cout << "How many rooms are to be painted?" << endl;
	cin >> numberOfRooms;
	
	if (numberOfRooms < 1)
	do
	{
		cout << "Invalid number of rooms." << endl;
		cout << "How many rooms are to be painted?" << endl;
		cin >> numberOfRooms;
	} while (numberOfRooms < 1);
	 
	int sqftInput = 0;

	for(int i = 0; i < numberOfRooms; i++) 
	{
		getRoomSize(sqftInput);		
	}	
	 
	int paintNeed = paintRequired(sqftInput);
	double hoursNeed = computeLabor(sqftInput);

	cout << paintNeed << " gallons of paint required" << endl;
	cout << "$" << (paintNeed * PAINT_COST) << " is the cost of paint" << endl;
	cout << hoursNeed << " is the amount of hours needed" << endl;
	cout << "$" << (hoursNeed * LABOR_COST) << " is the cost of labor" << endl;
	cout << "$" << jobCost(paintNeed,hoursNeed) << " is the total cost of the job." << endl;
	
	return 0;
}
