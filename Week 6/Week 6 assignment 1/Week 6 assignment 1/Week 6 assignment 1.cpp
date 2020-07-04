/*	Week 6 Programing Assignment 1 - Score tests and drop lowest score
Rian Booyer - ccis 241 dea
Version 0.9*/
#include <iostream>
#include <string>
using namespace std;

//global variables
int testScore, testTotal, testAverage;//, lowScore;
static int lowScore;

//predefine functions
void calcAverage(int, int, int, int, int, int);
int findLowest(int, int, int, int, int,int);
void getScore(int &testScore);

int main()
{
	
	// local variables
	int score1,score2,score3,score4,score5,score6;

	//start display
	cout << string(41, '-') << endl;//outputs string that is 41 characters long with the character -
	cout << "|              Test Scores              |" << endl;
	cout << string(41, '-') << endl;
	
	//start asking for input
	cout << "What are the scores for your past 6 tests?"<<endl <<"Scores must be between 0 to 100 percent" << endl;
	cout << "Test 1 Score: ";
	getScore(score1);
	cout << "Test 2 Score: ";
	getScore(score2);
	cout << "Test 3 Score: ";
	getScore(score3);
	cout << "Test 4 Score: ";
	getScore(score4);
	cout << "Test 5 Score: ";
	getScore(score5);
	cout << "Test 6 Score: ";
	getScore(score6);
	cout << string(41, '-') << endl;
	cout << "The total of all tests are: " << testTotal<<endl;
	
	calcAverage(score1,score2,score3,score4,score5,score6);


	return 0;
}
void getScore(int &testScore)
{
	cin >> testScore;

	bool scoreLoop = true;
	
	do // loop added just in case someone enters score out of range more than once.
	{
		if (testScore >= 0 && testScore <= 100)
			scoreLoop = true;
		else if (testScore < 0 || testScore > 100)
		{ 
			cout << "Score is out of range re-enter score: ";
			cin >> testScore;
			scoreLoop = false;
		}
	} while (!scoreLoop);
	
	testTotal = testTotal + testScore;
	
}
void calcAverage(int score1, int score2, int score3, int score4, int score5, int score6)
{
	findLowest(score1, score2, score3, score4, score5, score6);// calls findLowest to find lowest score

	testAverage = (testTotal - lowScore) / 5;//drops lowest score and divides by 5 tests
	cout << "The Lowest Score Is: " << lowScore << " Percent, And Will Be Dropped." << endl;
	cout << "Test Average is: " << testAverage << " Percent."<< endl;

}
int findLowest(int score1, int score2, int score3, int score4, int score5, int score6)
{
	//finds low score and assigns it to lowScore
	lowScore = score1;
	if (score2 < lowScore)
		lowScore = score2;
	else if (score3 < lowScore)
		lowScore = score3;
	else if (score4 < lowScore)
		lowScore = score4;
	else if (score5 < lowScore)
		lowScore = score5;
	else if (score6 < lowScore)
		lowScore = score6;
	return lowScore;

}