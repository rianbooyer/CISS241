#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int  numPeople, pizDiam; 
	int const sliceEat = 3;//const needs their own line or they throw up warnings in the compiler
	double area, numPizza, pRadius, pizSlice;
	double const sliceArea = 14.125, PI = 3.14159;//same as int const but aparently puting multiple variables causes them all to be const
	
	//start input of variables
	cout << "What Diameter of Pizza would you like: ";
	cin >> pizDiam;
	cout << "How many people will be eating pizza: ";
	cin >> numPeople;

	//Performs the calculations for the program.
	pRadius = pizDiam / 2.0;
	area = PI * pow(pRadius, 2); //had to use the pow to raise power of pRadius to calculate area.
	pizSlice = area / sliceArea;
	numPizza = ceil((numPeople * sliceEat) /pizSlice); //ceil forces rounding up even if .1 - .4
	

	
	//output information fixed and setprecision is set to provide correct output for pizSlice and numPizza
	cout << string(41, '-') <<endl; //using to provide an easy separation between the questions and response
	cout << "Number of slices per pizza: " << fixed << setprecision(1)<<  pizSlice << " slices." << endl;
	cout << "Number of Pizza's Required: " << fixed << setprecision(0) <<numPizza << " Pizza's." <<endl;
	cout << string(41, '-')<< endl; // just to make it look better
	return 0;
}