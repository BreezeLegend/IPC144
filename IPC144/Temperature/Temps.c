// Name:Victor Hasnat
// Student Number:
// Email:vhasnat@myseneca.ca
// Section:NLL
// Workshop:3


#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4
#include <stdio.h>

int main(void)
{
	float mean;
	int high;
	int low;
	int i;
	int totalhigh = 0;
	int totallow = 0;
	int dayhigh = 0;
	int daylow = 0;
	int highest = -41;
	int lowest = 41;
	double averagemin = 0;
	double averagehigh = 0;


	printf("---=== IPC Temperature Analyzer ===---\n");
	for (i = 1; i <= NUMS; i++) {
		do {
			printf("Enter the high value for day %d: ", i);
			scanf("%d", &high); //type in high values
			printf("\n");
			printf("Enter the low value for day %d: ", i);
			scanf("%d", &low); //type in low values
			printf("\n");
			if (high > 40 || low < -40 || high < low) {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.");
				printf("\n\n");
				
			}
			else {

				totalhigh += high;
				totallow += low;
				averagehigh += high;
				averagemin += low;
				mean = (totalhigh + totallow) / (float)(NUMS * 2); //find average for all temperatures
				if (highest < high) {
			
					highest = high;
					dayhigh = i;
				}
				if (low < lowest) {
					lowest = low;
					daylow = i;
				}
			}
		} while (high > 40 || low < -40 || high < low);
	} // end of for loop
	averagemin /= NUMS;
	averagehigh /= NUMS;

	printf("The average (mean) LOW temperature was: %.2f\n", averagemin);
	printf("The average (mean) HIGH temperature was: %.2f\n", averagehigh);
	printf("The average (mean) temperature was: %.2f\n", mean);
	printf("The highest temperature was %d, on day %d\n", highest, dayhigh);
	printf("The lowest temperature was %d, on day %d\n", lowest, daylow);
	return 0;
}