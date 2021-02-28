/*
 * Goose.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#include "Goose.h"

Goose::Goose() {
	Oviparous();				// First call parent constructor to set eggs = 0
	this->subType = "Goose";	// Set Subtype = Goose
}

Goose::Goose(int numEggs) {
	Oviparous();
	this->subType = "Goose";
	this->SetNumberOfEggs(numEggs);
}

