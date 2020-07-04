#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout.setf(ios_base::fixed);
	cout.precision(2);

	//begin by defining variables
	double intRate,intRateP,principal, interest, amountSavings;
	int timesComp;

	//start input prompts
	cout << "What is your accounts principal: $";
	cin >> principal;
	cout << "What is the interest rate on the account: ";
	cin >> intRate; 
	cout << "How many times is interest compounded: ";
	cin >> timesComp;
	
	// calculations
	intRateP = intRate / 100;
	amountSavings =  principal * pow(1+ intRateP / timesComp, timesComp);
	
	

	//output
	cout << string(41, '-');
	cout << "\nInterest Rate: " << intRate << "%" << endl;
	cout << "Times Compounded: " << timesComp << endl;
	cout << "Principal: $" << principal << endl;
	cout << "Interest: $" << (amountSavings - principal) << endl;
	cout << "Ammount in Savings: $" << amountSavings << endl;

	
	return 0;
}