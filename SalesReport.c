#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main() {

	

	
	


	char months[12][30] = {"January     $", "February    $", "March       $", "April       $", "May         $", "June        $", "July        $", "August      $", "September   $", "October     $", "November    $", "December    $"};
	double sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22 };
	
	const char* minMonth = " "; 
	const char* maxMonth = " ";

	int x = 0;
	printf("%s\n", "=====================");
	printf("Monthly sales report for 2022\n");
	printf("%s\n", "Month       Sales");
	

	for (int x = 0; x < 12; x++) {
		printf("%s", months[x]);
		printf("%.2f\n", sales[x]);
	}
	printf("%s", "=====================\n");
	//////////////////////////////////////////////////////////////////////
	
	
	double sum = 0.0;
	double minimumValue = sales[0];
	double maximumValue = sales[0];
	int minimumPosition = 0;
	int maximumPosition = 0;
	for (int x = 0; x < 12; x++) {
		
		sum += sales[x];

		if (sales[x] < minimumValue) {
			minimumValue = sales[x];
			minimumPosition = x;
		}
		if (sales[x] > maximumValue) {
			maximumValue = sales[x];
			maximumPosition = x;
		}
	}

	double average = sum / 12;
	switch (minimumPosition) {
	case 0:
		minMonth = "January";
		break;
	case 1:
		minMonth = "February";
		break;
	case 2:
		minMonth = "March";
		break;
	case 3:
		minMonth = "April";
		break;
	case 4:
		minMonth = "May";
		break;
	case 5:
		minMonth = "June";
		break;
	case 6:
		minMonth = "July";
		break;
	case 7:
		minMonth = "August";
		break;
	case 8:
		minMonth = "September";
		break;
	case 9:
		minMonth = "October";
		break;
	case 10:
		minMonth = "November";
		break;
	case 11:
		minMonth = "December";
		break;
	default:
		minMonth = "Error";
		break;

	}

	switch (maximumPosition) {
	case 0:
		maxMonth = "January";
		break;
	case 1:
		maxMonth = "February";
		break;
	case 2:
		maxMonth = "March";
		break;
	case 3:
		maxMonth = "April";
		break;
	case 4:
		maxMonth = "May";
		break;
	case 5:
		maxMonth = "June";
		break;
	case 6:
		maxMonth = "July";
		break;
	case 7:
		maxMonth = "August";
		break;
	case 8:
		maxMonth = "September";
		break;
	case 9:
		maxMonth = "October";
		break;
	case 10:
		maxMonth = "November";
		break;
	case 11:
		maxMonth = "December";
		break;
	default:
		maxMonth = "Error";
		break;

	}
	printf("\n%s", "=====================\n");
	printf("Sales Summary:\n");
	printf("Minimum value: $%.2lf       (%s)\n", minimumValue, minMonth);
	printf("Maximum value: $%.2lf       (%s)\n", maximumValue, maxMonth);
	printf("Average Sales: $%.2lf\n", average);
	printf("%s", "=====================\n");


////////////////////////////////////////////////////////////////////////////////////////////////
	
	const char* months2[] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};
	printf("\n%s", "=====================\n");
	printf("6-Month Moving Averages Report:\n");
	for (int x = 0; x <= 6; x++) {
		double avg = 0.0;
		for (int y = 0; y < 6; y++) {
			avg += sales[x + y];
		}
		avg /= 6;
		printf("%s - %s: $%.2lf\n", months2[x], months2[x + 5], avg);
	}
	printf("%s", "=====================\n");

////////////////////////////////////////////////////////////////////////////////////////////////
	printf("\n%s", "=====================\n");
	int sortedPositions[12] = {};

	for (int x = 0; x < 12; x++) {
		sortedPositions[x] = x;
	}

	for (int x = 0; x < 12 - 1; x++) {
		for (int y = 0; y < 12 - x - 1; y++) {
			if (sales[y] < sales[y + 1]) {
				double temp = sales[y];
				sales[y] = sales[y + 1];
				sales[y + 1] = temp;

				
				int tempPosition = sortedPositions[y];
				sortedPositions[y] = sortedPositions[y + 1];
				sortedPositions[y + 1] = tempPosition;
			}
		}
	}
	const char* sortedMonth;
	printf("Sales Report (Highest to Lowest)\n");
	printf("Month       Sales\n");
	for (int x = 0; x < 12; x++) {
		switch (sortedPositions[x]) {
		case 0:
			sortedMonth = "January  ";
			break;
		case 1:
			sortedMonth = "February ";
			break;
		case 2:
			sortedMonth = "March    ";
			break;
		case 3:
			sortedMonth = "April    ";
			break;
		case 4:
			sortedMonth = "May      ";
			break;
		case 5:
			sortedMonth = "June     ";
			break;
		case 6:
			sortedMonth = "July     ";
			break;
		case 7:
			sortedMonth = "August   ";
			break;
		case 8:
			sortedMonth = "September";
			break;
		case 9:
			sortedMonth = "October  ";
			break;
		case 10:
			sortedMonth = "November ";
			break;
		case 11:
			sortedMonth = "December ";
			break;
		default:
			sortedMonth = "Error";
			break;

		}
		printf("%s ", sortedMonth);
		printf(" $%.2lf\n", sales[x]);
	}
	

	printf("%s", "=====================\n");



















	
	}



