/* -------------------------------------------
Name: Victor Hasnat
Student number: 119485183
Email: vhasnat@myseneca.ca
Section: NPP
Date: November 11, 2019
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
   int streetNumber;
   char street[41];
   int apartmentNumber;
   char postalCode[8];
   char city[41];
};

// Structure type Numbers declaration
// Place your code here...
// NOTE: Modify the C String arrays sizes according to the
//       Assignment-2 Milestone-1 specifications
struct Numbers {
   char cell[11];
   char home[11];
   char business[11];
};


// Structure type Contact declaration
// NOTE:  Make sure the structure name does not have an 's' on the end!
// Place your code here...
struct Contact {
   struct Name name;
   struct Address address;
   struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function prototypes here...              |
// +-------------------------------------------------+


// Place your code here...
void getName(struct Name* name);


// Place your code here...
void getAddress(struct Address* address);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers* numbers);

// Get and store from standard input the values for a Contact (NOT: Contacts)
// NOTE:  Make sure the structure Contact does not have an 's' on the end!
// Put function prototype below:
void getContact(struct Contact* contact);