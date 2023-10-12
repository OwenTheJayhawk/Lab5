#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE* file;
	
	file = fopen("C:\\Users\\owend\\Downloads\\SalesReport.txt", "r");

	char Report[100];

	
	


	char months[12][30] = {"January     $", "February    $", "March       $", "April       $", "May         $", "June        $", "July        $", "August      $", "September   $", "October     $", "November    $", "December    $"};
	double sales[12] = {};
	float movingAverage[12];
	float totalSales;
	const char* minMonth = " "; 
	const char* maxMonth = " ";

	int i = 0;
	printf("%s\n", "=====================");
	
	printf("%s\n", "Month       Sales");
	while (fgets(Report, 100, file)) {
		printf("%s", months[i++]);
		printf("%s", Report);
	}
	printf("\n%s", "=====================\n");

	fclose(file);



	//////////////////////////////////////////////////////////////////////
	FILE* file2;
	file2 = fopen("C:\\Users\\owend\\Downloads\\SalesReport.txt", "r");

	char Report2[100];
	
	double sum = 0.0;
	double minimumValue = sales[0];
	double maximumValue = sales[0];
	int minimumPosition = 0;
	int maximumPosition = 0;
	for (int i = 0; i < 12; i++) {
		if (fscanf(file2, "%lf", &sales[i]) != 1) {
			printf("Failed to read all 12 numbers from the file.\n");
			return 1;
		}
		sum += sales[i];

		if (sales[i - 1] < minimumValue) {
			minimumValue = sales[i];
			minimumPosition = i;
		}
		if (sales[i] > maximumValue) {
			maximumValue = sales[i];
			maximumPosition = i;
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
	int monthRange;
	const char* months2[] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};
	printf("\n%s", "=====================\n");
	printf("6-Month Moving Averages Report:\n");
	for (int i = 0; i <= 6; i++) {
		double avg = 0.0;
		for (int j = 0; j < 6; j++) {
			avg += sales[i + j];
		}
		avg /= 6;
		printf("%s - %s: $%.2lf\n", months2[i], months2[i + 5], avg);
	}
	printf("%s", "=====================\n");
























	
	}



