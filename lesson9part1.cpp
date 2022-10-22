/*
 * The purpose of this program is to display the status order of a hypothetical company. The program requires three
 * functions at the bare minimum including the main() function. One function will be responsible for reading in the
 * values and another function will be responsible for displaying these values. These two functions however do not
 * interact with each other, but both individually interact with main.
 */
#include <iostream>
#include <iomanip> // Needed for setting the precision for the displayed values in the displayValues functions.
using namespace std; // For convenience

// Function Prototypes
int readNumberOfSpools(int& numberOfSpools);
int readSpoolsInStock(int& spoolsInStock);
char readSpecialCharge(char& specialCharge);
double readShippingHandlingCharge(char& specialCharge, double& shipHandleCharge);
void displayValues(int numberOfSpools, int spoolsInStock, double shipHandleCharge);

// Function simply calls all the other functions. The directions state at least 3 functions, I split the one readInValues
// function into four parts because it seemed simpler this way.
int main() {
    int numberOfSpools; // Initializes these variables in main to allow for multiple test cases.
    int spoolsInStock;
    char specialCharge;
    double shipHandleCharge;

    // Loops the readNumberOfSpools function till a valid number is inputted for numberOfSpools.
    while(readNumberOfSpools(numberOfSpools) < 1) {}

    // Loops the readSpoolsInStock function till a valid number is inputted for spoolsInStock.
    while(readSpoolsInStock(spoolsInStock) < 0) {}

    // Loops the readShippingHandleCharge function till a valid number is inputted for shipHandleCharge.
    //if(readShippingHandlingCharge(specialCharge, shipHandleCharge) < 0.0) {
    readSpecialCharge(specialCharge);
    while(readShippingHandlingCharge(specialCharge, shipHandleCharge) < 0.0);
    //}

    // Calls the displayValues() function and runs the output statements in the function.
    displayValues(numberOfSpools, spoolsInStock, shipHandleCharge);

    return 0; // Finishes with exit code 0
}

// Function reads in the number of spools ordered.
int readNumberOfSpools(int& numberOfSpools) {
    cout << "Spools to be ordered" << endl;
    cin >> numberOfSpools;
    if (numberOfSpools < 1) {
        cout << "Spools order must be 1 or more" << endl;
    }
    return numberOfSpools;
}

// Function reads in the number of spools in stock at the hypothetical company.
int readSpoolsInStock(int& spoolsInStock) {
    cout << "Spools in stock" << endl;
    cin >> spoolsInStock;
    if (spoolsInStock < 0) {
        cout << "Spools in stock must be 0 or more" << endl;
    }
    return spoolsInStock;
}

// Function reads in the user's decision and return the character.
char readSpecialCharge(char& specialCharge) {
    cout << "Special shipping and handling (y or n)" << endl;
    cin >> specialCharge;
    return specialCharge;
}

// Function reads in the shipHandleCharge variable and references the readSpecialCharge() function above.
double readShippingHandlingCharge(char& specialCharge, double& shipHandleCharge) {
    if (specialCharge == 'y') {
        cout << "Shipping and handling amount" << endl;
        cin >> shipHandleCharge;
        if (shipHandleCharge < 0.0) {
            cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
        }
        if (shipHandleCharge > 0.0) {
            return shipHandleCharge;
        }
    } else {
        shipHandleCharge = 12.99; // The normal shipping and handling is $12.99 per spool.
    }
    return shipHandleCharge;
}

// Function calculates all the values needed to be outputted at the end like the amount of spools ready to ship and the
// back order on this amount. Additionally, calculates the subtotal, total shipping fee, and the combined total shipping
// charges.
void displayValues(int numberOfSpools, int spoolsInStock, double shipHandleCharge) {
    const int spoolCost = 104; // A spool cost 104 per piece.
    int readyToShip = 0.0, backOrder = 0.0;
    double subtotal, totalShippingFee, total;

    if(numberOfSpools > spoolsInStock){     // Series of ifs responsible for determining the correct readyToShip
        readyToShip = spoolsInStock;        // and backOrder variables are made based off the number of spools
        backOrder = numberOfSpools - spoolsInStock; // ordered and in stock.
    } else if(numberOfSpools < spoolsInStock) {
        readyToShip = numberOfSpools;
    } else if(numberOfSpools == spoolsInStock) {
        readyToShip = numberOfSpools;
        backOrder = 0;
    }
    // Calculates the subtotal, totalShippingFee, and total values which are outputted below.
    subtotal = readyToShip * spoolCost;
    totalShippingFee = readyToShip * shipHandleCharge;
    total = subtotal + totalShippingFee;

    // Outputs all the required values whenever the displayValues function is called in main().
    cout << "Spools ready to ship: " << readyToShip << endl;
    cout << "Spools on back-order: " << backOrder << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal ready to ship: $" << setw(10) << subtotal << endl;
    cout << "Shipping and handling:  $" << setw(10) << totalShippingFee << endl;
    cout << "Total shipping charges: $" << setw(10) << total << endl;
}