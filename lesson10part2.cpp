/*
 * The purpose of the program is to read the contents of a file into an array and calculate various values based on the
 * contents of file. The program will also use a 2 dimensional array that has 30 rows and 5 columns. The program should
 * only use one constant global variable among the 5 minimum required functions.
 */
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Initializing the global constant variable stated in the directions.
const int MAX_COLUMNS = 5;

// Function prototypes.
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName);
double average(double values[][MAX_COLUMNS], int numberRows);
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows);
double smallestRowVal(double values[][MAX_COLUMNS], int rowNumber);

int main() {
    ifstream inputFile; // Initializes the input file stream
    const int maxRows = 30; // Initializing more variables
    string inputFilename;
    int rowsRead;
    double values[maxRows][MAX_COLUMNS];

    // Prompts for the user to enter a file name and reads in the user's response.
    cout << "Enter input file name" << endl;
    cin >> inputFilename;

    // Setting the precision to two decimal places
    cout << fixed << setprecision(2);

    // Calls the readFile function and assigns the integer returned from the function to the rowsRead variable.
    rowsRead = readFile(values, maxRows, inputFilename);
    if (rowsRead == -1) {
        cout << "File \"" << inputFilename << "\" could not be opened" << endl;
    }
    else if (rowsRead == 0) {
        cout << "The input file \"" << inputFilename << "\" did not contain any data" << endl;
    }
    else {
        cout << "Processing " << rowsRead << " rows, and " << MAX_COLUMNS << " columns" << endl; // Prints # of rowsRead & columns.
        cout << "Average for all values is " << average(values, rowsRead) << endl; // Prints the average of all values.
    // Loop that prints the averages for each column.
        for (int i = 0; i < MAX_COLUMNS; i++) {
            cout << "Average for column " << i << " is " << columnAverage(values, i, rowsRead) << endl;
        }
    // Loop that prints the smallest value for each row.
        for (int j = 0; j < rowsRead; j++) {
            cout << "Smallest value for row " << j << " is " << smallestRowVal(values, j) << endl;
        }
    }
    return 0;
}

int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName) {
    int i, j; // Declaring variables
    string line;
    ifstream inputFile; // Declaring the input file stream and opening the file.
    inputFile.open(inputFileName.c_str(), ios::in);

    // Checks if the file exists or not
    if (inputFile.fail()) {
        return -1; // Returns this value if the file fails to open.
    } else {
        // Reads the data from the file.
        for (i = 0; i < maxRows &&
                    (inputFile.good()); i++) { // .good() is like the opposite of .fail and checks if there are no errors.
            for (j = 0; j < MAX_COLUMNS; j++) {
                inputFile >> values[i][j]; // Reads the values from each row of the file.
                    if (inputFile.fail() && i == 0) {
                        return 0;     // Returns 0 if the file contains no data and there are no rows of data in the file.
                    }
                }
            }
        }

        if (inputFile.eof() && inputFile.fail() ) { // Checks for the end of the file and closes the file once the end of the file is reached.
            inputFile.close();
            i -= 1;
        }
        return i; // Returns the number of rows read
    }

// The average function calculates the average of the total values in the 2D array.
double average(double values[][MAX_COLUMNS], int numberRows) {
    double sum = 0;
    int i, j;

    for (i = 0; i < numberRows; i++) { // Repeats over rows
        for (j = 0; j < MAX_COLUMNS; j++) { // Repeats over columns
            sum += values[i][j]; // Calculates the sum
        }
    }
    return (sum / (double)(numberRows * MAX_COLUMNS)); // Calculates the total average of all values and returns it.
}

// The columnAverage function calculates the average of each column.
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows) {
    double totalSum = 0;
    int i;

    for (i = 0; i < numberRows; i++) { // Repeats for the number of total rows.
        totalSum += values[i][column]; // Calculates the total sum of all values in the 2D array.
    }
    return (totalSum / (double)(numberRows)); // Calculates the average of each column and returns it.
}

// The smallestRowVal function returns the smallest value in each row.
double smallestRowVal(double values[][MAX_COLUMNS], int rowNumber) {
    double lowestVal = values[rowNumber][0];
    int i;

    for (i = 0; i < MAX_COLUMNS; i++) { // Repeats for the number of total columns.
        if (values[rowNumber][i] < lowestVal) {
            lowestVal = values[rowNumber][i]; // Updates the lowestVal variable to the lowest value in the row.
        }
    }
    return lowestVal; // Returns the lowest value
}