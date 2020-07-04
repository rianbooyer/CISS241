/*	Week 5 Programing Assignment 1 - Random Number Guessing Game
Rian Booyer - ccis 241 dea
Version 0.2*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*Write a program that generates a random number between 1 and 100 and asks 
the user to guess what the number is. If the user’s guess is higher than the
random number, the program should display “Too high, try again.” If the user’s
guess is lower than the random number, the program should display “Too low, try again.”
The program must use a loop that repeats until the user correctly guesses the random 
number or has made 10 guesses. The program needs to keep track of the number of guesses 
the user makes. At the end the program will display one of the messages in the table below
based on the number of guesses the user took. The program must validate the user’s guess 
by making sure the value entered is between 1 and 100. If the value is not between 1 and 100,
the user should be told to make another guess. The invalid input should not count as one of 
the 10 guesses the user is allowed.

Number of Guesses by the User	Output Message
Less than 5 guesses	"Either you know the secret or you got lucky!"
5-7 guesses	"You're pretty good at this!"
8-10 guesses	"You'll do better next time."
If guess 10 is not correct	"Sorry - You have taken too many guesses."*/

int main()
{
// define variables
	int guess;
	bool outRange = false;
	const int minVal = 1, maxVal = 100;
	
	srand((unsigned int)time(0));// runs a seed before the random number is generated. For some reason i was only getting 42 over and over
	
	int ranNum = (rand() % (maxVal - minVal + 1)) + minVal; //declares the variable and assigns a random number to it 
	//cout << ranNum<<endl; // outputs the random number, this is for testing purposes only
		
	//start display
	for (int numGuess = 1; numGuess < 10; numGuess++) // loops while there are guesses left
	{

		do /*sets up loop to check and see if values are in range (within 1 to 100)
		     and displays an error if it isn't does not count against number of guesses*/
		{
			/*resets outRange variable because when i would put a guess out of range
			it would just keep repeating afterward even if in range*/
			outRange = false;

			cout << "I'm Thinking Of A Number Between 1 and 100. \nWhat Is The Number I'm Thinking Of? " << endl;
			cin >> guess;
			if (guess < 1 || guess > 100)
				{
					cout << "Remember my number is between 1 and 100." << endl;
					outRange = true;
				}
			} while (outRange);
			
			//start if statements to check the number
			if (guess < ranNum)
				cout << "Too low, try again." << endl;
			else if (guess > ranNum)
				cout << "Too high, try again." << endl;
			else if (guess == ranNum)
			{
				if (numGuess >= 1 && numGuess <= 4)
				{
					cout << "That's My Number!" << endl;
					cout << "Either you know the secret or you got lucky!" << endl;
				}
				else if (numGuess >= 5 && numGuess <= 7)
				{
					cout << "That's My Number!" << endl;
					cout << "You're pretty good at this!" << endl;
				}
				else if (numGuess >= 8 && numGuess <= 10)
				{
					cout << "That's My Number!" << endl;
					cout << "You'll do better next time." << endl;
				}
				return 0;
			}
	}
	cout << "Sorry - You have taken too many guesses." << endl;

	
	return 0;
}