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
#include <ctype.h>
// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

#include "contacts.h" // This is added, might need to remove

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// pause:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void) {
	char NL = 'x';
	int value = 0;
	int toReturn = 0;
	while (NL != '\n') {
		scanf("%d%c", &value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
		else
			toReturn = value;
	}
	return toReturn;
}


// getIntInRange:
int getIntInRange(int min, int max) {
	int done = 0;
	int toReturn = 0;
	//printf("Enter 'seneca', then '99', then '501', then '250' >");
	do {
		int entered = getInt();
		if (entered >= min && entered <= max) {
			done = 1;
			toReturn = entered;
		}
		else {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}

	} while (done == 0);
	return toReturn;
}

// yes:
int yes(void) {
	char NL = 'x';
	char value = ' ';
	int done = 0;
	int toReturn = 0;
	do {
		while (NL != '\n') {
			scanf("%c%c", &value, &NL);
			if (NL != '\n') {
				clearKeyboard();
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			}
			else if ((value == 'y' || value == 'Y') && NL == '\n') {
				done = 1;
				toReturn = 1;
			}
			else if ((value == 'n' || value == 'N') && NL == '\n') {
				done = 1;
				toReturn = 0;
			}
		}
	} while (done == 0);
	return toReturn;
}


// menu:
int menu(void) {
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");
	//getInt and intinrange
	int choice = getIntInRange(0, 6);
	printf("\n");
	//get int
	return choice; // Change the return
}


// contactManagerSystem:
void contactManagerSystem(void) {


	struct Contact contact[MAXCONTACTS] = {
			{
				{ "Rick",{ '\0' }, "Grimes" },
				{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
				{ "4161112222", "4162223333", "4163334444" } },
				{
					{ "Maggie", "R.", "Greene" },
					{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
					{ "9051112222", "9052223333", "9053334444" } },
					{
						{ "Morgan", "A.", "Jones" },
						{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
						{ "7051112222", "7052223333", "7053334444" } },
						{
							{ "Sasha",{ '\0' }, "Williams" },
							{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
							{ "9052223333", "9052223333", "9054445555" } },
	};

	int option = 0;
	int done = 0;
	do {
		option = menu();
		switch (option) {
		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			//printf("\n<<< Feature 3 is unavailable >>>\n\n");
			updateContact(contact,MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			//printf("\n<<< Feature 4 is unavailable >>>\n\n");
			deleteContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			//printf("\n<<< Feature 5 is unavailable >>>\n\n");
			searchContacts(contact, MAXCONTACTS);
			//displayContactHeader();
			// displayContact();

			pause();
			printf("\n");
			break;
		case 6:
			//printf("<<< Feature to sort is unavailable >>>\n\n");
			sortContact(contact, MAXCONTACTS);
			printf("--- Contacts sorted! ---\n\n");
			pause();
			printf("\n");
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			int confirm = yes();
			if (confirm == 1) {
				printf("\nContact Management System: terminated\n");
				done = 1;
				break;
			}
			else printf("\n");

			break;
		}
	} while (done == 0);
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

void getTenDigitPhone(char phoneNum[])
{
	int i = 0;
	int needInput = 1;
	int totalNumbers = 0;
	while (needInput == 1) {
		scanf("%10s", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10) {
			for (i = 0; i < 10; i++) {
				if (isdigit(phoneNum[i]) != 0)
					totalNumbers++;
				else
					break;
			}

			if (totalNumbers == 10) {
				needInput = 0;
				//Add phoneNum to pointer
				
			}
			else {
				totalNumbers = 0;
				printf("Enter a 10-digit phone number: ");
			}
		}
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i = 0;
	int found = 0;
	int result = -1;

	for (i = 0; i < size; i++) {
		found = strcmp(contacts[i].numbers.cell, cellNum);
		if (found == 0) {
			result = i;

			break;
		}
	}
	//return -1;
	return result;
}

// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
// Put empty function definition below:
void displayerContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
	if (strcmp(contact->name.middleInitial, "") == 0)
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	else
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial,
			contact->name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell,
			contact->numbers.home, contact->numbers.business);

	if (contact->address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber,
			contact->address.street, contact->address.apartmentNumber, 
			contact->address.city, contact->address.postalCode);
	else
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, 
			contact->address.street, contact->address.city, contact->address.postalCode);
}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
	int i;
	int count = 0;
	displayContactHeader();

	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) != 0) {
			displayContact(&contacts[i]);
			count++;
		}
	}
	displayerContactFooter(count);
	/*displayContactHeader();
	int checkIfCell = 0;
	int totalPeople = 0;
	int i = 0;
	for (i = 0; i < size; i++) {
		checkIfCell = strlen(contacts[i].numbers.cell);
		if (checkIfCell > 0) {
			displayContact(&contacts[i]);
			totalPeople++;
		}
	}

	displayerContactFooter(totalPeople);*/
}

// :
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
	char cellNum[11];
	int i = 0;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	//printf("\n");
	i = findContactIndex(contacts, size, cellNum);
	if (i != -1){
		printf("\n");
		displayContact(&contacts[i]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n\n");
}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
	int i = 0;
	int availableIndex = -1;
	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) == 0) { //if no number
			availableIndex = i;
			break;
		}
	}
	if (availableIndex > -1) {
		getContact(&contacts[availableIndex]);
		printf("--- New contact added! ---\n\n");
	} else
		printf("*** ERROR: The contact list is full! ***\n\n");
}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
	int index = -1;
	char cellNum[11];
	int answer = 0;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	index = findContactIndex(contacts,size,cellNum);
	if (index > -1) {
		printf("\nContact found:\n");
		displayContact(&contacts[index]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		answer = yes();
		if (answer == 1) 
			getName(&contacts[index].name);
		
		printf("Do you want to update the address? (y or n): ");
		answer = yes();
		if (answer == 1) 
			getAddress(&contacts[index].address);
		
		printf("Do you want to update the numbers? (y or n): ");
		answer = yes();
		if (answer == 1)
			getNumbers(&contacts[index].numbers);

		printf("--- Contact Updated! ---\n\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n\n");
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
	int index = -1;
	char cellNum[11];
	int answer = 0;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	index = findContactIndex(contacts, size, cellNum);
	if (index > -1) {
		printf("\nContact found:\n");
		displayContact(&contacts[index]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		answer = yes();
		if (answer == 1) {
			strcpy(contacts[index].numbers.cell, "\0");
			printf("--- Contact deleted! ---\n\n");
		}
		else
			printf("\n");
	}
}

// sortContacts:
// Put empty function definition below:
void sortContact(struct Contact contacts[], int size)
{
	struct Contact temp[1];
	int i,j;
	for (i=0; i < size - 1; i++){
		for (j = i+1; j < size; j++){
			if (strcmp(contacts[i].numbers.cell,contacts[j].numbers.cell)>0){
				temp[0] = contacts[i];
				contacts[i] = contacts[j];
				contacts[j] = temp[0];
			}
		}
	}
}