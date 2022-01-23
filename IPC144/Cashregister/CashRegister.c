// Name:Victor Hasnat
// Student Number:
// Email:vhasnat@myseneca.ca
// Section:NLL
// Workshop:2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double amount, Balance, GST;
	int Loonies, Quarters, Dimes, Nickels, Pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);
    
	GST = amount * .13 + .005;
	printf("GST: %.2lf\n", GST);
	
	Balance = amount + GST;
	printf("Balance owing: $%.2lf\n", Balance);

	Loonies = Balance / 1;
	Balance = Balance - Loonies;

	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, Balance);

	Quarters = Balance / .25;
	Balance = Balance - (Quarters * 0.25);

	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, Balance);

	Dimes = Balance / .10;
	Balance = Balance - (Dimes * 0.10);

	printf("Dimes required: %d, balance owing $%.2lf\n", Dimes, Balance);

	Nickels = Balance / 0.05;
	Balance = Balance - (Nickels * 0.05);

	printf("Nickels required: %d, balance owing $%.2lf\n", Nickels , Balance);

	Pennies = Balance / .01;
	Balance = Balance - (Pennies * 0.01);

	printf("Pennies required: %d, balance owing $%.2lf\n", Pennies, Balance);


	return 0;
}