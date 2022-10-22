/*
 * The purpose of this program is to calculate the distance an object travels in meters on Earth for a specified
 * number of seconds. The program will also calculate the distance traveled on the Moon in meters for the specified number
 * of seconds. There will be a function in the program to read in seconds in the beginning and there will be a display
 * function at the end of the program.
 */
#include <iostream>
#include <cmath> // Needed pow for calculating earthDistance and moonDistance.
#include <iomanip> // Needed setprecision for setting the precision of display values.
using namespace std; // For convenience

// Function reads in number of seconds needed for calculating distances.
double readSeconds(double& seconds) {
    cout << "Enter the time (in seconds)" << endl;
    cin >> seconds;
    return seconds;
}

// Function calculates the distance an object travels on Earth in meters for a specific number of seconds.
double calculateEarthDistance(double seconds) {
    double earthDistance;
    const double gravityAcceleration = 9.8;
    earthDistance = 0.5 * gravityAcceleration * pow(seconds, 2);
    cout << fixed << setprecision(4);
    return earthDistance;
}

// Function calculates the distance an object travels on the Moon in meters for a specific number of seconds.
double calculateMoonDistance(double seconds) {
    double moonDistance;
    const double moonAcceleration = 1.6;
    moonDistance = 0.5 * moonAcceleration * pow(seconds, 2);
    cout << fixed << setprecision(4);
    return moonDistance;
}

// Function outputs the distance traveled on Earth and the Moon to the fourth precision and
// the seconds to the second precision.
void displayResults(double seconds, double earthDistance, double moonDistance) {
    cout << fixed << setprecision(4) << "The object traveled " << earthDistance << " meters in " <<
                        setprecision(2) << seconds << " seconds on Earth" << endl;
    cout << fixed << setprecision(4) << "The object traveled " << moonDistance << " meters in " <<
                        setprecision(2) << seconds << " seconds on the Moon" << endl;
}

// Function is the main driver of program and calls all the other functions.
int main () {
   double seconds; // Initializing number of seconds in the program.

    while(readSeconds(seconds) != 0) { // Calls the readSeconds function repeatedly until the value is not 0.
        if(seconds < 0) { // Checks if the number of seconds inputted is positive.
            cout << "The time must be zero or more" << endl;
        }
        if(seconds > 0) { // Checks if seconds are greater than zero and calls the other 3 functions.
            double earthDistance = calculateEarthDistance(seconds);
            double moonDistance = calculateMoonDistance(seconds);
            displayResults(seconds, earthDistance, moonDistance);
        }
        if(seconds == 0) { // Checks if the seconds is equal to zero to end the program.
            break;
        }
    }
}