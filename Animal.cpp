/*
 * Animal.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#include "Animal.h"

// Constructor
Animal::Animal() {
	this->name = "None";
	this->trackNum = -1;
	this->type = "None";
	this->subType = "None";
	this->numEggs = -1;
	this->nurse = -1;
}

// Parameterized constructor


// Destructor
Animal::~Animal() {};

// Getters (Accessors)

/*
 * "const" to raise error if getter is
 * attempting to change value of field
 */
std::string Animal::GetName() const {
	return this->name;
}

int Animal::GetTrackNum() const {
	return this->trackNum;
}

std::string Animal::GetType() const {
	return this->type;
}

std::string Animal::GetSubType() const {
	return this->subType;
}

int Animal::GetNurse() const {
	return 0;
}

int Animal::GetNumberOfEggs() const {
	return 0;
}

// Setters (Mutators)
void Animal::SetName(std::string name) {
	this->name = name;
}

void Animal::SetTrackNum(int trackNum) {
	this->trackNum = trackNum;
}

void Animal::SetNumberOfEggs(int numEggs) {
}

void Animal::SetNurse(int nurse) {
}


