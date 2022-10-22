/*
CS1337.002
02-16-2022
Damboba Hebo

Program asks users for min and max values, number of samples and delta. Using the Min and Max values entered by the user, the program generates n random numbers, between [Min, Max]. The value for n <= 80. The program computes the average of the values worth 20 points. The program computes the variance of the values worth 20 points. The program computes the standard deviation of the value worth 10 points.

Show the values of the 3 parameters above at the bottom of the table. Samples should be
displayed signed (+ should be shown for samples >0) as a table with no more than 4 columns,
and no more than 20 rows per column, using at least 10 positions per value, and 3 positions after
the decimal point (20 points). Implement input validation: Min < Max, d<=(Max-Min) and 1<=
n<=80 (10 points).

For this program, also include:
a) Pseudocode (5 points)
b) Flowchart (5 points)

PSEUDOCODE:
1.- Start																												CIRCLE
2.- Define a global constant variable for the size of the array															RECTANGLE
3.- Declare the integer variable (N)																					RECTANGLE
4.- Declare the double variables (min, max, delta, random(random is an array))											RECTANGLE
5.- Ask the user for a maximum value																					PARALLELOGRAM
6.- Read in the max value																								PARALLELOGRAM
7.- Ask the user for a minimum while validating that the value entered is smaller than the max value					PARALLELOGRAM
8.- Read in the min value till valid.																					PARALLELOGRAM
9.- Asks the user for the number of samples between 1 and 80.															PARALLELOGRAM
10.- Reads in the number of samples and validates it is within the range before continuing								PARALLELOGRAM
11.- Asks the user for a delta value																					PARALLELOGRAM
12.- Reads in the delta value as long as delta inputted is greater than the difference of min and max					PARALLELOGRAM
13.- Store random numbers between the min and max for n amount of samples into the random array.						RECTANGLE
14.- Initialize integer variable called index for outputting the samples in a table										RECTANGLE
15.- Check the signedness of the sample data.(If signed...)																DIAMOND
15A.- If the value at the index is greater than 0 display the value with a positive sign in front						DIAMOND -> PARALLELOGRAM
15B.- If the value at the index is equal to 0 then display the value with no sign in the front							DIAMOND -> PARALLELOGRAM
15C.- If the other conditions aren't true display the value with a negative sign in the front							DIAMOND -> PARALLELOGRAM
15D.- If the index variable is equal to the number of samples then break out of the inner loop							DIAMOND -> PARALLELOGRAM
16.- Output a whole new line and break out of the outer loop by checking if index is equal to the number of samples		DIAMOND -> PARALLELOGRAM
17.- Compute the Average																								RECTANGLE
18.- Display the Average																								PARALLELOGRAM
19.- Compute the Variance																								RECTANGLE
20.- Display the Variance																								PARALLELOGRAM
21.- Compute the Standard Deviation																						RECTANGLE
22.- Display the Standard Deviation																						PARALLELOGRAM
23.- Exit																												CIRCLE

*/
#include <iostream> // cout/cin processing
#include <iomanip> // for setprecision and setw
#include <cmath> // for square root
#include <time.h> // for srand

using namespace std;

#define MAX_N 80

int main() {
	int N = 81; // N stands for the number of samples
	double max, min, delta;
	double random[MAX_N];

	cout << "Enter a maximum value: "; // Asks user for max value.
	cin >> max;

	min = max + 1;
	while (min > max) {
		cout << "Enter a minimum value: "; // Asks user for min value.
		cin >> min;
	}

	do {
		cout << "Please enter the number of samples [1, 80]: ";
		cin >> N;
	} while (N < 1 || N > 80);

	do {
		cout << "Enter the smallest difference between two non-identical samples: "; // Asks user for a delta value.
		cin >> delta;
	} while (delta > (max - min) );

	srand(time(0));	// Resets seed
	for (int i = 0; i < N; i++) {
		random[i] = min + delta * (rand() % ((int)((max - min) / delta) + 1));
	}

	int index = 0;
	for (int i = 0; i < ((N / 4) + N % 4); i++) {
		for (int j = 0; j < 4; j++) {
			if (random[index] > 0) {
				cout << fixed << setprecision(3) << right << setw(10) << "+" << random[index];
			}
			else if (random[index] == 0) {
				cout << fixed << setprecision(3) << right << setw(10) << " " << abs(random[index]);
			}
			else {
				cout << fixed << setprecision(3) << right << setw(10) << "-" << abs(random[index]);
			}
			index++;
			if (index == N) {
				break;
			}
		}
		cout << endl;
		if (index == N) {
			break;
		}
	}

	double average, variance, standardDeviation;
	// Computing the AVERAGE
	double totalAverageSum = 0;
	for (int i = 0; i < N; i++) {
		totalAverageSum += random[i];
	}
	average = totalAverageSum / N;
	cout << endl << "Average is: " << average; // Dislays the AVERAGE

	// Computing the VARIANCE
	double totalVarianceSum = 0;
	for (int i = 0; i < N; i++) {
		totalVarianceSum += pow((random[i] - average), 2);
	}
	variance = totalVarianceSum / N;
	cout << endl << "Variance is: " << variance; // Displays the VARIANCE

	// Computing the STANDARD DEVIATION
	standardDeviation = sqrt(variance);
	cout << endl << "Standard Deviation is: " << standardDeviation; // Displays the STANDARD DEVIATION
}










