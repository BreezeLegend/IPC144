/* -------------------------------------------
Name: Victor H	
Student number: 119485183
Email: vhasnat@myseneca.ca		
Section: NLL
Date: March 8,2020
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"
// getName:
void getName(struct Name* name) {
  int answer = 0;

   printf("Please enter the contact's first name: ");
   scanf("%[^\n]s", name->firstName);
   printf("Do you want to enter a middle initial(s)? (y or n): ");
   answer = yes();
switch (answer) {
	case 1:
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]c", name->middleInitial);
		clearKeyboard();
		break;
	default:
		break;
	}

    printf("Please enter the contact's last name: ");
   scanf(" %[^\n]s", name->lastName);
}

// getAddress:
void getAddress(struct Address* address) {
  int aptNum = 0;
	int streetNum = 0;
	int answer = 0;
	printf("Please enter the contact's street number: ");
	do {
		
		//scanf("%d", &address->streetNumber);
		//clearKeyboard();
		streetNum = getInt();
		if (streetNum < 0){
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		}
	} while (streetNum < 1);
	address->streetNumber = streetNum;
	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]c", address->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	answer = yes();


	switch (answer) {
	case 1:
		printf("Please enter the contact's apartment number: ");
		do {
			aptNum = getInt();
			//scanf("%d", &address->apartmentNumber);
			//clearKeyboard();
		if (aptNum <0 ){
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
		}
		} while (aptNum < 1);
		address->apartmentNumber = aptNum;
		break;

		default:
		break;
	}

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]c", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%41[^\n]c", address->city);
	clearKeyboard();
}

// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers* numbers) {
   int option;
   
   printf("Please enter the contact's cell phone number: ");
   getTenDigitPhone(numbers->cell);
   printf("Do you want to enter a home phone number? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's home phone number: ");
      getTenDigitPhone(numbers->home);
   }
   else {
      strcpy(numbers->home, "\0");
   }
   printf("Do you want to enter a business phone number? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's business phone number: ");
      getTenDigitPhone(numbers->business);
   }
   else {
      strcpy(numbers->business, "\0");
   }
}
// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact) {
   getName(&contact->name);
   getAddress(&contact->address);
   getNumbers(&contact->numbers);   
}