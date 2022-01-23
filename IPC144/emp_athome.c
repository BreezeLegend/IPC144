#define _CRT_SECURE_NO_WARNINGS
#define SIZE 4

#include <stdio.h>
struct employee {
	int id;
	int age;
	double salary;
};


int main(void)
{

	int option = 0, i = 0, j = 0, n = 0, flag = 0;

	struct employee emp[SIZE] = { {0} };


	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		printf("\n");
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			printf("\n");

			break;
		case 1:


			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {

				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf", emp[i].id, emp[i].age, emp[i].salary);
					printf("\n");

				}

			}
			break;
		case 2:


			printf("Adding Employee\n");
			printf("===============\n");

			if (n < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[n].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[n].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[n].salary);
				n++;

			}
			else
				printf("ERROR!!! Maximum Number of Employees Reached\n");


			break;


		case 3:
			printf("Update Employee Salary\n");
			printf("===============\n");
			do {
				printf("Enter Employee ID: ");
				scanf(" %d", &j);


				for (i = 0; i < SIZE; i++) {
					if (j == emp[i].id)
					{

						printf("The current salary is %0.2lf", emp[i].salary);
						printf("\nEnter New Employee Salary: ");
						scanf(" %11lf", &emp[i].salary);
						flag = 1;
						break;

					}
				}




				if (j != emp[i].id) {
					printf("*** ERROR: Employee ID not found! ***");
					printf("\n");


				}
			} while (flag == 0);



			break;

		case 4:
			printf("Remove Employee\n");
			printf("===============\n");
			do {
				printf("Enter Employee ID: ");
				scanf(" %d", &j);


				for (i = 0; i < SIZE; i++) {
					if (j == emp[i].id)
					{
						printf("Employee %d will be removed\n", emp[i].id);
						emp[i].id = 0;
						flag = 1;
						break;
					}

				}

				if (j != emp[i].id) {
					printf("*** ERROR: Employee ID not found! ***");
					printf("\n");
				}
			} while (flag == 0);


			break;


		default:
			printf("ERROR: Incorrect Option: Try Again\n");
		}

	} while (option != 0);


	return 0;
}
