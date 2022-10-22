/*
Program reads in values from an input file stores these values into arrays. Then we sort the arrays by course_number in non decreasing order
and display the final output as a table:
FIRST_NAME LAST_NAME	COURSE_NUMBER	GRADE

Contents of "roster.txt":
FIRST_NAME: Homer
LAST_NAME: Simpson
COURSE_NUMBER: 1337
GRADE: 99.9
FIRST_NAME: Karl
LAST_NAME: Lewis
COURSE_NUMBER: 1336
GRADE: 69.9
FIRST_NAME: John
LAST_NAME: Milton
COURSE_NUMBER: 2305
GRADE: 87.00

Complete the example and display as a table.
Use the header above, and precision of 2 for the grade with a byte field of 8. // Use atleast 8 positions
show positive sign.	// SHOWPOS
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define SIZE 100

using namespace std;

int main() {
	string first_name[SIZE];
	string last_name[SIZE];
	int course_number[SIZE];
	double grade[SIZE];

	ifstream in;
	in.open("roster.txt");
	if (!in.is_open()) {
		cout << "Error opening the for reading...\n";
		return -1;
	}

	int counter = 0;
	string helper;
	while (!in.eof()) {
		//in >> helper >> first_name[counter];
		//in >> helper >> last_name[counter];
		in >> helper;
		getline(in, first_name[counter]);
		in >> helper;
		getline(in, last_name[counter]);
		in >> helper >> course_number[counter];
		in >> helper >> grade[counter];
		counter++;
	}

	bool swap;
	do {
		swap = false;
		for (int i = 0; i < counter - 1; i++) {
			if (course_number[i] > course_number[i + 1]) {
				swap = true;
				int temp = course_number[i];
				course_number[i] = course_number[i + 1];
				course_number[i + 1] = temp;

				string temp_fname = first_name[i];
				first_name[i] = first_name[i + 1];
				first_name[i + 1] = temp_fname;

				string temp_lname = last_name[i];
				last_name[i] = last_name[i + 1];
				last_name[i + 1] = temp_lname;

				double temp_grade = grade[i];
				grade[i] = grade[i + 1];
				grade[i + 1] = temp_grade;
			}
		}
	} while (swap);


	cout << fixed << left << setw(12) << "FIRST_NAME"
		 << setw(12) << "LAST_NAME"
		 << setw(15) << "COURSE_NUMBER"
		 << setw(12) << "GRADE" << endl;

	for (int i = 0; i < counter; i++) {
		cout << fixed << left << setw(12) << first_name[i]
			 << setw(12) << last_name[i]
			 << setw(15) << noshowpos << course_number[i]
			 << setw(12) << setprecision(2) << showpos << grade[i] << "\n";
	}

	return 0;
}
