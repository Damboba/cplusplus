/*
 * The purpose of the program is to create multiple functions to calculate the present value without the use of global
 * variables. The functions should repeat the input value process and output a message in the case a negative number or
 * zero is inputted. There are three functions which read in input from the user. These values are used to calculate
 * the present value. The last function other than main is the display function which displays all the values in an
 * orderly manner. The int main function calls all the other 5 functions and is the main backbone of the program.
 */
#include <iostream>
#include <cmath> // Needed pow for calculating the presValue in the presentValue function.
#include <iomanip> // Needed setprecision for setting the precision of display values in displayValues function.
using namespace std; // For convenience

// Function reads in the future value and returns it.
double futValue(double& futureValue) {
    cout << "Enter future value" << endl;
    cin >> futureValue;
    return futureValue;
}
// Function reads in the annual interest rate and divides it by 100 before being used in the present value function
// and return the calculated interest rate.
double intRate(double& interestRate) {
    cout << "Enter annual interest rate" << endl;
    cin >> interestRate;
    interestRate = interestRate / 100;
    return interestRate;
}
// Function reads in the number of years and returns it.
int numberOfYears(int& numberYears) {
    cout << "Enter number of years" << endl;
    cin >> numberYears;
    return numberYears;
}
// Function calculates the present value and returns it.
double presentValue(double futureValue, double interestRate, int numberYears) {
    double presValue;
    presValue = futureValue / pow((1 + interestRate), numberYears);
    cout << futureValue << " " << interestRate << " " << numberYears << endl;
    return presValue;
}
// Function displays the present value, future value, annual interest rate, and number of years.
void displayValues(double& presValue, double futureValue, double interestRate, int numberYears) {
    presValue = futureValue / pow((1 + interestRate), numberYears);
    cout << fixed << setprecision(2) << "Present value: $" << presValue << endl;
    cout << fixed << setprecision(2) << "Future value: $" << futureValue << endl;
    cout << fixed << setprecision(3) << "Annual interest rate: " << (interestRate * 100) << "%" << endl;
    cout << fixed << setprecision(0) << "Years: " << numberYears << endl;
}

int main() {
    double futureValue; // Initializes variables from functions in main, so that the program supports many test cases.
    double interestRate;
    int numberYears;
    double presValue;

    while(futValue(futureValue) <= 0) { // Loops until a positive non-zero value is inputted.
        cout << "The future value must be greater than zero" << endl;
    }

    while(intRate(interestRate) <= 0) { // Loops until a positive non-zero value is inputted.
        cout << "The annual interest rate must be greater than zero" << endl;
    }

    while(numberOfYears(numberYears) <= 0) { // Loops until a positive non-zero value is inputted.
        cout << "The number of years must be greater than zero" << endl;
    }

    // Responsible for final display of values at the end.
    displayValues(presValue, futureValue, interestRate, numberYears);

    return 0;
}

