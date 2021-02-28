/*
 * Whale.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef WHALE_H_
#define WHALE_H_

#include "Mammal.h"

// Whale inherits Mammal

class Whale : public Mammal {

	public:

		Whale();
		Whale(int nurse);		// overriding constructor with nurse parameter
};

#endif /* WHALE_H_ */
