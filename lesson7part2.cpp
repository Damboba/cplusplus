/*
 * The purpose of this program is to read numbers from a file and validate if those numbers fit within a certain range.
 * The range of numbers should inclusively be from 0 to 105 and the average of all valid numbers will be taken. The invalid
 * values will be outputted in another file called "invalid-values.txt" with five digits to the right of the decimal point.
 * The program should prompt the user to input a file name and present multiple error messages in the case the input file could
 * not be opened or an average could not be calculated.
 */

#include <iostream>
#include <iomanip>
#include <fstream> // For inputting and outputting files in the program
using namespace std;

int main() {
    ifstream inputFile; // Responsible for bringing files into the program
    ofstream outputFile;   // Responsible for outputting files out the program to another file.

    cout << fixed << setprecision(4);

    double totalValidSum = 0.0; // Initializing double variables
    double averageOfValidValues = 0.0;
    double number;

    int totalCountOfNumbers = 0; // Initializing integer variables needed to count numbers
    int validCountOfNumbers = 0;
    int invalidCountOfNumbers = 0;

    string fileName; // String to store user input file name and allow for different file names
    cout << "Enter input file name" << endl;  // Prompts the user to input a file name into the program.
    cin >> fileName; // Reads in the user-specified file name.

    inputFile.open(fileName.c_str());   // Opens the input file with user-specified file name.

// checking whether the file name is validCountOfNumbers or not
    if (inputFile.fail()) { // Checks if the input file failed to be opened
        cout << "File " << "\"" << fileName << "\" could not be opened" << endl; // Displays to user if the input file couldn't be opened.
        return 1;
    } else {
        outputFile.open("invalid-values.txt"); // Creating the output file "invalidCountOfNumbers-numbers.txt" and opening it.
        cout << "Reading from file \"" << fileName << "\"" << endl; // Displays the name of the file being read from.

        // Reading in the numbers from the input file through a while loop.
        while (inputFile >> number) {
            totalCountOfNumbers++; // Keeps track of totalValidSum numbers in the file.
            if (number >= 0 && number <= 105) { // Checks if the number inputted is in the valid range or not.
                totalValidSum += number; // Calculates the totalValidSum amount of valid numbers.
                validCountOfNumbers++; // Keeps track of valid numbers by counting them.
            } else {
                invalidCountOfNumbers++; // Keeps track of invalid numbers by counting them.
                outputFile << fixed << setprecision(5) << number << endl; // Outputs the invalid numbers to the outputFile invalid-values.txt.
            }
        }
        inputFile.close(); // Closes the input file
        outputFile.close(); // Closes the output file.
    }

    // Outputs totalValidSum values, invalidCountOfNumbers values, and validCountOfNumbers values.
    cout << "Total values: " << totalCountOfNumbers << endl;
    cout << "Invalid values: " << invalidCountOfNumbers << endl;
    cout << "Valid values: " << validCountOfNumbers << endl;

    if (validCountOfNumbers == 0) { // Checks if there are no valid numbers.
        cout << "An average cannot be calculated" << endl; // Outputs that an average cannot be calculated.
    }
    else {
        averageOfValidValues = totalValidSum / validCountOfNumbers; // Calculates the average from the total sum divided by the count.
        cout << "Average of valid values: " << fixed << setprecision(4) << averageOfValidValues << endl;
    }
    return 0;
}