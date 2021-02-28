/*
 * Bat.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#include "Bat.h"

Bat::Bat() {
	Mammal();				// calling Parent will set nurse to 0
	this->subType = "Bat";	// Set Subtype = Bat
}

Bat::Bat(int nurse) {
	Mammal();
	this->subType = "Bat";
	this->SetNurse(nurse);
}


