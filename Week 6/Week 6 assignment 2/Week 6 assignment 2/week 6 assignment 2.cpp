/*	Week 6 Programing Assignment 2 - rock, paper....lizard,spock
Rian Booyer - ccis 241 dea
Version 0.6*/

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

//Global Variables
int compChoice,userChoice;//int for random number variable for computers choice and number for user's choice
string choice,winnerIs;// prints out the choices
const int minVal = 1, maxVal = 5;
const int rock = 1, paper = 2, scissors = 3, lizard = 4, spock = 5;
bool someoneWon = true;

//define functions
int getUserChoice();
int getComputerChoice();
void determineWinner(int, int);
void displayChoice(int);
string choiceMeans(int &ch);

int main()
{
	//local variables
	

	// seed timer
	srand((unsigned int)time(0));
	
	do // loops while there isn't a winner
	{
		if (system("CLS")) system("clear"); //clears screen
		//output menu
		cout << string(41, '-') << endl;//outputs string that is 41 characters long with the character -
		cout << "|   Rock,Paper,Scisors,Lizard,Spock     |" << endl;
		cout << string(41, '-') << endl;


		getComputerChoice();
		//compChoice = 5;
		getUserChoice();
		choiceMeans(compChoice);
		displayChoice(compChoice);
		choiceMeans(userChoice);
		determineWinner(compChoice, userChoice);


		//someoneWon = true;
	} while (!someoneWon);
	return 0;
}
/*choiceMeans originally designed to do the same function as displayChoice but after I coded displayChoice
choiceMeans was not needed however i decided to use it to display what the user chooses.*/
string choiceMeans(int &ch)
{
	
	if (ch == 1)
		choice = "Rock";
	if (ch == 2)
		choice = "Paper";
	if (ch == 3)
		choice = "Scisors";
	if (ch == 4)
		choice = "Lizard";
	if (ch == 5)
		choice = "Spock";
	//cout << "Your choice is: " << choice << endl;
		return choice;
}
int getUserChoice()
{
	cout << "| Lets Play Pick Your Weapon!" << endl<<endl;
	cout << "| 1. Rock" << endl;
	cout << "| 2. Paper" << endl;
	cout << "| 3. Scissors" << endl;
	cout << "| 4. Lizard" << endl;
	cout << "| 5. Spock" << endl;
	cout << string(41, '-') << endl;
	cout << "Pick Your Weapon: ";
	cin >> userChoice;

	return userChoice;

}
int getComputerChoice()
{
	compChoice = (rand() % (maxVal - minVal + 1)) + minVal;
	return compChoice;
}
void determineWinner(int, int)
{/* would love to figure out a better way to do this without multiple if statements*/
	if (compChoice == 1)//rock
	{
		if (userChoice == 1)//rock
		{
			cout << "Rocks Roll away to join a band...."<<endl;
			cout << "It's a Tie!";
			someoneWon = false;
		}
		else if (userChoice == 2)//paper
		{
			cout << "Paper covers rock" << endl;
			cout << "Computer Wins!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 3)//scissors
		{
			cout << "Rock breaks scissors" << endl;
			cout << "Computer Wins!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 4)//lizard
		{
			cout << "Rock crushes lizzard" << endl;
			cout << "Computer Wins!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 5)//spock
		{
			cout << "Spock vaporizes rock" << endl;
			cout << "You Win!" << endl;
			someoneWon = true;
		}
	}

	if (compChoice == 2)//paper
	{
		if (userChoice == 1)//rock
		{
			cout << "Paper covers rock" << endl;
			cout << "Computer Wins!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 2)//paper
		{
			cout << "Paper flies off with paper..."<<endl;
			cout << "It's a Tie!";
			someoneWon = false;
			
		}
		else if (userChoice == 3)//scissors
		{
			cout << "Scissors Cuts Paper" << endl;
			cout << "You Win!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 4)//lizard
		{
			cout << "Lizard eats paper" << endl;
			cout << "You Win!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 5)//spock
		{
			cout << "Paper disproves Spock" << endl;
			cout << "You loose!" << endl;
			someoneWon = true;
		}
	}
	
	if (compChoice == 3)//scissors
	{
		if (userChoice == 1)//rock
		{
			cout << "Rock breaks scissors" << endl;
			cout << "You Win!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 2)//paper
		{
			cout << "Scissors Cuts Paper" << endl;
			cout << "Computer Wins!" << endl;
			someoneWon = true;

		}
		else if (userChoice == 3)//scissors
		{
			cout << "It's a Tie!"<<endl;
			someoneWon = false;

		}
		else if (userChoice == 4)//lizard
		{
			cout << "Scissors decapitate lizzard" << endl;
			cout << "Computer Win!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 5)//spock
		{
			cout << "Spock melts scissors" << endl;
			cout << "You win!" << endl;
			someoneWon = true;
		}
	}
		
	if (compChoice == 4)//lizard
	{
		if (userChoice == 1)//rock
		{
			cout << "Rock crushes lizard"<<endl;
			cout << "You Win!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 2)//paper
		{
			cout << "Lizard eats paper" << endl;
			cout << "Computer Wins!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 3)//scissors
		{
			cout << "Scissors decapitate lizzard" << endl;
			cout << "You Win!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 4)//lizard
		{
			cout << "Lizard stares at lizard with funny look..." << endl;
			cout << "It's a Tie!" << endl;
			someoneWon = false;
		}
		else if (userChoice == 5)//spock
		{
			cout << "Lizard poisons Spock" << endl;
			cout << "Computer Wins!" << endl;
			someoneWon = true;
		}
	}

	if (compChoice == 5)//Spock
	{
		if (userChoice == 1)//rock
		{
			cout << "Spock vaporizes rock"<<endl;
			cout << "Computer Wins!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 2)//paper
		{
			cout << "Paper disproves Spock" << endl;
			cout << "You Win!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 3)//scissors
		{
			cout << "Spock melts scissors" << endl;
			cout << "Computer Wins!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 4)//lizard
		{
			cout << "lizard poisons Spock" << endl;
			cout << "You Win!" << endl;
			someoneWon = true;
		}
		else if (userChoice == 5)//spock
		{
			cout << "Spock looks at Spock, realizes it's a mirror..." << endl;
			cout << "It's a tie!" << endl;
			someoneWon = false;
		}
	}
}
void displayChoice(int)
{

	if (compChoice == 1)
		choice = "Rock";
	if (compChoice == 2)
		choice = "Paper";
	if (compChoice == 3)
		choice = "Scisors";
	if (compChoice == 4)
		choice = "Lizard";
	if (compChoice == 5)
		choice = "Spock";
	cout << "Computer Chooses: " << choice << endl;
}
