/*
 * Crocodile.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#include "Crocodile.h"

Crocodile::Crocodile() {
	Oviparous();
	this->subType = "Crocodile";

}

Crocodile::Crocodile(int numEggs) {
	Oviparous();
	this->subType = "Crocodile";
	this->SetNumberOfEggs(numEggs);
}


