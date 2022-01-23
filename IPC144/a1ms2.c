/* -------------------------------------------
Name: Victor Hasnat
Student number: 119485183
Email: vhasnat@myseneca.ca
Section:IPC 144 SYV
Date:2018-11-2
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"





void Clear() {
	while (getchar() != '\n');
}

int main(void) {
	// Declare variables here:

	struct [Contact contact1[] = { {0} };

	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:
    getName(contact1);
	// Contact Address Input:
	getAddress(contact1);
	// Contact Numbers Input:
	getNumbers(contact1);

	// Display Contact Summary Details
	printf("\n\nContact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", contact1[0].name.firstName);
	printf("Middle initial(s): %s\n", contact1[0].name.middleInitial);
	printf("Last name: %s\n\n", contact1[0].name.lastName);
	printf("Address Details\n");
	printf("Street number: %d\n", contact1[0].address.StreetNumber);
	printf("Street name: %s\n", contact1[0].address.street);
	printf("Apartment: %d\n", contact1[0].address.ApartmentNumber);
	printf("Postal code: %s\n", contact1[0].address.postalCode);
	printf("City: %s\n\n", contact1[0].address.city);

	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n", contact1[0].number.cell);
	printf("Home phone number: %s\n", contact1[0].number.home);
	printf("Business phone number: %s\n", contact1[0].number.business);

	// Display Completion Message
	printf("\nStructure test for Name, Address, and Numbers Done!");


	return 0;
}


void getName(struct Contact *contact) {
	char middle;
	printf("Please enter the contact's first name: ");
	scanf("%29s", contact[0].name.firstName);
	Clear();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &middle);
	Clear();
	if (middle == 'y' || middle == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", contact[0].name.middleInitial);
		Clear();
	}

	printf("Please enter the contact's last name: ");
	scanf("%35s", contact[0].name.lastName);
	Clear();

}



void getAddress(struct Contact *contact) {
	char middle;
	printf("Please enter the contact's street number : ");
	scanf("%d", &contact[0].address.StreetNumber);
	Clear();

	printf("Please enter the contact's street name: ");
	scanf("%36[^\n]", contact[0].address.street);
	Clear();

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%c", &middle);
	Clear();

	if (middle == 'y' || middle == 'Y') {

		printf("Please enter the contact's apartment number: ");
		scanf("%d", &contact[0].address.ApartmentNumber);
		Clear();
	}

	printf("Please enter the contact's postal code: ");
	scanf("%8[^\n]", contact[0].address.postalCode);
	Clear();

	printf("Please enter the contact's city: ");
	scanf("%41[^\n]", contact[0].address.city);
	Clear();

}


void getNumbers(struct Contact *contact) {
	char middle;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("%c", &middle);
	Clear();
	if (middle == 'y' || middle == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%20s", contact[0].number.cell);
		Clear();
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%c", &middle);
	Clear();
	if (middle == 'y' || middle == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf("%20s", contact[0].number.home);
		Clear();
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("\n%c", &middle);
	Clear();
	if (middle == 'y' || middle == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf("%20s", contact[0].number.business);
		Clear();
	}

}