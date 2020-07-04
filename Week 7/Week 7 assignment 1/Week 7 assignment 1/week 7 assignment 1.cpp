/*	Week 7 Programing Assignment 1 - Rainfall Ammounts
Rian Booyer - ccis 241 dea
Version 0.8*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//global variables

const int NumMonths = 12;
double rainTotal = 0;
double rainAverage = 0.00;
int rainLowest = 9999;
int rainHighest = 0;
int lowMonth;
int highMonth;

//preload functions

static double getTotal(double[], int);
double getAverage(double[], int);
double getLowest(double[], int, int&);
double getHighest(double[], int, int&);
void displayOutput(double, double, double, double);
bool getInput();

//Global Arrays
double rainFallAmmounts[12];
const string monthsOfYear[NumMonths] = { "January","February","March","April","May",
										"June","July","August","September","October",
															"November","December" };

int main()
{
	getInput();
	getTotal(rainFallAmmounts, NumMonths);
	getAverage(rainFallAmmounts, NumMonths);
	getLowest(rainFallAmmounts, NumMonths, rainLowest);
	getHighest(rainFallAmmounts, NumMonths, rainHighest);
	displayOutput(rainTotal, rainAverage, rainLowest, rainHighest);
	
	return 0;
}
bool getInput()
{
	cout << "|---------------------------------------------------|" << endl;
	cout << "|                 Rainfall Ammounts                 |" << endl;
	cout << "|---------------------------------------------------|" << endl;
	cout << "|Please enter the rainfall for the following months.|" << endl;
	cout << "|---------------------------------------------------|" << endl;
	for (int count = 0; count < 12; count++) //displays month name from monthsOfYear then asks for input and stores in rainFallAmmount
	{
		cout << "| " << monthsOfYear[count] << ": ";
		cin >> rainFallAmmounts[count];
	}

	return 1;
}
double getTotal(double [], int)
{
	
	for (int count = 0; count < NumMonths; count++)
	{
		rainTotal += rainFallAmmounts[count];
	}
	return rainTotal;
}

double getAverage(double[], int)
{
	rainTotal = 0;
	for (int count = 0; count < NumMonths; count++)
		rainTotal += rainFallAmmounts[count];
	rainAverage = rainTotal / NumMonths;
	
	return rainAverage;
}
double getLowest(double[], int, int&)
{
	for (int count = 0; count < NumMonths; count++)
	{
		if (rainFallAmmounts[count] < rainLowest)
		{
			rainLowest = (int)(rainFallAmmounts[count]);
			lowMonth = count;
		}
	}
	
	return rainLowest;
}
double getHighest(double[], int, int&)
{
	for (int count = 0; count < NumMonths; count++)
	{
		if (rainFallAmmounts[count] > rainHighest)
		{
			rainHighest = (int)(rainFallAmmounts[count]);
			highMonth = count;
		}
	}
	
	return rainHighest;
}
void displayOutput(double, double, double, double)
{
	cout << "|---------------------------------------------------|" << endl;
	cout << "|                 Totals                            |" << endl;
	cout << "|---------------------------------------------------|" << endl;
	cout << "|Total Rain for the year was: " << rainTotal << endl;
	cout << "|Average Rain for the year Was: " << rainAverage << endl;
	cout << "|Month with the highest rainfall: " << monthsOfYear[highMonth] << endl;
	cout << "|Month with the lowest rainfall: " << monthsOfYear[lowMonth] << endl;
	cout << "|---------------------------------------------------|" << endl;
}