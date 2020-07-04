/*	Week 7 Programing Assignment 2 - sales information
Rian Booyer - ccis 241 dea
Version 72.0*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

//global variables
const int COLS = 5;
const int ROWS = 5;
int colTotal;
double colAverage;
int rowTotal;
int highest;
int lowest;
int divHigh = 0;
int divLow = std::numeric_limits<int>::max();
int quartLow = std::numeric_limits<int>::max();
int quartHigh = 0;
int highDiv;
int highQuart;
int lowDiv;
int lowQuart;
int salesTotal = 0;
int salesAverage = 0;

//preload functions
int getInput();
int getTotal(int[][COLS]);
int getAverage(int[][COLS]);
int getRowTotal(int[][COLS],int);
int getColumnTotal(int[][COLS], int);
int getHighest(int[][COLS],int&,int&);
int getLowest(int[][COLS],int&,int&);
int getOutput();
//global arrays
//const string TitleArray[6][5] = { {"Quarter 1","Quarter 2","Quarter 3","Quarter 4","Division\nTotal"},
									//{"North"},{"South"},{"East"},{"West"},{"Quarter Total"} };
const string TitleArray[6][6] = { {"Quarter 1","Quarter 2","Quarter 3","Quarter 4","Division Total"},
									{"North"},{"South"},{"East"},{"West"},{"Quarter Total"} };

/* Uncomment the following line to auto populate salesNumbers and rem getInput declaration and the array definition imediately below*/
//int salesNumbers[ROWS][COLS]= { {1000,5000,9000,13000,0},{2000,6000,10000,14000,0},{3000,7000,11000,15000,0},{4000,8000,12000,16000,0} };
int salesNumbers[ROWS][COLS];

int main()
{
	getInput();
	getTotal(salesNumbers);
	getAverage(salesNumbers);
	getColumnTotal(salesNumbers, 0);
	getColumnTotal(salesNumbers, 1);
	getColumnTotal(salesNumbers, 2);
	getColumnTotal(salesNumbers, 3);
	getColumnTotal(salesNumbers, 4);
	getRowTotal(salesNumbers, 0);
	getRowTotal(salesNumbers, 1);
	getRowTotal(salesNumbers, 2);
	getRowTotal(salesNumbers, 3);
	getRowTotal(salesNumbers, 4);
	getHighest(salesNumbers, divHigh, quartHigh);
	getLowest(salesNumbers, divLow, quartLow);
	getOutput();
	return 0;
}

int getInput()
{
	
	//get inputs for quarter 1
	cout << "Please enter totals for quarter 1." << endl;
	for (int count = 1; count < COLS; count++)
	{
		cout << TitleArray[count][0] << ":";
		cin >> salesNumbers[count - 1][0];

	}
	
	//get inputs for quarter 2
	if (system("CLS")) system("clear");
	cout << "Please enter totals for quarter 2." << endl;
	for (int count = 1; count < COLS; count++)
	{
		cout << TitleArray[count][0] << ":";
		cin >> salesNumbers[count - 1][1];

	}
	//get inputs for quarter 3
	if (system("CLS")) system("clear");
	cout << "Please enter totals for quarter 3." << endl;
	for (int count = 1; count < COLS; count++)
	{
		cout << TitleArray[count][0] << ":";
		cin >> salesNumbers[count - 1][2];

	}
	//get inputs for quarter 4
	if (system("CLS")) system("clear");
	cout << "Please enter totals for quarter 4." << endl;
	for (int count = 1; count < COLS; count++)
	{
		cout << TitleArray[count][0] << ":";
		cin >> salesNumbers[count - 1][3];

	}
	if (system("CLS")) system("clear");
	return 0;
}
int getOutput()
{
	cout << "|" << string(74, '-') << "|" << endl;
	cout << "               " << setw(10) << left << TitleArray[0][0] << setw(10) << left << TitleArray[0][1] <<
		setw(10) << left << TitleArray[0][2] << setw(10) << left << TitleArray[0][3] << setw(10) << left << TitleArray[0][4] << endl;
	cout << setw(13) << left << TitleArray[1][0] << "  " << setw(10) << left << salesNumbers[0][0]
		<< setw(10) << left << salesNumbers[0][1]
		<< setw(10) << left << salesNumbers[0][2]
		<< setw(10) << left << salesNumbers[0][3]
		<< setw(10) << left << salesNumbers[0][4] << endl;
	cout << setw(13) << left << TitleArray[2][0] << "  "
		<< setw(10) << left << salesNumbers[1][0]
		<< setw(10) << left << salesNumbers[1][1]
		<< setw(10) << left << salesNumbers[1][2]
		<< setw(10) << left << salesNumbers[1][3]
		<< setw(10) << left << salesNumbers[1][4] << endl;
	cout << setw(12) << left << TitleArray[3][0] << "   "
		<< setw(10) << left << salesNumbers[2][0]
		<< setw(10) << left << salesNumbers[2][1]
		<< setw(10) << left << salesNumbers[2][2]
		<< setw(10) << left << salesNumbers[2][3]
		<< setw(10) << left << salesNumbers[2][4] << endl;
	cout << setw(12) << left << TitleArray[4][0] << "   "
		<< setw(10) << left << salesNumbers[3][0]
		<< setw(10) << left << salesNumbers[3][1]
		<< setw(10) << left << salesNumbers[3][2]
		<< setw(10) << left << salesNumbers[3][3]
		<< setw(10) << left << salesNumbers[3][4] << endl;
	cout << TitleArray[5][0] << "  "
		<< setw(10) << left << salesNumbers[4][0]
		<< setw(10) << left << salesNumbers[4][1]
		<< setw(10) << left << salesNumbers[4][2]
		<< setw(10) << left << salesNumbers[4][3]
		<< setw(10) << left << salesNumbers[4][4] << endl;
	cout << "|" << string(74, '-') <<"|"<< endl;
	cout << "The Highest Division was: " << setw(5) << left << TitleArray[highDiv][0] << " With: $" << divHigh << endl;
	cout << "The Lowest Division was:  " << setw(5) << left << TitleArray[lowDiv][0] << " With: $" << divLow << endl;
	cout << "|" << string(74, '-') << "|" << endl;
	cout << "The Highest Quarter was: " << setw(5) << left << TitleArray[0][highQuart] << " With: $" << quartHigh << endl;
	cout << "The Lowest Quarter was:  " << setw(5) << left << TitleArray[0][lowQuart] << " With: $" << quartLow << endl;
	cout << "|" << string(74, '-') << "|" << endl;
	cout << "The total is " << salesTotal << endl;
	cout << "The average is: " << salesAverage << endl;
	cout << "|" << string(74, '-') << "|" << endl;
	
	/* the following lines allowed me to troubleshoot the salesNumbers array if you wish to display just uncomment the lines*/
	/*for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLS; y++)
		{
			cout << setw(8) << left << salesNumbers[x][y] << " ";
		}
		cout << endl;
	}*/
	return 0;
}
int getTotal(int[][COLS])
{
	
	for (int row = 0; row < COLS; row++)
	{
		for (int col = 0; col < COLS; col++)
			salesTotal += salesNumbers[row][col];
	}
	// Display the sum.
	//cout << "The total is " << salesTotal << endl;
	return salesTotal;
}

int getAverage(int[][COLS])
{
	
	for (int row = 0; row < COLS; row++)
	{
		for (int col = 0; col < COLS; col++)
			salesAverage += salesNumbers[row][col];
		
	}
	salesAverage = salesAverage / 16;
	// Display the sum.
	
	return salesAverage;
}

int getRowTotal(int[][COLS], int b)
{
	rowTotal = 0;
	for (int count = 0; count < COLS - 1; count++)
	{
		rowTotal += salesNumbers[b][count];
		
	}
	salesNumbers[b][4] = rowTotal;

	return rowTotal;
}

int getColumnTotal(int[][COLS], int b)
{
	colTotal = 0;
	for (int count = 0; count < ROWS - 1; count++)
	{
		colTotal += salesNumbers[count][b];

	}
	salesNumbers[4][b] = colTotal;

	return colTotal;
		
	
}

int getHighest(int[][COLS], int&, int&)
{
	//gets highest division
	for (int count = 0; count < ROWS - 1; count++)
	{
		
		if (salesNumbers[count][4] > divHigh)
		{
			
			divHigh = salesNumbers[count][4];
			highDiv = count;
		}
	
	}

	//gets highest quarter
	for (int count = 0; count < COLS - 1; count++)
	{
		if (salesNumbers[4][count] > quartHigh)
		{
			quartHigh = salesNumbers[4][count];
			highQuart = count;
		}
	}
	return divHigh;
	return highDiv;
	return quartHigh;
	return highQuart;
}

int getLowest(int[][COLS], int&, int&)
{
	for (int count = 0; count < COLS - 1; count++)
	{

		if (salesNumbers[count][4] < divLow)
		{
			divLow = salesNumbers[count][4];
			lowDiv = count+1;
		}
		
	}
	
	//gets highest quarter
	for (int count = 0; count < ROWS ; count++)
	{
		if (salesNumbers[4][count] < quartLow)
		{
			quartLow = salesNumbers[4][count];
			lowQuart = count;
		}
	}
	return divLow;
	return lowDiv;
	return quartLow;
	return lowQuart;
	
}


