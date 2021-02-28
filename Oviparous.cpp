/*
 * Oviparous.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */
#include "Oviparous.h"

// Constructor
Oviparous::Oviparous() {
	this->numEggs = 0;		// Default to no eggs
	this->type = "Oviparous";
}

// Getters
int Oviparous::GetNumberOfEggs() const {
	return this->numEggs;
}

// Setters
void Oviparous::SetNumberOfEggs(int numEggs) {
	this->numEggs = numEggs;
	return;
}



