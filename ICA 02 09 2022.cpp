/* Program's purpose is to read out the values the user inserts into the program into the test.txt file. Print out the values into 4 different columns and 25 different rows and displays.
* The program's value accept a range between 1-100 values and that is why a 4 by 25 column display is sufficient. The program's also meant to calculate the minimum and maximum value out of the total values
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX_N 100

int main() {
    int data[MAX_N]; // Array to store values from file
    fstream myfile; // For input/output
    int counter; // Used as an index counter later for the array 
    int N; // The number of samples
    int minN, maxN;

    do {
        cout << "Enter the Number of Samples ";
        cin >> N;
    } while (N < 1 || N>100);

    myfile.open("test.txt", ios::out); // Opens file as ofstream

    if (!myfile.is_open()) {
        cout << "Error in file opening\n";
        return -1;
    }

    for (counter = 0; counter < N; counter++) { // reads out the random numbers to the test.txt output file
        myfile << rand() << endl;
    }

    myfile.close();

    // Opening file for reading
    myfile.open("test.txt", ios::in);

    if (!myfile.is_open()) { 
        cout << "Error in file reading\n"; 
        return -2; 
    }

    counter = 0;
    while (!myfile.eof()) {
        myfile >> data[counter]; 
        counter++;
    }

    // Calculates the largest and smallest number in the array
    maxN = data[0]; minN = data[0];
    for (counter = 0; counter < N; counter++) {
        if (maxN < data[counter]) {
            maxN = data[counter];
       }
        if (minN > data[counter]) {
            minN = data[counter];
        }
    }

    // Displays the values with no more than 4 columns and 25 rows
    cout << "COL1\tCOL2\tCOL3\tCOL4";
    for (counter = 0; counter < N; counter++) {
        if (counter % 4 == 0) {
            cout << "\n";
        }
        cout << data[counter] << "\t";
    }

    // Displays the largest and smallest values in the array.
    cout << endl;
    cout << "\nMax Value in the Array is: " << maxN;
    cout << "\nMin Value in the Array is: " << minN;

    return 0;
}