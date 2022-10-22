/*
Write a program to read first (string) and last(string) name of one person, (integer, e.g. 1337) and grades (doubles) for exams 1,2, and 3.

Then compute the average grade, and display the information, left aligned, with no more than two decimals for the average grade

LAST(MINW of 15) FIRST(MINW 15) (COURSE MW 5) (E1 MW 4) (E2 MW 4) (E3 MW 4) (AVG, MW 6, PRECISION 2)

Last		First	Course E1 E2 E3	AVG
Razo		Miguel	  1337 50 80 80 70.00

PSEUDOCODE
1.- Start                                                                                                   Circle
2.- Declare the variables (full name of the person, the course section, average grade and 3 exam grades)    Rectangle
3.- Ask for first and last name of the person                                                               Parallelogram
4.- Read the first and last name of the person (string variables)                                           Parallelogram
5.- Ask for the course section and 3 exam grades                                                            Parallelogram
6.- Read the course section and 3 exam grades  (integer variables)                                          Parallelogram
7.- Compute the average grade (double variable)                                                             Rectangle
8.- Display the headers for the variables                                                                   Parallelogram
9.- Display the variables with a left alignment and varying min widths                                      Parallelogram
10.- Exit                                                                                                   Circle  
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string lastName, firstName;     // Declares the variables
    int courseSection, exam1, exam2, exam3;
    double averageGrade;

    //Asks for the last name
    cout << "Enter Last Name\n";
    //Reads in the last name
    cin >> lastName;

    //Asks for the first name
    cout << "Enter First Name\n";
    //Reads in the first name
    cin >> firstName;

    //Asks for the course section
    cout << "Enter the Course Section\n";
    //Reads in the course section
    cin >> courseSection;

    cout << "Enter the Three Exam Grades (in order from first exam to last)\n";
    //Reads in the exam grades
    cin >> exam1 >> exam2 >> exam3;

    //Compute the average grade of the three exams
    averageGrade = (exam1 + exam2 + exam3) / 3.0;

    
    //Displays the information
    cout << fixed << left << setw(15) << "Last" << setw(15);
    cout << "First" << setw(5);
    cout << "Course  " << setw(4);
    cout << "E1" << setw(4);
    cout << "E2" << setw(4);
    cout << "E3" << setw(6);
    cout << "AVG" << endl;

    cout << fixed << left << setw(15) << lastName << setw(17);
    cout << firstName << setw(6);
    cout << courseSection << setw(4);
    cout << exam1 << setw(4);
    cout << exam2 << setw(4);
    cout << exam3 << setw(6);
    cout << setprecision(2) << averageGrade << endl;

}
