/*
 * Crocodile.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "Oviparous.h"

// Crocodile inherits Oviparous

class Crocodile : public Oviparous {

	public:

		Crocodile();
		Crocodile(int numEggs);	// overriding constructor with numEggs parameter
};

#endif /* CROCODILE_H_ */
