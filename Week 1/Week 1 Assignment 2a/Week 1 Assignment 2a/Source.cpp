#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double Rprice, StaxP, Stax, total;
	
	//following two lines sets decimal places to 2 decimal placess even if they are null so instead of 2.1 you get 2.10
	cout.setf(ios_base::fixed);
	cout.precision(2);
	
	//get price
	cout << "What is the price of the item? ";
	cin >> Rprice;

	//get sales tax rate
	cout << "what is the sales tax rate percentage? ";
	cin >> StaxP;
	

	//Calculate Sales Tax
	Stax = (StaxP / 100) * Rprice;

	cout << "Sales Tax Ammount: $ " << Stax << endl;

	//calculate total with tax
	total = ((StaxP / 100) + 1) * Rprice;

	cout << "Your Total Is: $" << total << endl;
	
	return 0;

}