/*
 * The purpose of this program is to read in values from a file to determine whether the values in the file satisfy the
 * conditions to be considered a magic square. If the file can't be opened the program should also handle errors such as
 * these and use only one const global variables for all functions.
 */
#include<iostream>
#include<fstream>
using namespace std;

const int MAX_SIZE = 21; // Global const int variable accessible to all function in the program.

// Function Prototypes
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size);
int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName);
void printSquare(const int square[MAX_SIZE][MAX_SIZE], int size);

// The purpose of this function is to call the other functions and correctly output any error messages.
int main() {
    string fileName; // Initializing variables
    int size;
    int square[MAX_SIZE][MAX_SIZE];

    // Prompts user to enter a file name and reads in the user's input to the string fileName.
    cout << "Enter input file name" << endl;
    cin >> fileName;

    // Assigns the value obtained from calling the readSquare function to the size variable.
    size = readSquare(square, fileName);

    // Checks if the size variable is not equal to -1
    if(size != -1 && size != 0) {
        printSquare(square, size); // Calls the printSquare function to print the square.
        if(validateSquare(square, size)) {       // Calls the validateSquare function to determine validity of the square.
            cout << endl << "Valid magic square"; // Outputs this if square is a magic square.
        } else {
            cout << endl << "Invalid magic square"; // Outputs this if square is not a magic square.
        }
    }
    return 0;
}

// The purpose of this function is to read the square array from inputFile and return the size variable.
int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName) {
    int size = -1; // Initialize and set size variable to -1, so if no size is given in the file other functions aren't called.
    ifstream inputFile;
    inputFile.open(inputFileName.c_str()); // Opens the file with user inputted file name.

    if( !inputFile ) {
        // Displays an error message that the file could not be opened if it wasn't opened.
        cout << "File \"" << inputFileName << "\" could not be opened" << endl;
        inputFile.close();
        return 0;
    }
    // Checks if the file has been opened.
    if( inputFile.is_open() ) {
        inputFile >> size;         // Reads in the size of the 2D array. Note width and length are same value because it's a square.
        for(int i = 0; i < size; i++) {         // For loop repeats until all the values in the inputFile have been added to the 2D array.
            for(int j = 0; j < size; j++) {
                inputFile >> square[i][j];
            }
        }
 }
    if ( inputFile.eof() ) { // Checks for the end of the file.
        inputFile.close(); // If the file has reached the end, closes the file.
    }
    return size; // Returns the size
}

// The purpose of this function is to print out the contents of the 2D array in a square format.
void printSquare(const int square[MAX_SIZE][MAX_SIZE], int size) {
    cout << "Magic square" << endl; // Prints out the header of the magic square.
    for(int i = 0; i < size; i++) { // Repeats through rows of the 2D array
        for(int j = 0; j < size; j++) {   // Repeats through columns of the 2D array.
            // Outputs each element in the 2D array.
            cout << square[i][j] << " ";
        }
        cout << endl; // Prints out on to the next line after each row of values is done.
    }
}

// The purpose of this function is to use the 2D array and size parameters and determine whether the square is a valid magic square.
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size) {
    int diagonalSum1 = 0, diagonalSum2 = 0, rowSum, columnSum; // Initializes sum variables;
    int checkDigits[MAX_SIZE*MAX_SIZE + 1] = {0,0,0,0,0,0,0,0,0}; // Array used to check if the values being entered into 2D array are correct.
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(square[i][j] < 1 || square[i][j] > size*size) {
                return false;
            } else {
                checkDigits[square[i][j]]++;
            }
        }
    }
    for(int i = 1; i <= size*size; i++) {
        if(checkDigits[i] > 1) { // Checks if any values are greater than 1.
            return false;
        }
    }

    // Calculate the Sum of the Diagonals
    for (int i = 0; i < size; i++) {
        diagonalSum1 = diagonalSum1 + square[i][i]; // Calculates the sum of diagonal1.
    }
    for (int i = 0; i < size; i++) {
        diagonalSum2 = diagonalSum2 + square[i][size - 1 - i]; // Calculates the sum of diagonal2.
    }
    if(diagonalSum1 != diagonalSum2) {  // Checks if the sum of the diagonals is not equal and returns false.
        return false; // This is a boolean type function so returns are either true or false.
    }

    // Calculates the sum of each row in the 2D array.
    for (int i = 0; i < size; i++) {
        rowSum = 0; // Needed otherwise the value of rowSum would grow to big.
        for (int j = 0; j < size; j++) {
            rowSum = rowSum + square[i][j];
        }
        // Checks if the sum of each row is equal to sum of diagonal and otherwise returns false.
        if (rowSum != diagonalSum1) {
            return false;
        }
    }

    // Calculates the sum of each column in the 2D array.
    for (int i = 0; i < size; i++) {
        columnSum = 0; // Needed otherwise the value of rowSum would grow to big.
        for (int j = 0; j < size; j++) {
            columnSum = columnSum + square[j][i];
        }
        // Checks if the sum of each column is equal to sum of diagonal and otherwise returns false.
        if (columnSum != diagonalSum1) {
            return false;
        }
    }
    // If all the sums are equal then the function will return true.
    return true;
}