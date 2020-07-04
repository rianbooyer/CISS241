#include <iostream>

using namespace std;

int main()
{

	//define variables
	double area, width, length;

	// Get room width
	cout << "What is the width of the room. ";
	cin >> width;

	//Get Room length
	cout << "What is the length of the room. ";
	cin >> length;

	// Calculate the area
	area = width * length;

	//Display Area
	cout << "The area of the room is: " << area << endl;
	return 0;
	}
