// Name:Victor Hasnat
// Student Number:
// Email:vhasnat@myseneca.ca
// Section:SYV
// Workshop:3

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 3

int main(void) {

	int i;
	int totalHigh = 0, totalLow = 0;
	int high, low;
	int entry;
	int max = 0, min = 0;
	
	float mean;

	printf("---=== IPC Temperature Analyzer ===---\n");
	for (i = 1; i <= NUMS; ++i) {

		entry = 0;
		while (!entry) {

			printf("Enter the high value for day %d: ", i);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i);
			scanf("%d", &low);
			printf("\n");

			if (high > 40 || low < -40 || low > high) {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
			}
			else {
				entry = 1;

				totalHigh += high;
				totalLow += low;


				if (high > max) {
					max = high;
				
				}
				if (low < min) {
					min = low;
					
				}
			}
		}
	}

	mean = (float)(totalHigh + totalLow) / (NUMS * 2);
	printf("The average (mean) temperature was: %1.2f\n", mean);

	return 0;
}

