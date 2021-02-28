/*
 * Mammal.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include "Animal.h"

// Define the Mammal class.  Inherits Animal base class

class Mammal : public Animal {

	public:

		Mammal();
		// Nurse data member should be 1 (nursing) or 0 (not nursing)

		// Getters
		int GetNurse() const;

		// Setters
		void SetNurse(int nurse);

	private:

		int nurse;
};

#endif /* MAMMAL_H_ */
