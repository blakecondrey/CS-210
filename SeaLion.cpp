/*
 * SeaLion.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#include "SeaLion.h"

SeaLion::SeaLion() {
	Mammal();					// First call parent constructor to set nurse = 0
	this->subType = "Sea Lion";
}

SeaLion::SeaLion(int nurse) {
	Mammal();
	this->subType = "Sea Lion";
	this->SetNurse(nurse);
}


