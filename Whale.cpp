/*
 * Whale.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#include "Whale.h"

Whale::Whale() {
	Mammal();					// First call parent constructor to set nurse = 0
	this->subType = "Whale";
}

Whale::Whale(int nurse) {
	Mammal();
	this->subType = "Whale";
	this->SetNurse(nurse);
}


