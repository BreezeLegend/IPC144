//--------------------------------------------------
// Name: Victor Hasnat      
// Student Number: 119485183
// Email: vhasnat@myseneca.ca 
// Section: NLL  
// Workshop: 5    
//--------------------------------------------------

#include <stdio.h>
#define SIZE 4

struct Employ {
	int ID;
	int age;
	double salary;
};

int main(void) {
	struct Employ emp[SIZE] = {{0}};						        //make Employ structured variable and initialize;
	int option = 1;											//option variable
	int nEmp = 0;											//counting how many employee we have so far
	int i;
	
	int check;												//to check each variable is valid
	int sID;												//searching ID
	printf("---=== EMPLOYEE DATA ===---\n\n");
	while (option != 0) {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");
		switch (option)
		{
		case 1:												//print employee information
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {
        if (emp[i].ID > 0)
				printf("%6d%9d%11.2lf\n", emp[i].ID, emp[i].age, emp[i].salary);
			}
			printf("\n");
			break;
		case 2:												//add employee
			printf("Adding Employee\n");
			printf("===============\n");
			        if (nEmp < SIZE){
          for (i=0; i <= SIZE; i++){
            
            if (emp[i].ID == 0){
              printf("Enter Employee ID: ");
              scanf("%d", &emp[i].ID);
              printf("Enter Employee Age: ");
              scanf("%d", &emp[i].age);
              printf("Enter Employee Salary: ");
              scanf("%lf", &emp[i].salary);
	      printf("\n");
              check = 0;
              ++nEmp;
              break;
            }
          }
        } else
        printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			
			break;
		case 3:												//update employee
			printf("Update Employee Salary\n");
			printf("======================\n");
			if (nEmp == 0) {								//in case there is no employee yet
				printf("\nNo employee to update\n\n");
				break;
			}
			do
			{
				check = 1;
				printf("Enter Employee ID: ");
				scanf("%d", &sID);
				for (i = 0; i < nEmp; i++)
				{
					if (emp[i].ID == sID) break;
					else if (i == nEmp - 1) printf("*** ERROR: Employee ID not found! ***\n");
				}
				if (i != nEmp) {
					printf("The current salary is %.2f\n", emp[i].salary);
					printf("Enter Employee New Salary: ");
					scanf("%lf", &emp[i].salary);
					check = 0;
					printf("\n");
				}
			} while (check);
			break;
		case 4:												//remove employee
			      printf("Remove Employee\n");
			printf("===============\n");
      if (nEmp == 0){
        printf("\nNo employee to remove\n\n");
        break;
      } else {
        check =0;
        do{
        //There are more than 0 Employees
        printf("Enter Employee ID: ");
			 	scanf("%d", &sID);
        
        //Check to see if the employee exists
        for (i=0;i<=SIZE;i++){
          //If employee Id is found
          if (emp[i].ID == sID){
            printf("Employee %d will be removed\n", emp[i].ID);
            check = 1; //do-while flag
            emp[i].ID = 0;
            nEmp = nEmp - 1;
            printf("\n");
            break;
           // break;
          } else if ( i == SIZE && check == 0){
            printf("*** ERROR: Employee ID not found! ***\n");
          }
        }
        }while (check==0);//do-while
        check = 0; // reset
      } // else
			break;
		case 0:												//exit
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		default:											//not valid option input
			printf("ERROR: Incorrect Option: Try Again\n\n");
			break;
		}
		//if (option != 0) option = -1;
	}
	return 1;
}