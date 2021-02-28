#include <iostream>
#include <jni.h>
#include <fstream>		// library for file i/o
#include <stdexcept>	// for runtime_error object
#include <string>
#include <vector>
#include <typeinfo>

#include "Bat.h"
#include "Crocodile.h"
#include "Exceptions.h"
#include "Goose.h"
#include "Pelican.h"
#include "SeaLion.h"
#include "Whale.h"

using namespace std;


void PrintData(string str, unsigned int dataLength) {
	unsigned int i;		// for loop
	int stringLength = str.length();
	cout << str;
	for (i = stringLength; i < dataLength; ++i) {
		cout << " ";
	}
}

// pads numbers with leading 0s
void PrintTrackNumber(int trackNum, unsigned int paddingLength) {
	unsigned int i;
	string leadZero;	// num will cast to string type, the leadzero can be prefixed to str
	char buffer [10];
	string trackNumInString;
	trackNumInString = itoa((trackNum), buffer, 10);
	for (i = trackNumInString.length(); i < paddingLength; ++i) {
		leadZero += "0";
	}
	leadZero += trackNumInString;
	cout << leadZero;
}
// animal constructing function function to create animal to add to vector
Animal* MakeAnimal(int trackNum, string name, string type, string subType, int numEggs, int nurse) {

	Animal* animal = nullptr;

	if ((subType == "Crocodile") || (subType == "crocodile")) {
		Crocodile* animal = new Crocodile(numEggs);
		animal->SetTrackNum(trackNum);
		animal->SetName(name);
		return animal;
	}
	else if ((subType == "Goose") || (subType == "goose")) {
		Goose* animal = new Goose(numEggs);
		animal->SetTrackNum(trackNum);
		animal->SetName(name);
		return animal;
	}
	else if ((subType == "Pelican") || (subType == "pelican")) {
		Pelican* animal = new Pelican(numEggs);
		animal->SetTrackNum(trackNum);
		animal->SetName(name);
		return animal;
	}
	else if ((subType == "Bat") || (subType == "bat")) {
		Bat* animal = new Bat(nurse);
		animal->SetTrackNum(trackNum);
		animal->SetName(name);
		return animal;
	}
	else if ((subType == "Whale") || (subType == "whale")) {
		Whale* animal = new Whale(nurse);
		animal->SetTrackNum(trackNum);
		animal->SetName(name);
		return animal;
	}
	else if ((subType == "Sea Lion") || (subType == "sea lion")) {
		SeaLion* animal = new SeaLion(nurse);
		animal->SetTrackNum(trackNum);
		animal->SetName(name);
		return animal;
	}

	return animal;
}

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void AddAnimal(vector<Animal*>& zooAnimals) {
	// prompt user to enter necessary data to make a new animal and add to vector of zoo animals
	// all "Input______" functions below are from "Exceptions.h" header file
	bool flag;				// for exception handling to verify trackNum is unique
	int trackNum;			// to capture trackNum
	unsigned int i;

	do {
		flag = true;
		try {
			trackNum = ValidateTrackNumber();	// caputre and validate trackNum
			// loop through zooAnimals vector to ensure trackNum is unique
			for (i = 0; i < zooAnimals.size(); ++i) {
				if (trackNum == zooAnimals.at(i)->GetTrackNum()) {
					throw runtime_error("\nTrack number already in use.\n");
				}
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what();
			flag = false;
		}
	}
	while (!flag);

    string animalName = ValidateAnimalName();
    string animalType = ValidateAnimalType();
    string animalSubType = ValidateAnimalSubType(animalType);
    int numEggs = InputEggs(animalType);
    int nurse = DetermineNurse(animalType);

    // create nullptr to point to object
    Animal* animal = nullptr;
    // make animal with variables determined
    animal = MakeAnimal(trackNum, animalName, animalType, animalSubType, numEggs, nurse);


    cout << "Track Number: " << animal->GetTrackNum() << endl;
    cout << "Animal Name: " << animal->GetName() << endl;
    cout << "Animal Type: " << animal->GetType() << endl;
    cout << "Animal Sub-Type: " << animal->GetSubType() << endl;
    cout << "Number of eggs: " << animal->GetNumberOfEggs() << endl;
    cout << "Nursing: " << animal->GetNurse() << endl << endl;

    zooAnimals.push_back(animal);		// add animal object to vector
    cout << animal->GetName() << " has been successfully added.\n\n\n"; // simple print to show valid creation
}


void RemoveAnimal(vector<Animal*>& zooAnimals) {

	/*
	 * A boolean assigned as "flag" is declared and set to true to initiate
	 * the do-while loop, and errors set it to false. If user input
	 * is determined to be valid, the loop completes and returns value.
	 * try - catch exception will catch the invalid entry to output mistake
	 * to the user.
	 */

	bool flag;
	bool validMatch = false;	// to run removal by comparing; will determine if valid match track number
	string trackNumInString;	// first in string to ensure length is > 0 but <= 6
	int trackNum;				// will convert string above to this int
	unsigned int i;		// for loops iteration var

	cout << "\nRemove Animal by track number.\n";

	do {
		flag = true;
		try {
			cout << "Enter a track number without leading zeroes.\n";
			cin >> trackNumInString;

			// track numbers are limited to 6 characters. throw error if > 6
			if ((trackNumInString.length() < 0) || (trackNumInString.length() > 6)) {
				throw runtime_error("\nInvalid entry.\n");
			}
			trackNum = stoi(trackNumInString);
		}
		catch (runtime_error& excpt) {
			cout << excpt.what();
			flag = false;
		}
		// if user input is string literal
		catch (invalid_argument& excpt) {
			cout << "\nInvalid type.\n";
			flag = false;
		}
	}
	while (!flag);

	// loop determines if there is a match to switch boolean validMatch to true
	for (i = 0; i < zooAnimals.size(); ++i) {
		if (trackNum == zooAnimals.at(i)->GetTrackNum()) {
			validMatch = true;
			break;
		}
	}
	// now true, proceed to delete
	if (validMatch) {
		for (i = 0; i < zooAnimals.size(); ++i) {
			if (trackNum == zooAnimals.at(i)->GetTrackNum()) {
				cout << trackNum << " found. Removing animal.\n";
				delete zooAnimals.at(i);
				zooAnimals.erase(zooAnimals.begin() + i);
				break;
			}
		}
		cout << "\nAnimal removed.\n\n\n";
	}
}

void LoadDataFromFile(vector<Animal*>& zooAnimals, string fileName) {
	Animal* animal = nullptr;		// null ptr to animal object
	zooAnimals.clear();				// empties the zoo vector
	ifstream inputFile;				// for reading
	int trackNum = -1;				// flag for error
	string animalName;
	string animalType;
	string animalSubType;
	int numEggs;
	int nurse;
	int tTrackNum;

	inputFile.open(fileName);		// opening the file
	if (!inputFile.is_open()) {		// test that file opened
		cout << "File not found" << endl;
	}
	else {
		while (!inputFile.eof()) {	// until end of file is reached
			tTrackNum = trackNum;	// read all contents from file sequentially
			inputFile >> trackNum;
			inputFile >> animalName;
			inputFile >> animalType;
			inputFile >> animalSubType;
			inputFile >> numEggs;
			inputFile >> nurse;
			if (trackNum == tTrackNum) {	// stop to load data
				break;
			}
			// makes animal object from .txt file
			animal = MakeAnimal(trackNum, animalName, animalType, animalSubType, numEggs, nurse);
			zooAnimals.push_back(animal);	// puts animal object into emptied list
		}
	}
	inputFile.close();	// close file
	cout << "\nLoad successful.\n" << endl;
}

void SaveDataToFile(vector<Animal*>& zooAnimals) {
	unsigned int i;		// for-loop iteratin var
	string fileName = "zoodata.txt";	// to search and find file, had trouble using it as param
	ofstream outputFile;	// for output file
	outputFile.open(fileName);

	if (!outputFile.is_open()) {
		cout << "\nFile not found\n";
	}
	else {							// if-else and for-loop chain creates temp animal-type
									// object to output to file
		for (i = 0; i < zooAnimals.size(); ++i) {
			if ((zooAnimals.at(i)->GetType() == "Oviparous")
					|| (zooAnimals.at(i)->GetType() == "oviparous")) {
				Oviparous* tempOv = (Oviparous*)zooAnimals.at(i);
				outputFile << tempOv->GetTrackNum() << endl;
				outputFile << tempOv->GetName() << endl;
				outputFile << tempOv->GetType() << endl;
				outputFile << tempOv->GetSubType() << endl;
				outputFile << tempOv->GetNumberOfEggs() << endl;
				outputFile << tempOv->GetNurse() << endl;
			}
			else if ((zooAnimals.at(i)->GetType() == "Mammal")
					|| (zooAnimals.at(i)->GetType() == "mammal")) {
				Mammal* tempMm = (Mammal*)zooAnimals.at(i);
				outputFile << tempMm->GetTrackNum() << endl;
				outputFile << tempMm->GetName() << endl;
				outputFile << tempMm->GetType() << endl;
				outputFile << tempMm->GetSubType() << endl;
				outputFile << tempMm->GetNumberOfEggs() << endl;
				outputFile << tempMm->GetNurse() << endl;
			}
		}

		cout << "\nSave successfuly completed.\n\n\n";
	}

}

// to output animal data from vector
void DisplayAnimalData(vector<Animal*>& zooAnimals) {
	unsigned int i;
	string tableHeader = 	"Track# \t"
							"Name           \t"
							"Type           \t"
							"Sub-Type       \t"
							"Eggs  \t"
							"Nurse \t";
	cout << tableHeader << endl;
	for (i = 0; i < zooAnimals.size(); ++i) {
		Animal* animal = zooAnimals.at(i);
		PrintTrackNumber(animal->GetTrackNum(), 6);
		cout << " \t";
		PrintData(animal->GetName(), 15);
		cout << "\t";
		PrintData(animal->GetType(), 15);
		cout << "\t";
		PrintData(animal->GetSubType(), 15);
		cout << "\t";
		cout << animal->GetNumberOfEggs();
		if (animal->GetNumberOfEggs() > 9) {
			cout << "\t   ";
		}
		else if (animal->GetNumberOfEggs() > 99) {
			cout << "\t  ";
		}
		else {
			cout << "\t    ";
		}
		cout << animal->GetNurse() << "   " << endl;
	}
	cout << endl << endl;
}

void DisplayMenu() {
     string mainMenu = 	"\t\t****************************\n"
    		 	 	 	"\t\t* 1 - Load Animal Data     *\n"
    		 	 	 	"\t\t* 2 - Generate Data        *\n"
    		 	 	 	"\t\t* 3 - Display Animal Data  *\n"
    		 	 	 	"\t\t* 4 - Add Animal Record    *\n"
    		 	 	 	"\t\t* 5 - Delete Animal Record *\n"
    		 	 	 	"\t\t* 6 - Save Animal Data     *\n"
    		 	 	 	"\t\t* 7 - Quit                 *\n"
    		 	 	 	"\t\t****************************\n\n\n";

     cout << mainMenu;
}

// function will be called in main.cpp to run interface
void RunZooProgram(vector<Animal*> zooAnimals) {
	bool flag;
	int userChoice;

	cout << "\n\n\n\t\tWelcome to the Wildlife Zoo!\n\n";
	while (userChoice != 7) {

	/*
	 * A boolean assigned as "flag" is declared and set to true to initiate
	 * the do-while loop, and errors set it to false. If user input
	 * is determined to be valid, the loop completes and returns value.
	 * try - catch exception will catch the invalid entry to output mistake
	 * to the user.
	 */

		do {
			flag = true;
			try {
				DisplayMenu();
				cin >> userChoice;
				if ((userChoice < 1) || (userChoice > 7)) {
					throw runtime_error("\nInvalid response.\n");
				}
			}
			catch (runtime_error& excpt) {
				cout << excpt.what();
				flag = false;
			}
			// catch string input
			catch (invalid_argument& excpt) {
				cout << "\nInvalid data type.\n";
				flag = false;
			}
		}
		while (!flag);

		switch (userChoice) {

			case 1:
				LoadDataFromFile(zooAnimals, "zoodata.txt");
				break;

			case 2:
				GenerateData();
				break;

			case 3:
				DisplayAnimalData(zooAnimals);
				break;

			case 4:
				AddAnimal(zooAnimals);
				break;

			case 5:
				RemoveAnimal(zooAnimals);
				break;

			case 6:
				SaveDataToFile(zooAnimals);
				break;

			case 7:
			default:
				cout << "\n\n\t\tGoodbye.";
				exit(0);
				break;
		}
	}
}
