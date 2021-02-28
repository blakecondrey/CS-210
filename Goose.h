/*
 * Goose.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef GOOSE_H_
#define GOOSE_H_

#include "Oviparous.h"

// Goose inherits Oviparous

class Goose : public Oviparous {

	public:

		Goose();
		Goose(int numEggs);	// overriding constructor with numEggs parameter
};

#endif /* GOOSE_H_ */
