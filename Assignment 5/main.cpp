#include <iostream>
#include <fstream>
// Jason Hammar, May 21, 2019, this program calculates the weight of
// people whose data is in a text file who are five feet tall or taller.
using namespace std;

int main()
{
	ifstream input;

	int heightInFeet, additionalInches;
	int totalWeight;
	string name;
	// this is how many pounds someone weighs if they are five feet tall.
	const int FIVE_FEET_POUNDS = 110;
	input.open("names-1.txt");

	if(!input){// checks if the file can open.
    	cout << "file open failure. ";
	}else{
// If the file can open, the program then attempts to calculate
// the weight of that person.
	while(getline(input, name) && input >> heightInFeet >> additionalInches){
    // While there is a name and height, this loop keeps going.
    	// Calculation for weight of people as tall as or taller than 5 feet.
    	if(heightInFeet >= 5){
        	totalWeight = FIVE_FEET_POUNDS + (
        	(heightInFeet - 5) * 12 + additionalInches) * 5;
        	cout << "The ideal body weight for ";
        	cout << name << " is: " << totalWeight;
        	cout << endl;
    	}else// Prints this statement if the person is shorter than 5 feet.
        	cout << "I can't calculate the weight of " << name << endl;

    	input.ignore();
	}


	input.close();
	}
	return 0;
}
/* Sample Run:
Note: The height of Eaton Wright and Cary Oki has been changed.
The ideal body weight for Tom Atto is: 185
The ideal body weight for Eaton Wright is: 150
The ideal body weight for Cary Oki is: 220
I can't calculate the weight of Omar Ahmed

Process returned 0 (0x0)   execution time : 0.035 s
Press any key to continue.
*/


