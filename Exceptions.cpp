/*
 * Exceptions.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#include <iostream>				// cin cout
#include <stdexcept>            // exceptions
#include <string>				// C++ string class library
#include <algorithm>			// for_each - to lowercase
#include <cctype>
#include <vector>
#include "Animal.h"
#include "Exceptions.h"
using namespace std;

/*
 * 				******* MAIN NOTE HERE!!!! *******
 * Exceptions.cpp is created for exception handling to ensure that
 * user entry is valid. This is accomplished through do-while loops
 * that execute at least once to assume user input is valid.
 * A boolean assigned as "flag" is declared and set to true to initiate
 * the do-while loop, and errors set it to false. If user input
 * is determined to be valid, the loop completes and returns value.
 * try - catch exception will catch the invalid entry to output mistake
 * to the user.
 */

//creates track number

bool ValidateTrackNumberIsUnique(vector<Animal*>& zooAnimals, int trackNum) {
	unsigned int i;					// for-loop
	bool flag;						// bool type for assingment and return
	for (i = 0; i < zooAnimals.size(); ++i) {	// loop through vector to search for match
		if (zooAnimals.at(i)->GetTrackNum() == trackNum) { // comparison check
			flag = false;
		}
		else {
			flag = true;
		}
	}
	return flag;
}

int ValidateTrackNumber() {
	bool flag;					// drive exception handling
	string trackNumInString;
	int trackNum;				// for user input


	do {
		flag = true;
		try {
			cout << "Enter track number (omit leading 0's): \n";
			cin >> trackNumInString;
			cin.ignore();
			if ((trackNumInString.length() < 0) || (trackNumInString.length() > 6)) {
				throw runtime_error("\nInvalid track number.\n");
			}
			trackNum = stoi(trackNumInString); // string is now int
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			flag = false;
		}
		// if input is string literal
		catch (invalid_argument & excpt) {
			cout << "\nInvalid type; enter an integer without leading 0's.\n";
			flag = false;
		}
	} while(!flag);

	return trackNum;
}

//create animal name used to instantiate an animal
string ValidateAnimalName() {
	bool flag;
	string animalName;

	// See MAIN NOTE (lines 17 - 27) for exception handling explanation

	do {
		flag = true;
		try {
			cout << "Enter animal name: \n";
			getline(cin, animalName);
			if (animalName.length() > 15) { // limited to 15 characters
				throw runtime_error("\nSorry, name cannot exceed 15 characters.\n");
			}
		}
		catch(runtime_error& excpt) {
			cout << excpt.what();
			flag = false;
		}
	} while(!flag);

	return animalName;
}

// creates animal type used to instantiate an animal
string ValidateAnimalType() {
	bool flag;
	string animalType;

	// See MAIN NOTE (lines 17 - 27) for exception handling explanation

	do {
		flag = true;
		try {
			cout << "Enter animal type: ( (M/m) for \"mammal\" or (O/o) for \"oviparous\")\n";
			getline(cin, animalType);

			if ((animalType != "M") && (animalType != "m")
					&& (animalType != "O") && (animalType != "o")) {
				throw runtime_error("\nInvalid animal type.\n");
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what();
			flag = false;
		}
	}
	while (!flag);

	return animalType;
}

// creates sub-type used to instantiate an animal
string ValidateAnimalSubType(string animalType) {
	bool flag;
	string animalSubType;

	// See MAIN NOTE (lines 17 - 27) for exception handling explanation

	do {
		flag = true;
		try {
			cout << "Enter animal's sub-type:\n";
			getline(cin, animalSubType);

			// if w/ nested-if statements to validate animalSubType with user selection

			if ((animalType == "M") || (animalType == "m")) {
				if ((animalSubType != "bat") && (animalSubType != "sea lion") && (animalSubType != "whale")
						&& (animalSubType != "Bat") && (animalSubType != "Sea lion") && (animalSubType != "Whale")
								&& (animalSubType != "Sea Lion")) {
					throw runtime_error("\nInvalid entry. Mammal must be: bat, sea lion, or whale.\n");
				}
			}

			// if w/ nested-if statements to validate animalSubType with user selection

			if ((animalType == "O") || (animalType == "o")) {
				if ((animalSubType != "crocodile") && (animalSubType != "goose") && (animalSubType != "pelican")
						&& (animalSubType != "Crocodile") && (animalSubType != "Goose") && (animalSubType != "Pelican")) {
					throw runtime_error("\nInvalid entry. Oviparous must be: crocodile, goose, or pelican.\n");
				}
			}
		}
		catch(runtime_error& excpt) {
			cout << excpt.what();
			flag = false;
		}
	}
	while (!flag);

	return animalSubType;
}

// captures egg amount for oviparous
int InputEggs(string animalType) {
	bool flag;
	int numEggs;

	// See MAIN NOTE (lines 17 - 27) for exception handling explanation

	// if-else will automatically assign 0 eggs to mammals
	// if statement employs the exception handling for validation of
	// user input for numEggs
	if ((animalType == "O") || (animalType == "o")) {
		do {
			flag = true;
			try {
				cout << "Enter amount of eggs: \n";
				cin >> numEggs;
				cin.ignore();
				if (numEggs < 0) {
					throw runtime_error("\nInvalid entry.\n");
				}
			}
			catch(runtime_error& excpt) {
				cout << excpt.what();
				flag = false;
			}
			catch(invalid_argument& excpt) { // if user enters a string
				cout << "\nInvalid type.\n";
				flag = false;
			}
		}
		while (!flag);
	}
	else {
		numEggs = 0;
	}
	return numEggs;
}

// determines if mammal and nursing
int DetermineNurse(string animalType) {
	bool flag;
	int nurse;

	// See MAIN NOTE (lines 17 - 27) for exception handling explanation

	// if-else will automatically assign 0 to an oviparous
	// if statement employs the exception handling for validation of
	// user input for nurse
	if((animalType == "M") || (animalType == "m")) {
		do {
			flag = true;
			try {
				cout << "Enter 1 for nursing, 0 for not nursing: \n";
				cin >> nurse;
				cin.ignore();
				if ((nurse != 1) && (nurse != 0)) {
					throw runtime_error("\nInvalid entry.\n");
				}
			}
			catch (runtime_error& excpt) {
				cout << excpt.what();
				flag = false;
			}
			catch(invalid_argument& excpt) { // if user enters a string
				cout << "\nInvalid data type.\n";
				flag = false;
			}
		}
		while (!flag);
	}
	else {
		nurse = 0;
	}

	return nurse;
}
