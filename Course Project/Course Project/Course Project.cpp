/*	Week 8 Course Project - Airline Reservation
Rian Booyer - ccis 241 dea
Version 1.ungodly ammount of versions*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//global variables
const int ROWS = 15,COLS = 6,totalSeats = 80;
int totalSeatsbooked = 0, totalSeatsAvailable = 0, ecoCoachBooked = 0, coachBooked = 0, firstBooked = 0, menuSelection, rowNum=0, rowNumAvail=0;
double firstCostTotal = 0, CoachCostTotal = 0, ecoCoachCostTotal = 0, fcPrice, coachPrice, ecoPrice, seatsPriceTotal;
bool isNumTrue = true;
string fileName = "SeatPrices.txt";

//predefine functions
int rowSeatCount(int a);
double seatBooked();
double populateSeatPriceArray();
void seatAvailableConvert(bool a[][COLS]);
void reserveSeatsMenu();
void totalSeatsMenu();
void seatsEmptyMenu();
void pressEnter();
double isNum(double);
void showSeatingChart();

//define global arrays

//for true/false for if the seats are available
bool seatAvailable[ROWS][COLS];

//char array for checking if seatAvailable bool is 0 or 1, 0 for x and 1 for *
char seatIsBooked[ROWS][COLS]; 

//array for seat prices that is populated from SeatPrices.txt
double seatPrices[3]; 

//start functions
int main()
{
	bool quit = 0;
	populateSeatPriceArray();
	bool mainMenutf = true;
	while (mainMenutf)
	{
		seatAvailableConvert(seatAvailable);
		showSeatingChart();
		seatBooked();

		cout << "Please Enter Selection: ";
		cin >> menuSelection;
		
		switch (menuSelection)
		{
		case 1://reserve seat
			reserveSeatsMenu();
			break;
		case 2://Total Seats
			totalSeatsMenu();
			break;
		case 3:// Seats Empty
			seatsEmptyMenu();
			break;
		case 4://quit
			return 0;
			break;
		
		default:
			break;
		}
	}
	return 0;
}

// Primary functions of program

/*PopulateSeatPriceArray - this array opens the seatPrices.txt file and populates the seatPrices array and assigns 
variables based on the classes of seating for further calculations later on. If the file isn't present it prompts
the user to create the file, if the user choses n then it exits the program. If the user selects y then the program
prompts the user for the price per seat for each class of seats then stores them into the seatPrices array and
populates a new SeatPrices.txt file. Name of the file can be changed in an above fileName variable. */
double populateSeatPriceArray()
{
	string arrayline;
	char pspyn;


	ifstream seatPricesFileOpen(fileName);
	//opens price array file and populates it from file
	if (seatPricesFileOpen.is_open())
	{

		for (int cs = 0;cs < 3; cs++)
		{
			getline(seatPricesFileOpen, arrayline, ',');
			double i_arrayline = stod(arrayline);
			seatPrices[cs] = i_arrayline;
		}

	}
	seatPricesFileOpen.close();
	//checks to see if array file is open and if it fails to open allows user to create and populate a new file before array is populated
	if (seatPricesFileOpen.fail())
	{
		cout << "ERROR: cannot open " << fileName << "for input to array" << endl;
		cout << "Do you wish to create a new file and populate it? Y/n ";
		cin >> pspyn;
		if (pspyn == 'N' || pspyn == 'n')
		{
			cout << "You chose not to populate file. Program will close" << endl;
			pressEnter();
			exit(1);
		}
		if (pspyn == 'Y' || pspyn == 'y')
		{
			cout << "Please input prices for the following classes:" << endl;
			do
			{
				cout << "First Class: ";
				cin >> fcPrice;
				isNum(fcPrice);//passes fcPrice to isNum function to make sure alpha chars are not entered
			} while (isNumTrue);
			do
			{
				cout << "Coach Class: ";
				cin >> coachPrice;
				isNum(coachPrice);
			} while (isNumTrue);
			do
			{
				cout << "Economy Class: ";
				cin >> ecoPrice;
			} while (isNumTrue);
			seatPrices[0] = fcPrice;
			seatPrices[1] = coachPrice;
			seatPrices[2] = ecoPrice;


			//opens/creates for output.
			ofstream spPopulate(fileName);
			////checks if file is open and if so populates array.
			if (spPopulate.is_open())
			{
				cout << "Populating File" << endl;

				for (int cs = 0; cs < 3; cs++)
				{
					spPopulate << seatPrices[cs] << ",";
				}
				spPopulate.close();



			}
			//Re-opens price array file and populates it from file
			ifstream seatPricesFileOpen(fileName);
			if (seatPricesFileOpen.is_open())
			{

				for (int cs = 0;cs < 3; cs++)
				{
					getline(seatPricesFileOpen, arrayline, ',');
					double i_arrayline = stod(arrayline);
					seatPrices[cs] = i_arrayline;
				}

			}
			//force close of file
			seatPricesFileOpen.close();
		}

	}
	//assigns earlier price inputs to the array
	fcPrice = (double)(seatPrices[0]);
	coachPrice = (double)(seatPrices[1]);
	ecoPrice = (double)(seatPrices[2]);
	return fcPrice;
	return coachPrice;
	return ecoPrice;
}

/*seatAvailableConvert - converts bool values from seatAvailable array to char values and stores them in the
seatIsBooked array for display in the outputDisplay function. If the seat is booked (true bool) the program 
displays an asterix, if the seat is available (false bool) then it displays an # */
//converts bool values from one array to char's for display
void seatAvailableConvert(bool a[][COLS])
{
	int num;
	char r = ' ';
	for (int rs = 0; rs < ROWS; rs++)
	{
		for (int cs = 0; cs < COLS; cs++)
		{

			num = a[rs][cs];
			if (num == 0)
				r = '#';
			else if (num == 1)
				r = '*';
			seatIsBooked[rs][cs] = r;


		}

	}
}

/*seatBooked -  adds up booked seats and calculates totals for seats used and total prices.*/
double seatBooked()
{
	int num;
	totalSeatsbooked = 0;
	totalSeatsAvailable = 0;
	firstCostTotal = 0;
	CoachCostTotal = 0;
	ecoCoachCostTotal = 0;
	ecoCoachBooked = 0;
	coachBooked = 0;
	firstBooked = 0;
	for (int rs = 0; rs < ROWS - 10; rs++)
	{
		for (int cs = 0; cs < COLS; cs++)
		{

			num = seatAvailable[rs][cs];
			firstBooked = firstBooked + num;
		}
	}
	int numb = 0;
	for (int rs = 0; rs < ROWS; rs++)
	{
		for (int cs = 0; cs < COLS; cs++)
		{
			if (rs >= 5 && rs <= 9)
			{
				numb = seatAvailable[rs][cs];
				coachBooked = coachBooked + numb;
			}
			if (rs >= 10 && rs <= 15)
			{
				numb = seatAvailable[rs][cs];
				ecoCoachBooked = ecoCoachBooked + numb;
			}

		}
	}
	firstCostTotal = firstBooked * fcPrice;
	CoachCostTotal = coachBooked * coachPrice;
	ecoCoachCostTotal = ecoCoachBooked * ecoPrice;
	seatsPriceTotal = firstCostTotal + CoachCostTotal + ecoCoachCostTotal;
	totalSeatsbooked = firstBooked + coachBooked + ecoCoachBooked;
	totalSeatsAvailable = totalSeats - totalSeatsbooked;
	return totalSeatsAvailable;
	return firstCostTotal;
	return CoachCostTotal;
	return ecoCoachCostTotal;
	return ecoCoachBooked;
	return firstBooked;
	return coachBooked;
	return ecoCoachBooked;
}

/*rowSeatCount - counts available seats in a specified row*/
int rowSeatCount(int a)
{
	int num;
	rowNumAvail = 0;

	char r = ' ';
	if (a >= 0 && a <= 4)
	{
		for (int cs = 0; cs < COLS - 2; cs++)
		{
			num = seatAvailable[a][cs];
			if (num == 0)
				rowNumAvail++;

		}
	}
	if (a >= 5 && a <= 14)
	{
		for (int cs = 0; cs < COLS; cs++)
		{
			num = seatAvailable[a][cs];
			if (num == 0)
				rowNumAvail++;

		}
	}

	return rowNumAvail;
}

//Menu functions

/*reserveSeatMenu - for reserving seats asks for row and seat input 
then checks if it is available, if available it can 
reserve it, if taken you can cancel reservation.*/
void reserveSeatsMenu()
{
	int sn;
	int rn;
	bool rsn;
	bool reserveSeatsLoop = false;
	bool seatCheck = true;
	char yn;


	while (!reserveSeatsLoop)
	{
		do
		{
			seatCheck = true;
			if (system("CLS")) system("clear");
			cout << char(0xc9) << string(43, char(0xcd)) << char(0xbb) << endl;
			cout << char(0xba) << string(10, ' ') << "Seat Reservation System" << string(10, ' ') << char(0xba) << endl;
			cout << char(0xc8) << string(43, char(0xcd)) << char(0xbc) << endl;

			cout << " Input Row Number: ";
			cin >> rn;
			rn = rn - 1;
			cout << " Input Seat Number: ";
			cin >> sn;
			sn = sn - 1;

			if (rn >= 0 && rn <= 4)
			{
				if (sn >= 0 && sn <= 3)
				{
					rsn = seatAvailable[rn][sn];
					seatCheck = true;
				}
				else if (sn >= 4)
				{
					cout << "Invalid Seat Number Enter Again." << endl;
					pressEnter();
					seatCheck = false;

				}

			}
			else if (rn >= 5 && rn <= 14)
			{
				if (sn >= 0 && sn <= 5)
					rsn = seatAvailable[rn][sn];
				else if (sn >= 6)
				{
					cout << "Invalid Seat Number Enter Again." << endl;
					pressEnter();
					seatCheck = false;
				}
			}
			else seatCheck = true;
		} while (!seatCheck);
		if (rsn == 0)
		{
			cout << "Seat is available. \nDo you wish to reserve Y/n? ";
			cin >> yn;
			if (yn == 'y' || yn == 'Y')
			{
				seatAvailable[rn][sn] = 1;
				reserveSeatsLoop = true;
			}
			if (yn == 'n' || yn == 'N')
			{
				break;
			}

		}
		if (rsn == 1)
		{
			cout << "Seat is not available. \nDo you wish to cancel reservation y/N? ";
			cin >> yn;

			if (yn == 'y' || yn == 'Y')
			{
				seatAvailable[rn][sn] = 0;
				reserveSeatsLoop = true;
			}
			if (yn == 'n' || yn == 'N')
			{
				break;
			}
			pressEnter();
			reserveSeatsLoop = true;
		}
	}
	seatAvailableConvert(seatAvailable);
	showSeatingChart();

}

/* displays seat and pricing totals information broken down
to 3 different classes of seats First Class, Coach Class, and Economy Class
then displays totals of seats available per class and total seats available*/
void totalSeatsMenu()
{
	seatBooked();
	seatsPriceTotal = (firstBooked * fcPrice) + (coachBooked * coachPrice) + (ecoCoachBooked * ecoPrice);
	if (system("CLS")) system("clear");
	cout << char(0xc9) << string(43, char(0xcd)) << char(0xbb) << endl;
	cout << char(0xba) << string(15, ' ') << "Seating Totals" << string(14, ' ') << char(0xba) << endl;
	cout << char(0xcc) << string(43, char(0xcd)) << char(0xb9) << endl;
	cout << char(0xba) << char(0xda) << string(26, char(0xc4)) << char(0xc2) << string(14, char(0xc4)) << char(0xbf) << char(0xba) << endl;
	cout << char(0xba) << char(0xb3) << string(5, ' ') << "Seats Sold" << string(11, ' ') << char(0xb3) << "Pricing Totals" << char(0xb3) << char(0xba) << endl;
	cout << char(0xba) << char(0xc3) << string(26, char(0xc4)) << char(0xc5) << string(14, char(0xc4)) << char(0xb4) << char(0xba) << endl;
	cout << char(0xba) << char(0xb3) << setw(24) << left << "First class sold: " << setw(2) << firstBooked << char(0xb3) << "$ " << setw(12) << left << firstCostTotal << char(0xb3) << char(0xba) << endl;
	cout << char(0xba) << char(0xb3) << setw(24) << left << "Coach class sold: " << setw(2) << coachBooked << char(0xb3) << "$ " << setw(12) << left << CoachCostTotal << char(0xb3) << char(0xba) << endl;
	cout << char(0xba) << char(0xb3) << setw(24) << left << "Eco   class Sold: " << setw(2) << ecoCoachBooked << char(0xb3) << "$ " << setw(12) << left << ecoCoachCostTotal << char(0xb3) << char(0xba) << endl;
	cout << char(0xba) << char(0xb3) << setw(24) << left << "Total seats sold: " << setw(2) << totalSeatsbooked << char(0xb3) << "$ " << setw(12) << left << seatsPriceTotal << char(0xb3) << char(0xba) << endl;
	cout << char(0xba) << char(0xc3) << string(26, char(0xc4)) << char(0xc5) << string(14, char(0xc4)) << char(0xb4) << char(0xba) << endl;
	cout << char(0xba) << char(0xb3) << setw(24) << left << "First class available: " << setw(2) << 20 - firstBooked << char(0xb3) << setw(14) << left << " " << char(0xb3) << char(0xba) << endl;
	cout << char(0xba) << char(0xb3) << setw(24) << left << "Coach Class available: " << setw(2) << 30 - coachBooked << char(0xb3) << setw(14) << left << " " << char(0xb3) << char(0xba) << endl;
	cout << char(0xba) << char(0xb3) << setw(24) << left << "Eco   Class available: " << setw(2) << 30 - ecoCoachBooked << char(0xb3) << setw(14) << left << " " << char(0xb3) << char(0xba) << endl;
	cout << char(0xba) << char(0xb3) << setw(24) << left << "Total seats available: " << setw(2) << totalSeatsAvailable << char(0xb3) << setw(14) << left << " " << char(0xb3) << char(0xba) << endl;
	cout << char(0xba) << char(0xc0) << string(26, char(0xc4)) << char(0xc1) << string(14, char(0xc4)) << char(0xd9) << char(0xba) << endl;
	cout << char(0xc8) << string(43, char(0xcd)) << char(0xbc) << endl;
	pressEnter();
}

/* shows display asks for row number and
displays seats available in the row.*/
void seatsEmptyMenu()
{
	if (system("CLS")) system("clear");
	cout << char(0xc9) << string(43, char(0xcd)) << char(0xbb) << endl;
	cout << char(0xba) << string(15, ' ') << "Seats Empty" << string(17, ' ') << char(0xba) << endl;
	cout << char(0xba) << "For the following enter the row number to  " << char(0xba) << endl;
	cout << char(0xba) << "see how many seats are available.          " << char(0xba) << endl;
	cout << char(0xba) << "Total seats available: " << setw(20) << left << totalSeatsAvailable << char(0xba) << endl;
	cout << char(0xc8) << string(43, char(0xcd)) << char(0xbc) << endl;
	cout << "Enter row number: ";
	cin >> rowNum;
	rowSeatCount(rowNum - 1);
	cout << "Seats available in row " << rowNum << " are: " << rowNumAvail << endl;
	pressEnter();

}

/*The following functions are Miscellaneous functions.*/

/*isNum - can be called to check cin input to make sure 
it's a number and displays an error if it isn't*/
double isNum(double)
{
	int temp;

	if (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cout << "Invalid Input - Only Enter Numbers\n";
		cout << "Press Enter To Continue";
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		temp = cin.get();
		isNumTrue = 1;
	}
	else
	{
		isNumTrue = 0;
	}
	return 0;
}

/*pressEnter - called when it's necessary to press enter to continue.*/
void pressEnter()
{
	int temp;
	cout << "Press Enter to Continue";
	temp = cin.get(); //gets value from cin and assigns it to temp unsure how this works though
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*ShowSeatingChart - outputs information for the main screen */
void showSeatingChart()
{
	int colMod;
	if (system("CLS")) system("clear");
	cout << char(0xc9) << string(43, char(0xcd)) << char(0xbb) << endl;
	cout << char(0xba) << string(13, ' ') << "Latveria Airlines" << string(13, ' ') << char(0xba) << endl;
	cout << char(0xcc) << string(43, char(0xcd)) << char(0xb9) << endl;
	cout << char(0xba) <<setw(29)<<left <<"\t1 2\tFirst Class\t3 4" << char(0xba) << endl;
	cout << char(0xcc) << string(43, char(0xcd)) << char(0xb9) << endl;
	for (int row = 0; row < 5; row++)
	{
		cout << char(0xba) << "Row " << (row + 1) << "\t";
		for (int col = 0; col < 4; col++)
		{
			colMod = (col + 1) % 2;
			cout << seatIsBooked[row][col] << " ";
			if (col == 3)
			cout << setw(8)<<left<<" "<< char(0xba);
			if (colMod == 0)
				cout << setw(20) << left << " " ;
		}
		cout << endl;
	}
	cout << char(0xcc) << string(43, char(0xcd)) << char(0xb9) << endl;
	cout << char(0xba) << setw(33) << left << "\t1 2 3\tPremium Coach\t4 5 6" << char(0xba) << endl;
	cout << char(0xcc) << string(43, char(0xcd)) << char(0xb9) << endl;
	colMod = 0;
	for (int row = 5; row < 10; row++)
		{
			cout << char(0xba) << "Row " << (row + 1) << "\t";
			for (int col = 0; col < 6; col++)
			{
				colMod = (col + 1) % 3;
							cout << seatIsBooked[row][col] << " ";
							if (col == 5)
								cout << setw(6) << left << " " << char(0xba);
							if (colMod == 0)
								cout << setw(18) << left << " ";
			}
			cout << endl;
		}
	cout << char(0xcc) << string(43, char(0xcd)) << char(0xb9) << endl;
	cout << char(0xba) << setw(33) << left << "\t1 2 3\tEconomy Coach\t4 5 6" << char(0xba) << endl;
	cout << char(0xcc) << string(43, char(0xcd)) << char(0xb9) << endl;
	colMod = 0;
	for (int row = 10; row < 15; row++)
	{
		cout << char(0xba) << "Row " << (row + 1) << "\t";
		for (int col = 0; col < 6; col++)
		{
			colMod = (col + 1) % 3;
			cout << seatIsBooked[row][col] << " ";
			if (col == 5)
				cout << setw(6) << left << " " << char(0xba);
			if (colMod == 0)
				cout << setw(18) << left << " ";
		}
		cout << endl;
	}
	cout << char(0xcc) << string(43, char(0xcd)) << char(0xb9) << endl;
	cout << char(0xba) << " 1. Reserve Seats 2. Seating Totals        " << char(0xba) << endl;
	cout << char(0xba) << " 3. Seats Empty   4. Quit" << string(18, ' ') << char(0xba) << endl;
	cout << char(0xc8) << string(43, char(0xcd)) << char(0xbc) << endl;
}