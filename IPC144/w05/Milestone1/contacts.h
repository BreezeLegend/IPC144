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

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

struct Address {
	int StreetNumber;
	int ApartmentNumber;
	char street[41];
	char postalCode[8];
	char city[41];
};

struct Number {
	char cell[21];
	char home[21];
	char business[21];
};

struct Contact {
	struct Name name;
	struct Address address;
	struct Number number;

};
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------
void getName(struct Contact *);

void getAddress(struct Contact *);

void getNumbers(struct Contact *);

