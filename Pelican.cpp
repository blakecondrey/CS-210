/*
 * Pelican.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#include "Pelican.h"

Pelican::Pelican() {
	Oviparous();				// First call parent constructor to set eggs = 0
	this->subType = "Pelican";
}

Pelican::Pelican(int numEggs) {
	Oviparous();
	this->subType = "Pelican";
	this->SetNumberOfEggs(numEggs);
}


