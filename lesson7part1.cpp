/*
 * The purpose of this program is to read in a file name from cin. It will then open the input file. The program must
 * also open an output file called saleschart.txt. The directions state to write the bar char headings and data
 * to this file. There will be a loop that will read the input data and process it until it gets and end of file
 * indication from the file readFileValues operation.
 */
#include <iostream>
#include <fstream> // For inputting and outputting files in the program
#include <iomanip> // For setting the precision of values
#include <string> // For getting the file name
using namespace std;

// Function readFileValues() for checking the values being read in from file.
bool readFileValues(ifstream &inputFile, long long int &sales, unsigned int &store) {
    bool valid = false;     // valid bool variable to check if valid data is readFileValues each time

    while(inputFile >> store >> sales) { // Reads in two values from file, loop breaks when eof arrives.
        if(store < 1 || store > 99 ) {   // Checks if the store number value is valid.
            cout << "The store number " << store<< " is not valid" << endl;
        }

        if( sales < 0) { // Checks if the sales number value is valid.
            cout << "The sales value for store " << store << " is negative" << endl;
        }

        if( sales >=0 && (store >=1 && store <=99)) {   // Checks if both the store and sale number values are valid.
            valid = true;   // Assigns valid variable as true. it will be the exit condition for while loop above
            break;          // Break statement to come out of the  while loop.
        }
    }

    if(!valid) {    // If valid data is not found or the end of file has been reached, returns false.
        return false;
    }
    return true;    // Returns true if the valid data is found.
}

// Function responsible for outputting the correct data to the saleschart.txt file at the end.
void displaySalesChart(ofstream &outputFile, long long int sales, unsigned int store) {
    outputFile << "Store " << setw(2) << store << ": ";   // writing data to file with store width set as 2
    int numberOfStars = sales / 5000;     // calculating number of stars to be appended for sales value

    // Loop responsible for writing required number of stars to the output file(saleschart.txt).
    for(int i = 1; i <= numberOfStars; i++) {
        outputFile << "*";
    }
    outputFile << endl; // Outputs a newline for the next data to be written on the next line.
}

// Calls other functions and is also responsible for getting the inputted file name.
int main() {
    ifstream inputFile; // Responsible for bringing files into the program
    ofstream outputFile;   // Responsible for outputting files out the program to another file.

    string fileName; // String to store user input file name and allow for different file names
    cout << "Enter input file name" << endl;
    cin >> fileName;

    inputFile.open(fileName.c_str());   // Opens the input file with user-specified file name.

    if(inputFile) {  // Checks if inputFile can be opened
        //Attempts to open outputFile (if file does not exist it will create a new file with the given name and open it)
        outputFile.open("saleschart.txt");

        if(outputFile) // Checks if output file can be opened
        {
            unsigned int store;     // Variable of type unsigned int to store the value of store
            long long int sales;    // Variable of type long long int  to store the value of sales

            int validRead = 0;     // Variable of type int to check if there are any valid reads from the file happened.
            while(readFileValues(inputFile, sales, store)) // calling read function in while loop for file processing it will be true till readFileValues return true
            {

                if(validRead == 0) {   // for first valid readFileValues this will run and write following data to output file
                    outputFile << "SALES BAR CHART" << endl; // Headers to output in saleschart.txt
                    outputFile << "(Each * equals 5,000 dollars)" << endl;
                    validRead = 1;     // Variable validRead set as 1, shows that at least one valid read occurred.
                }
                // Calls displaySalesChart function to write the output to the file.
                displaySalesChart(outputFile, sales, store);
            }
            outputFile.close();    // Closes the output file.
        }
        else {  // If outputFile cannot be opened, displays the following message.
            cout << "File " << "saleschart.txt" << " could not be opened" << endl;
        }
        inputFile.close(); // Closes the input file.
    }
    else    // If inputFile cannot be opened, displays the following message.
    {
        cout << "File " << "\"" << fileName << "\"" << " could not be opened" << endl; // Displays a message that says the file could not be opened.
    }

    return 0;
}