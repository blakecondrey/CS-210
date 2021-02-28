/*
 * Bat.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef BAT_H_
#define BAT_H_

#include "Mammal.h"

// Bat inherits Mammal

class Bat : public Mammal {

	public:

		Bat();
		Bat(int nurse);		// overriding constructor with nurse parameter
};

#endif /* BAT_H_ */
