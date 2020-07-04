#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//setup display of 2 decimal points
	cout.setf(ios_base::fixed);
	cout.precision(2);

	// define variables and initialize
	float shares = 600, sPrice = 21.77, bComis = 0.02,stockAlone,comEarned,totalAmountPaid, mustSell;

	//calculate price for 600 shares at $21.77
	stockAlone = shares * sPrice;
	
	
	//calculate ammount of commision
	comEarned = stockAlone * bComis;

	//calculate total ammount paid
	totalAmountPaid = stockAlone + comEarned;

	//display results assuming the profit needed is at least $1 from the total amount paid
	cout << "Price of stocks before commision: $ "
		<< stockAlone
		<< "\nThe ammount of commision is: $"
		<< comEarned
		<< "\nThe total ammount paid for the stock with commission is: $"
		<< totalAmountPaid
		<< "\nThe minimum ammount needed to sell at a profit would be: $"
		<< totalAmountPaid +1 
		<< "\n                                                    Or : $" 
		<< totalAmountPaid /600 
		<< " Per Share."
		<< "\n\nOr basically anything > $"
		<< totalAmountPaid
		<< endl ;
		return 0;
}