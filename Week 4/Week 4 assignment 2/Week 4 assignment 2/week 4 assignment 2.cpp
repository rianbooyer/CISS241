/*	Week 4 Programing Assignment 2 - Long Distance Calls
Rian Booyer - ccis 241 dea
Version 0.0.2*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//start universal variables
float startTime, startFrac, callTime, callFrac, costPerMin, totalCost;
const float rate1 = 0.12f, rate2 = 0.23f, rate3 = 0.55f, rate4 = 0.35f;
string temp;
void pressEnter()
{
	cout << "Press Enter to Continue";
	temp = cin.get();
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}
void calcCost()
{
	totalCost = callTime * costPerMin;
	cout << "The cost for this call would be: $" << fixed << setprecision(2) << totalCost << endl;
	pressEnter();
}

int main()
{
	
start: //loop label
	if (system("CLS")) system("clear"); //clear screen
	
	// print out menu title
	cout << string(41, '-') << endl;
	cout << "|            Long Distance Calls        |" << endl;
	cout << string(41, '-') << endl;
	
	//start main display and questions
	cout << "enter start time with decimal hh.mm: ";
	cin >> startTime;
	cout << "Enter Call Time as mmm.ss: ";
	cin >> callTime;
	startFrac = startTime - static_cast<int>(startTime);
	callFrac = callTime - static_cast<int>(callTime);
	
	
	if (startTime <= 23.59 && startTime >= 00.00)
	{
		if (startFrac <= 0.59 && startFrac >= 0.0) 
		{
			if (callFrac <= 0.59 && callFrac >= 0.0)
			{
				if (startTime >= 00.00 && startTime <= 05.59)
				{
					costPerMin = rate1;
					calcCost();
				}
				else if (startTime >= 06.00 && startTime <= 12.59)
				{
					costPerMin = rate2;
					calcCost();
				}
				else if (startTime >= 13.00 && startTime <= 19.59)
				{
					costPerMin = rate3;
					calcCost();
				}
				else if (startTime >= 20.00 && startTime <= 23.59)
				{
					costPerMin = rate4;
					calcCost();
				}
			}
			else
			{
				cout << "Do not enter calltime above ##.59 seconds" << endl;
				pressEnter();
				goto start;
			}
		}
		
		else
		{
			cout << "Do not enter minutes above xx.59 " <<endl;
			pressEnter();
			goto start;
		}

	}
	else 
	{
		cout << "Invalid Time - Time MUST be betwen 00.00 and 23.59" <<endl;
		pressEnter();
		goto start;
	}
	
	return 0;
}