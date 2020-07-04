/*	Week 4 Programing Assignment 1 - Geometry Calculator
	Rian Booyer - ccis 241 dea
	Version 0.5*/

/* Includes - the only reason for so many includes is i've been using a linux compiler for fun to test the program and math.h, cstdlib, must be uncommented
if you wish to compile under linux using g++ -o executablename filename.cpp
UPDATE: uncommented cstdlib because of random errors stating that cout is ambiguous
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
//#include <math.h>
#include <limits>
using namespace std;

string temp; //variable stored outside functions because it is used in multiple functions
bool isNumTrue = true;
 /*isneg function put here so I don't have to keep retyping the same code over and over making the program longer on the screen and having to change
it in multiple places so makes things short and sweet*/

void isneg() {
	
	cout << "Please enter a NON-NEGATIVE number!" << endl;
	cout << "Press Enter to Continue";
	temp = cin.get(); //gets value from cin and assigns it to temp unsure how this works though
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//found through google still analyzing
	

}
/*function screenClear allows me to call the code inside to display "press enter to continue" and when the enter key is pressed
it clears the screen so that when the loop inside main is called it allows for a fresh screen to display */
void screenClear()
{
		//puts press enter to continue then clears screen
		cout << "Press Enter to Continue";
		temp = cin.get(); //gets value from cin and assigns it to temp unsure how this works though
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//found through google still analyzing
		if (system("CLS")) system("clear");//found through google
}

int main()
{
	//setting precision to 2 so you don't get the 9.123e+10 output with large numbers
	cout.setf(ios_base::fixed);
	cout.precision(2);
	//define variables
	int menuSelection;
		
	//variables for circle and sphere
	double const PI = 3.1415;
	double cArea, sArea, radius;

	//variables for rectangle
	double rArea, rWidth, rLength;

	//variables for Triangle
	double triArea, triLength, triHeight;

	//variables for trapezoid
	double tBase1, tBase2, tHeight, tArea;

	//set bool values to get rid of goto statements
	bool isNumTrue = true;
	bool caseTrue = true;
	
	do {// loop that makes sure you enter menu options <6 and not negative
		do
			{// loop to make sure input is not alpha

			
		
		if (system("CLS")) system("clear");
		
#pragma region menu



		// print out menu title
		cout << string(41, '-') << endl;//outputs string that is 41 characters long with the character -
		cout << "|          Geometry Calculator          |" << endl;
		cout << string(41, '-') << endl;

		//Print out menu
		cout << "1. Calculate the Area of a Circle" << endl;
		cout << "2. Calculate the Area of a Rectangle" << endl;
		cout << "3. Calculate the Area of a Triangle" << endl;
		cout << "4. Calculate the Area of a Trapezoid" << endl;
		cout << "5. Calculate the Area of a Sphere" << endl;
		cout << "6. Exit Program" << endl;

		//label for goto statement if invalid input is selected
		cout << "Please enter selection: ";
		cin >> menuSelection;
		if (!cin) // or if(cin.fail())
		{
			// user didn't input a number
			cout << "Invalid Input - Only Enter Numbers\n";
			cout << "Press Enter To Continue";
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			temp = cin.get();
			isNumTrue = 1;															   // next, request user reinput
		}
		else
		{
			isNumTrue = 0;
		}
			} while (isNumTrue);
#pragma endregion		
		//start using switch for menue operations
		
		
	switch (menuSelection)
		{
#pragma region case1Sphere
		case 1:
			//starting loops for checks of alpha and negative numbers.
			do
			{
				do
				{
					if (system("CLS")) system("clear"); //clears screen before displaying quesions

					// print out title
					cout << string(41, '-') << endl;
					cout << "|            Area Of Circle             |" << endl;
					cout << string(41, '-') << endl;

					//start with questions neccessary
					cout << "What is the Radius of the Circle? ";
					cin >> radius;
					if (!cin) // or if(cin.fail())
					{
						// user didn't input a number
						cout << "Invalid Input - Only Enter Numbers\n";
						cout << "Press Enter To Continue";
						cin.clear(); // reset failbit
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
						temp = cin.get();
						isNumTrue = 1;															   // next, request user reinput
					}
					else
					{
						isNumTrue = 0;
					}
				
				} while (isNumTrue);
			//if statement to check for negative numbers and restart if necessary
				if (radius < 0) {
					isneg(); //calls to isneg function to displays an error if one is detected and restarts problem
					
					caseTrue = 1;
				}
				else
				{
					caseTrue = 0;
				}
			} while (caseTrue);
				//calculate area and display answer
				cArea = PI * pow(radius, 2);
				cout << "The area of the circle is: " << cArea << endl;
			
			//puts press enter to continue then clears screen
			screenClear();

			break;
#pragma endregion
#pragma region case2rectangle

		case 2:
			
		do
			{// loop for caseTrue
				do
					{//loop for rHeight
						do
						{// loop for rLength
							//clears screen and prints title
							if (system("CLS")) system("clear");
							
							// print out title
							cout << string(41, '-') << endl;
							cout << "|           Area Of Rectangle           |" << endl;
							cout << string(41, '-') << endl;
				
							//start with questions neccessary for Rectangle Area
				
								cout << "What is the rectangles length: ";
								cin >> rLength;
								if (!cin) // or if(cin.fail())
								{
									// user didn't input a number
									cout << "Invalid Input - Only Enter Numbers\n";
									cout << "Press Enter To Continue";
									cin.clear(); // reset failbit
									cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
									temp = cin.get();
									isNumTrue = 1;															   // next, request user reinput
								}
								else
								{
									isNumTrue = 0;
									caseTrue = 0;
								}
						} while (isNumTrue);
				
								cout << "What is the rectangles width: ";
								cin >> rWidth;
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
					} while (isNumTrue);

							//if statement to check for negative numbers and restart if necessary
							if (rLength < 0 || rWidth < 0) {
								isneg();
								caseTrue = 1;
								}
							else
							{
								caseTrue = 0;
								
							}
				
		} while (caseTrue);

			// Do the calculations		
			rArea = rLength *rWidth;
			cout << "The area of the Rectangle is: " << rArea << endl;

			//puts press enter to continue then clears screen
			screenClear();
			break;
#pragma endregion
#pragma region case3Triangle
		case 3:
			do //loop caseTrue
			{
				do {// loop isNumTrue for triHeight
						do // loop isNumTrue for triLength
						{
							//clears screen and prints title
							if (system("CLS")) system("clear");
							// print out title
							cout << string(41, '-') << endl;
							cout << "|           Area Of Triangle            |" << endl;
							cout << string(41, '-') << endl;
							
							//start with questions neccessary for Triangle Area
							cout << "What is the Triangle's Base Length: ";
							cin >> triLength;
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
						} while (isNumTrue);
						
						cout << "what is the Triangle's Height: ";
						cin >> triHeight;
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
					} while (isNumTrue);
					
					//if statement to check for negative numbers and restart if necessary
					if (triLength < 0 || triHeight < 0) {
						isneg();
						caseTrue = 1;
					}
					else
					{
						
						caseTrue = 0;
					}
				
			} while (caseTrue);

			//Calculate Area and display answer
			triArea = triLength * triHeight * 0.5;
			cout << "The area of the Triangle is: " << triArea << endl;

			//puts press enter to continue then clears screen
			screenClear();
			break;
#pragma endregion
#pragma region case4Trapezoid
	case 4:
		do { // loop for caseTrue
			do {//for tbase2
				do { //loop for tBase 1
					do { //loop for tHeight
						//clears screen and prints title
						if (system("CLS")) system("clear");

						// print out title
						cout << string(41, '-') << endl;
						cout << "|           Area Of Trapezoid           |" << endl;
						cout << string(41, '-') << endl;

						//start with questions neccessary Trapezoid
						cout << "What is the Trapezoid's Height: ";
						cin >> tHeight;
						if (!cin) // or if(cin.fail())
						{
							// user didn't input a number
							cout << "Invalid Input - Only Enter Numbers\n";
							cout << "Press Enter To Continue";
							cin.clear(); // reset failbit
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
							temp = cin.get();
							isNumTrue = 1;															   // next, request user reinput
						}
						else
						{
							isNumTrue = 0;
						}
					} while (isNumTrue);//for tHeight
					cout << "What is the length of the first base: ";
					cin >> tBase1;
					if (!cin) // or if(cin.fail())
					{
						// user didn't input a number
						cout << "Invalid Input - Only Enter Numbers\n";
						cout << "Press Enter To Continue";
						cin.clear(); // reset failbit
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
						temp = cin.get();
						isNumTrue = 1;															   // next, request user reinput
					}
					else
					{
						isNumTrue = 0;
					}

				} while (isNumTrue);// for tBase1

				cout << "what is the length of the second base: ";
				cin >> tBase2;
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
			
			} while (isNumTrue);// for tBase2

			//if statement to check for negative numbers and restart if necessary
			if (tBase1 < 0 || tHeight < 0 || tBase2 < 0) {
				isneg();
				caseTrue = 1;
				
			}
			else
			{
				caseTrue = 0;
				
			}

		} while (caseTrue);
		
			//calculate and display trapezoid area
			tArea = (tHeight / 2) * (tBase1 + tBase2);
			cout << "The Trapezoid's Area Is: " << tArea << endl;

			//puts press enter to continue then clears screen
			screenClear();
			break;
#pragma endregion
#pragma region case5Sphere
			case 5:
				do {//loop for caseTrue
					do {// loop for radius
						//clears screen and prints title
						if (system("CLS")) system("clear");
						// print out title
						cout << string(41, '-') << endl;
						cout << "|            Area Of Sphere             |" << endl;
						cout << string(41, '-') << endl;

						//start with questions neccessary Sphere
						cout << "What is the Radius of the Sphere? ";
						cin >> radius;
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
					} while (isNumTrue);//for radius
					//if statement to check for negative numbers and restart if necessary
					if (radius < 0)
					{
						isneg();
						caseTrue = 1;
					}
					else
					{
						caseTrue = 0;
						
					}
				} while (caseTrue);

			//calculate area and display answer
			sArea = 4 * PI*pow(radius, 2);
			cout << "The Area of the Sphere is: " << sArea << endl;

			//puts press enter to continue then clears screen
			screenClear();

			break;
#pragma endregion
#pragma region case6Exit

		case 6:
			//clears screen and thanks user for using program
			if (system("CLS")) system("clear");
			cout << string(41, '-') << endl;
			cout << "|    Thank You For Using Our Program.   |" << endl;
			cout << string(41, '-') << endl;
			return 0;
			break;
#pragma endregion
#pragma region default
		default: 
			
			cout << "Please enter a valid menu item of 1 to 6!" << endl;
			screenClear();
			} 
#pragma endregion
		
	}while (menuSelection < 6);

}