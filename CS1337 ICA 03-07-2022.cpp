/*
CS1337.002
03-07-2022
Damboba Hebo

PROGRAM 1:
Given a file with the following format:
<ID>	<X_COOORD>	<Y_COORD>	<CITY_NAME>
Where
ID is a unique integer >0
X_COORD is a double with the x coordinate
Y_COORD is a double with the y coordinate
CITY_NAME is a string that may or may not include spaces

e.g.
123 934.56	12.45	ATLANTA
567	01245.2	78.956	AUSTIN, TX

Write a program to
a) define a structure per record(id, x, y, city name)
b) show a menu like:
	a) Enter cities
		1.- by ID
		2.- by NAME
	c) Compute the distance between the two cities
	d) Find the closest city to city1
	e) exit

ICA 3-10-2022 - Complete the PROGRAM 1
2 options: a) Use dynamic arrays, or b) assume the maximum number
*/

#include <iostream> //cin/cout
#include <fstream>  //file handling/processing
#include <string>	//string data type and operations 
#include <iomanip>	//Output formatting
#include <cmath>

using namespace std;
#define SIZE 100

struct city { // Define a structure per record(id, x, y, city name)
	int id = 0;
	double xcoord = 0.0;
	double ycoord = 0.0;
	string cityname;
};

// Write a funtion to count how many records we have in the input file
int countNumberOfRecords(string filename) {
	ifstream input;
	input.open(filename.c_str());
	if (!input.is_open()) {
		cout << "Error";
		return -1;
	}

	string helper; int counter = 0;
	while (!input.eof()) {
		getline(input, helper);
		counter++;
	}
	input.close();
	return counter;
}

int fileError() {
	cout << "Error";
	return -2;
}

city* readFileContent(string filename) {
	ifstream input;
	int size = countNumberOfRecords(filename);
	city * cityInfo = new city[size];
	
	input.open(filename.c_str());
		if (!input.is_open()) {
			int fileError();
		}
		
	cout << "Press Enter to show menu";
	char ch;
	ch = getchar();

	int counter = 0;
	//EOF returns true when end of file
	while (!input.eof() && counter < size) {
		input >> cityInfo[counter].id >> cityInfo[counter].xcoord >> cityInfo[counter].ycoord >> ch;
		getline(input, cityInfo[counter].cityname);
		cityInfo[counter].cityname = ch + cityInfo[counter].cityname;
		counter++;
	}
	input.close();
	return cityInfo;
}

int main() {
	string filename = "test.txt";
	int size = countNumberOfRecords(filename);
	//int * intArray = new int[size];
	city * cityInfo = readFileContent(filename);
	//To prepare the menu
	int index_city1 = -1, index_city2 = -1, city1id = 0, city2id = 0, counter = 0;
	string city1name, city2name;
	bool testID = false, testNAME = false;
	double distance = 0.0, d1x = 0.0, d1y = 0.0, d2x = 0.0, d2y = 0.0;
	int count1 = 0, count2 = 0;

	char option;
	do {
		cout << "a) Enter cities\n";
		cout << "c) Compute the distance between the two cities\n";
		cout << "d) Find the closest city to city1\n";
		cout << "e) exit\n";
		cin >> option;
		while ((getchar() != '\n')); // This will remove the leftovers in the input
		
	switch (option) {
		case 'A':
		case 'a':
			// Present another menu.
			char option2;
			do {
				cout << "1) by ID\n2) by name\n";
				cin >> option2;
				while ((getchar() != '\n'));
			} while (option2 != '1' && option2 != '2');

			switch (option2) {
			case '1': //write you code or function call here
					do {
						cout << "Enter the ID of CITY 1: ";
						cin >> city1id;
						cout << "Enter the ID of CITY 2: ";
						cin >> city2id;
						if (city1id < 0 || city2id < 0) {
							cout << "Enter an ID value greater than 0!\n";
						}
					} while (city1id < 0 || city2id < 0);
					while (counter < size) {
						if (city1id == cityInfo[counter].id) {
							cout << "City 1 Info:\n";
							cout << cityInfo[counter].id << "\t"
								<< cityInfo[counter].xcoord << "\t"
								<< cityInfo[counter].ycoord << "\t"
								<< cityInfo[counter].cityname << "\n";
						}
						if (city2id == cityInfo[counter].id) {
							cout << "City 2 Info:\n";
							cout << cityInfo[counter].id << "\t"
								<< cityInfo[counter].xcoord << "\t"
								<< cityInfo[counter].ycoord << "\t"
								<< cityInfo[counter].cityname << "\n";

						}
						counter++;
						testID = true;
					}
				break;
			case '2': //write you code or function call here
				// City 1 Name Prompt and Read In
				cout << "Enter the NAME of CITY 1: ";
				getline(cin, city1name);
				// City 2 Name Prompt and Read In
				cout << "Enter the NAME of CITY 2: ";
				getline(cin, city2name);

				while (counter < size) {
					if (city1name == cityInfo[counter].cityname) {
						cout << "City 1 Info:\n";
						cout << cityInfo[counter].id << "\t"
							<< cityInfo[counter].xcoord << "\t"
							<< cityInfo[counter].ycoord << "\t"
							<< cityInfo[counter].cityname << "\n";
					}
					if (city2name == cityInfo[counter].cityname) {
						cout << "City 2 Info:\n";
						cout << cityInfo[counter].id << "\t"
							<< cityInfo[counter].xcoord << "\t"
							<< cityInfo[counter].ycoord << "\t"
							<< cityInfo[counter].cityname << "\n";
					}
					counter++;
					testNAME = true;
				}
				break;
			default: break;
			}
				break;

			//Test if the user already select the ids/names, warn the user to choose the ids/names first, if you have the values, compute the distance
			case 'C':
			case 'c':
				if (testID || testNAME) {
					while (counter < size) {
						//d = sqrt(pow(cityInfo[city1].xcoord - cityInfo[city2].xcoord, 2) + pow(allStudents[city1].ycoord - allStudents[city2].ycoord, 2));
						if (city1id == cityInfo[counter].id || city1name == cityInfo[counter].cityname) {
							d1x = cityInfo[counter].xcoord;
							d1y = cityInfo[counter].ycoord;
						}
						if (city2id == cityInfo[counter].id || city2name == cityInfo[counter].cityname) {
							d2x = cityInfo[counter].xcoord;
							d2y = cityInfo[counter].ycoord;
						}
						counter++;
					}
				} else if (!testID) {
					cout << "Choose the IDs/Names First (Submenu of a)" << endl;
				}
				else if (!testNAME) {
					cout << "Choose the IDs/Names First (Submenu of a)" << endl;
				}


				distance = sqrt(pow(d1x - d2x, 2) + pow(d1y - d2y, 2));
				cout << "Distance between Cities: " << d1x << " " << d2x << endl;
				break;
			
			//Compute the distance to all the other cities, select the small(closest)
			case 'D':
			case 'd':
				/*counter = 0;
				double distance = 0.0;
				int temp = 0;
				while (counter < size)
				{
					if (city1id == cityInfo[counter].id || city1name == cityInfo[counter].cityname) {

					}
				}
				cout << distance << endl;
				break;
			default: cout << "Invalid option, please try again.. \n"; */
				break;
			}
	} while (option != 'e' && option != 'E');
	
	return 0;// To indicate no error
} // end of main