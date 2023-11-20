// Name: Imtisal Rasheed
// Summary: A program that asks for the user for the rate, number of payments, and amount of loan and then displays the loan amount, monthly interest rate, montly payment, amount paid back, and the interest number. It also calculates the monthly payment on a loan.
// Most difficult aspect: The most difficult aspect for me was first, figuring out the equations to solve the problem. The professor showed us what equations we should use, and that's how I overcame that. Another difficult problem I had was aligning the numbers evenly. They wouldn't align right, and it would be inconsistent. I overcame this by experiencing with setw() and the fieldiwidth in order to align it properly.
// Amount of time: Around 2-3 hours to complete.
// File name: irA1_2.cpp
// File creation: 9/11/23
/* Revisions:
	* Revision 1: 9/17 added summary to beginning, started working on program
	* Revision 2: 9/18 continued working on program
	* Revision 3: 9/20 Worked on making program look neater, fixed formatting
*/

/* complete chart based on exercise's requirement

Loan amount: $10000
Annual interest rate (in the format .12 (for 12%): 0.12
Number of monthly payments to be made: 36

- - Loan Report - -

Loan Amount:			$ 10000.00
Monthly Interest Rate:		 1.00%
Number of Payments:				36
Monthly Payment:		$	332.14
Amount Paid Back:		$ 11957.15
Interest Paid:			$  1957.15

*/

#include <iostream>	//include preprocessor
#include <iomanip>	//include iomanip library for output
#include <cmath>	//include cmath library for power function

using namespace std;

// main function
int main()
{
	// declaring variables for input
	double loanAmount, annualInterestRate;
	int numberOfPayments;

	// declaring variable that can change
	double adjustedRate, payment, amtPaid, interestPaid, monthlyRate;

	// asks user to enter loan amount and then assign loan amount to loanAmount variable
	cout << "Loan amount: $";
	cin >> loanAmount;

	// asks user for the annual interest rate to enter it in decimal form and then assign it to annualInterestRate
	cout << "Anuual interest rate (in the format .12 (for 12%): ";
	cin >> annualInterestRate;

	// asks user for monthly payments that need to be made and then assign it to numberOfPayments
	cout << "Number of monthly payments to be made: ";
	cin >> numberOfPayments;

	// calculate monthly interest rate
	monthlyRate = annualInterestRate / 12;

	// calculate the adjusted rate
	adjustedRate = pow((1 + monthlyRate), numberOfPayments);

	// calculate total monthly payment
	payment = ((monthlyRate * adjustedRate) / (adjustedRate - 1)) * loanAmount;

	// calculate the amount paid back
	amtPaid = payment * numberOfPayments;

	// calculate the amount of interest paid
	interestPaid = amtPaid - loanAmount;

	// declare variable for field width
	const int fieldWidth = 8;

	// output all the information with the calculations made and original input entered by user
	cout << fixed << setprecision(2) << showpoint
		<< " " << endl
		<< "- - Loan Report - -\n"
		<< " " << endl
		<< "Loan Amount:			$ " << setw(fieldWidth) << loanAmount << endl
		<< "Monthly Interest Rate:		 " << setw(fieldWidth) << (monthlyRate * 100) << "%" << endl
		<< "Number of Payments		  " << setw(fieldWidth) << numberOfPayments << endl
		<< "Monthly Payment:		$ " << setw(fieldWidth) << payment << endl
		<< "Amount Paid Back:		$ " << setw(fieldWidth) << amtPaid << endl
		<< "Interest Paid:			$ " << setw(fieldWidth) << interestPaid << endl;

}	// end of function