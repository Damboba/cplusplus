/*
 * The purpose of the program is to grade the quizzes of students. The program will compare the student's answers with
 * the correct answers, and determine if the student passed the quiz or not. The program utilizes at a minimum 3 functions.
 */
#include<iostream>
#include<iomanip>
#include<fstream> // used to read in files and output files as well
using namespace std;

// Function reads in a file name from the user and attempts to open the file.
int readInputFile(const string& fileName, char answers[]) {
    int numberOfEntries = 0;
    ifstream inputFile; // Declares an input file stream.
    inputFile.open(fileName.c_str()); // Opens the file name the user inputs.

    // Checks if the file can be opened.
    if( inputFile.fail() ) {
        cout << "File \"" << fileName << "\" could not be opened" << endl;
        numberOfEntries = -1;
    }

    // Loops and checks the number of entries in the inputted file and adds to the number of entries after each loop.
    while(numberOfEntries < 30 && inputFile >> answers[numberOfEntries] ){
        numberOfEntries++;
    }
    // Checks for the end of the file and closes the file once reached.
    if( inputFile.eof() ) {
        inputFile.close();
    }

    return numberOfEntries; // returns the numberOfEntries.
}

// Displays the student's quiz results at the end of the program if other conditions are met.
void displayStudentResults(char correctAnswers[], char studentAnswers[], int numberOfEntries) {
    int numberOfIncorrectAnswers = 0;
    double percent;

    // For loop reads the entries in the student answers array and compares them to the correct answers array.
    for (int i = 0; i < numberOfEntries; i++) {
        if (correctAnswers[i] != studentAnswers[i]) {
            cout << "Question " << (i + 1) << " has incorrect answer '" << studentAnswers[i]
                    << "', the correct answer is '" << correctAnswers[i] << "'" << endl;
            numberOfIncorrectAnswers++;
        }
    }

    // Calculates the grade the student made and outputs the number of questions missed out of the total.
    percent = 100 - ((static_cast<double>(numberOfIncorrectAnswers) / numberOfEntries) * 100);
    cout << numberOfIncorrectAnswers << " questions were missed out of " << numberOfEntries << endl;
    cout << "The student grade is " << fixed << setprecision(1) << percent << "%" << endl;

    // Determines if a student passed or failed the quiz.
    if (percent >= 70) {
        cout << "The student passed" << endl;
    } else {
        cout << "The student failed" << endl;
    }
}

// Function prompts for the student answers file name and the correct answers file name from the user.
int main() {
    char correctAnswers[30], studentAnswers[30];
    string studentAnswersFileName, correctAnswersFileName;

    // Prompts for the student answers file name and reads in the studentAnswersFileName and determines the number of
    // entries in the file and assigns this value to studentNumberOfEntries.
    cout << "Enter student answers file name" << endl;
    cin >> studentAnswersFileName;
    int studentNumberOfEntries = readInputFile(studentAnswersFileName, studentAnswers);

    // Checks first if the number of student entries are equal to -1 and checks second if number of correct entries are
    // equal to -1. Thirdly, checks if the number of student entries is equal to the number of correct entries.
    // Last condition checks if the number of both the student and correct entries are equal to 0.
    if(studentNumberOfEntries >= 0) {
        // Prompts for the correct answers file name and reads in the correctAnswersFileName and determines the number of
        // entries in the file and assigns this value to  correctNumberOfEntries.
        cout << "Enter correct answer file name" << endl;
        cin >> correctAnswersFileName;
        int correctNumberOfEntries = readInputFile(correctAnswersFileName, correctAnswers);

        if(correctNumberOfEntries >= 0) {
            if (studentNumberOfEntries != correctNumberOfEntries) {
                cout << "The student answers file has " << studentNumberOfEntries <<
                     " entries and the correct answers file has " << correctNumberOfEntries << " entries" << endl;
                cout << "Grading cannot be done if they are not the same" << endl;
                return 0;
            }
            if(studentNumberOfEntries == 0 && correctNumberOfEntries == 0) {
                cout << "The number of student answers and correct answers are both 0" << endl;
                cout << "No grade can be calculated" << endl;
            }
            // Checks if the number of both student and correct entries is not equal to 0 and calls the displayStudentResults function.
            if(studentNumberOfEntries != 0 && correctNumberOfEntries != 0) {
                displayStudentResults(correctAnswers, studentAnswers, correctNumberOfEntries);
            }
        }
    }
    return 0;
}
