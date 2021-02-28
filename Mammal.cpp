/*
 * Mammal.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */
#include "Mammal.h"

// Constructor
Mammal::Mammal() {
	this->nurse = 0;			// Default to not nursing
	this->type = "Mammal";
}

// Getters
int Mammal::GetNurse() const {
	return this->nurse;
}

// Setters
void Mammal::SetNurse(int nurse) {
	this->nurse = nurse;
}



