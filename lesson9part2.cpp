/*
 * The purpose of this program is to use functions and files in correspondence. The program reads in values from a file
 * that the user inputs and then calculates the future value based on those values. The program outputs the values from
 * the inputted file and the calculated future value into an Excel spreadsheet file at the end.
 */

#include <iostream>
#include <fstream> // Needed for input and outputting files.
#include <iomanip> // Needed for setting the precision of outputted double values.
#include <string> // Needed for inputting the file name.
#include <cmath> // Needed for calculating the future value because of pow.
using namespace std;

// Function Prototypes
unsigned int readInputValues(ifstream& inputFile, double& presentValue, double& interestRate, int& months);
double futureValue(double presentValue, double interestRate, int months);
void displayOutput(ofstream& outputFile, double future, double presentValue, double interestRate, int months);

int main() {
    double present = 0.0; // Initializes the variables allowing for multiple test cases.
    double interest = 0.0;
    double future = 0.0;
    int months = 0;

    ifstream inputFile; // Responsible for bringing files into the program
    ofstream outputFile; // Responsible for outputting files out the program to another file.
    string fileName; // Needed to check different file names

    // Prompts the user to enter the name of the input file and reads in the user's input.
    cout << "Enter input file name" << endl;
    cin >> fileName;

    outputFile.open("output.xls"); // Opens the outputFile output.xls
    inputFile.open(fileName); // Opens the inputFile with user-inputted file name

    if (!inputFile.is_open()) { // Checks if the inputFile was not opened.
        cout << "File \"" << fileName << "\" could not be opened" << endl; // Displays this to the user.
        return -1;
    }
    if (!outputFile.is_open()) { // Checks if the outputFile was not opened.
        cout << "File \"output.xls\" could not be opened" << endl; // Displays this to the user.
        return -1;
    }

    // Outputs this as the header for the outputFile which is the output.xls Excel spreadsheet.
    outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;

    // The validType variable checks the return of the readInputValues() function.
    unsigned int validType = readInputValues(inputFile, present, interest, months);
    while (validType != 0) { // Loop operates as long as the values inputted aren't 0.
        if (validType == 1) { // The body of this if check runs when validType is equal to 1.
            future = futureValue(present, interest, months); // Calls the futureValue() function and assigns it to the variable future.
            displayOutput(outputFile, future, present, interest, months); //Calls the displayOutput() function
        }
        if (validType == 2) { // The body of this if check runs when validType is equal to 2.
            cout << fixed << setprecision(2) << present << " " << setprecision(3) << interest * 100 << " " << months << endl;
            cout << "One or more of the above values are not greater than zero" << endl; // Prompts user to enter values all greater than zero.
        }
        validType = readInputValues(inputFile, present, interest, months);
    }

    inputFile.close(); // Closes the inputFile.
    outputFile.close(); // Closes the outputFile

    return 0;
}

// Definition of the readInputValues function to read the content from the input file.
unsigned int readInputValues(ifstream& inputFile, double& presentValue, double& interestRate, int& months) {
    inputFile >> presentValue >> interestRate >> months; // Reads in all the values from the inputted file.
    interestRate /= 100; // Changes interest rate before it reaches the futureValue function
    if (inputFile.eof()) { // Checks for the end of file for inputFile.
        return 0; // Ends the loop in main when end of file has been reached.
    }
    if (!(presentValue > 0.0 && interestRate > 0.0 && months > 0)) { // Checks if one of the values is less than 0.0
        return 2;
    }
    return 1;
}

//Definition of the futureValue function which calculates the future value function with the values from the input file.
double futureValue(double presentValue, double interestRate, int months) {
    double future = presentValue * pow((1 + interestRate), months); //
    return future;
}

// Definition of the displayOutput function which writes the contents of other functions into the Excel file.
void displayOutput(ofstream& outputFile, double future, double presentValue, double interestRate, int months){
    outputFile << fixed << setprecision(2) << future << "\t" << presentValue;
    outputFile << fixed << setprecision(3) << "\t" << interestRate * 100 << "\t" << months << std::endl;
}