#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//following two lines sets decimal places to 2 decimal placess even if they are null so instead of 2.1 you get 2.10
	cout.setf(ios_base::fixed);
	cout.precision(2);

	double Sbal, Dep, WithD, IntRate, IntRateP, Intr, NewBalance;

	// get starting balance
	cout << "What is the starting balance? ";
	cin >> Sbal;

	// Get Total Deposits
	cout << "What is the total of all deposits made? ";
	cin >> Dep;

	//get total of withdrawals
	cout << "What is the total of all withdrawals? ";
	cin >> WithD;

	// get interest rate
	cout << "What is the interest rate on the account % ";
	cin >> IntRate;

	//convert Intrest rate to decimal
	IntRateP = IntRate / 100;

	//calculate the interest ammount earned
	Intr = (Sbal + Dep - WithD) * IntRateP;
	
	//calculate the new balance
	NewBalance = (Sbal + Dep - WithD) * (IntRateP +1);

	cout << "\nAmount You have earned from interest this month: $" << Intr << "\nYour New Balance Is: $" << NewBalance << endl;
	return 0;
}