// Name:Victor Hasnat
// Student Number:
// Email:vhasnat@myseneca.ca
// Section:NLL
// Workshop:2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double amount, Balance;
	int Loonies, Quarters;


	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	Loonies = amount / 1;
	Balance = amount - Loonies;

	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, Balance);

	Quarters = Balance / .25;
	Balance = Balance - (Quarters * 0.25);

	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, Balance);

	return 0;
}