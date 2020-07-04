/*	Week 5 Programing Assignment 2 - Working With Files
Rian Booyer - ccis 241 dea
Version 0.1*/
/*To compile under linux i have to have more includes and use c_string so i'm not going to do that with this program*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Setup Variables outside main to allow calling from multiple functions
ifstream inputFile;
string fileNumbers,vl;
int number, sumNumber=0,b,average,lowestNum = std::numeric_limits<int>::max(), highestNum;

void fileProc(string file)
{
	inputFile.open(file);
	if (inputFile.fail())
	{
		cout << "Opening File Failed: File Missing, Corrupted, Or Programmer DERP Detected" << endl;
		exit(1);
	}
	else
	{
		cout << "|Opening File Succeess" << endl;
	}
	for (int a = 1;inputFile >> number; a++)
	{
		if (number > highestNum)
			highestNum = number;
		if (number < lowestNum)
			lowestNum = number;
		sumNumber = sumNumber + number;
		b = a;
	}
	average = sumNumber / b;
}
int main()
{
	cout << string(41, '-') << endl;
	cout << "|            File Operations            |" << endl;
	cout << string(41, '-') << endl;
	fileProc("Random.txt");//opens and processes file in separate function fileProc
	cout << string(41, '-') << endl;
	cout << "|Number of values  : " << b << endl;
	cout << "|Sum of all numbers: " << sumNumber << endl;
	cout << "|Average of Numbers: " << average<<endl;
	cout << "|Highest Number    : " << highestNum << endl;
	cout << "|Lowest Number     : " << lowestNum << endl;
	cout << string(41, '-') << endl;


	return 0;
}