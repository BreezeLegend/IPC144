/* -------------------------------------------
Name: Victor Hasnat
Student number: 119485183
Email: vhasnat@myseneca.ca
Section: NPP
Date: November 8, 2019

----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:

void getName(struct Name* name) {
   char option; 

   printf("Please enter the contact's first name: ");
   scanf("%s", &name->firstName);
   printf("Do you want to enter a middle initial(s)? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's middle initial(s): ");
      scanf("%s", &name->middleInitial);
   }
   printf("Please enter the contact's last name: ");
   scanf("%s", &name->lastName);
}
// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:

void getAddress(struct Address* address) {
   char option; 

   printf("Please enter the contact's street number: ");
   scanf("%d", &address->streetNumber);
   printf("Please enter the contact's street name: ");
   scanf("%s", &address->street);
   printf("Do you want to enter an apartment number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's apartment number: ");
      scanf("%d", &address->apartmentNumber);
   }
   printf("Please enter the contact's postal code: ");
   scanf(" %[^\n]s", &address->postalCode);
   printf("Please enter the contact's city: ");
   scanf("%s", &address->city);
}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:

void getNumbers(struct Numbers* numbers) {
   char option; 

   printf("Do you want to enter a cell phone number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's cell phone number: ");
      scanf("%s", &numbers->cell);
   }
   printf("Do you want to enter a home phone number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's home phone number: ");
      scanf("%s", &numbers->home);
   }
   printf("Do you want to enter a business phone number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's business phone number: ");
      scanf("%s", &numbers->business);
   }
   printf("\n");
}