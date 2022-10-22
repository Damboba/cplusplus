/*
Damboba Hebo
CS1337.002
ICA: 2-28-2022

Example 2:
Assume an input file with the following structure is given(users.txt):
const // <int>	<string>	<double>
Where
int is the id (>0)
string is the username (string with no spaces)
double is the GPA

Assume that there are no more than 100 entries(rows or lines) in the input file

a) Define an structure user to store the information of one student
b) Define an array to store up to 100 elements of the user data type
c) read the input file into the array in b)
d) Display the data then as a table *use precision 2 for GPA
e) Find the average GPA
f) Display all students with a GPA>= average_GPA

e.g.
1234	asdas432423 4.0
5453	mnjkfgk234	3.7
9743	dsaha56456	2.6
*/

#include <iostream> //cin/cout
#include <fstream>  //file processing
#include <iomanip>  //output formatting

#define SIZE 100 // Symbolic constant for the number of entries in the input file

using namespace std;

struct users3D{				// Part a
	int id;		// (>0)
	string username; // String with no spaces
	double gpa;
};

int readFileValues(users3D data[]) {	// Part c
	ifstream input;
	input.open("users.txt");

	if (!input.is_open()) {
		cout << "Error opening the file";
		return -1;
	}

	int counter = 0;
	while (!input.eof()) {
		input >> data[counter].id >> data[counter].username >> data[counter].gpa;
		counter++;
	}
	input.close();
	return counter;
}

void displayTable(users3D data[], int max_size) { // Part d
	for (int i = 0; i < max_size; i++) {
		//cout << "P[" << i << "] : (" << ap[i].x << "," << ap[i].y << ")\n";
		cout << data[i].id << "\t" << data[i].username << "\t" << fixed << setprecision(2) << data[i].gpa << "\n";
	}
}

double averageGPA(users3D data[], int max_size) {	// Part e
	double averageGPA = 0;
	int i = 0;
	for (i = 0; i < max_size; i++) {
		averageGPA += data[i].gpa;
	}
	averageGPA = averageGPA / i;

	cout << "Students that have a GPA >= Average GPA: ";	// Part f

	for (i = 0; i < max_size; i++) {
		if (data[i].gpa >= averageGPA) {
			cout << data[i].username << ", ";
		}
	}
	return averageGPA;
}

int main() {
	users3D data[SIZE];		// Part b
	
	int counter = readFileValues(data);
	if (counter == -1) {
		return counter;
	}
	if (counter == 0) {
		cout << "empty file...\n";
	}

	cout << "ID#\t" << "USERNAME\t" << "GPA\n";

	displayTable(data, counter);

	cout << endl;
	averageGPA(data, counter);


	return 0; // No error found
} // end of main