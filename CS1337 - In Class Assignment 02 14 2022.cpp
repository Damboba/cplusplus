#include <iostream>
#include <fstream>
using namespace std;


// a) Ask for the number of samples to be generated N [1, 100];
int getNumberOfSamples();

// b) Generate the N samples and store them in a file named text.txt
int generateSamplesAndStoreInFile(int);
// c) Read the file data into an array of integers named data
int readValuesFromFile(int[], int);

// d) Sort the array in non-decreasing order(from smalles to largest)
void bubbleSort(int[], int);
// e) Implement linear search and ask the user for the key
// bool searchForAValue(int[], int, int);
//ICA for 2/14: implement the recursive version of the binary search
int recursiveBinarySearchForAValue(int values[], int SIZE, int key);

// Exit keyword will finish the program, regardless of where it is called


int main() {
	int N = getNumberOfSamples();
	if (generateSamplesAndStoreInFile(N) == -1) {
		return -1;
	}
	int data[100];
	if (readValuesFromFile(data, N) == -2) {
		return -2;
	}

	bubbleSort(data, N);

	int key;
	cout << "Enter a value to search: ";
	cin >> key;
		if (recursiveBinarySearchForAValue(data, N, key) == -1) {
			cout << "The value " << key << " was not found!\n";
		}
		else {
			cout << "The value " << key << " was found!\n";
		}

	return 0;
}

int getNumberOfSamples() {
	int M;
	do {
		cout << "Please enter the number of samples [1, 100]: ";
		cin >> M;
	} while (M < 0 || M > 100);
	return M;
}

int generateSamplesAndStoreInFile(int M) {
	ofstream output;
	// srand(11);
	output.open("test.txt");
	if (!output.is_open()) {
		cout << "Error opening the file for writing...\n";
		return -1;
	}
	for (int i = 0; i < M; i++) {
		output << rand() << endl;
	}
	output.close();
	return 0;
}

int readValuesFromFile(int values[], int SIZE) {
	ifstream input;
	input.open("test.txt");
	if (!input.is_open()) {
		cout << "Error opening the file for writing...\n";
		return -1;
	}
	int index = 0;
	while (!input.eof() && index < SIZE) {
		input >> values[index];
		index++;
	}
	input.close();
	return 0;
}

void bubbleSort(int values[], int N) {
	int temp; // helper for swapping
	bool swap;
	do {
		swap = false;
		for (int i = 0; i < N - 1; i++) {
			if (values[i] > values[i + 1]) {
				temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
	
	ofstream output;										// For convenience, so values in test.txt appear sorted.
	output.open("test.txt");
	if (!output.is_open()) {
		cout << "Error opening the file for writing...\n";
	}
	for (int i = 0; i < N; i++) {
		output << values[i] << endl;
	}
}

int recursiveBinarySearchForAValue(int values[], int SIZE, int key) {
	int first = 0, last = SIZE - 1, middle, position = -1;
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (values[middle] == key) {
			found = true;
			position = middle;
		} 
		else if (values[middle] > key) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}
	}
	return position;
}


/*
bool searchForAValue(int values[], int SIZE, int key) {
	for (int i = 0; i < SIZE; i++) {
		if (values[i] == key)
			return true;

	}
	return false;
}
*/