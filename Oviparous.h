/*
 * Oviparous.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_

#include "Animal.h"

// Define the Oviparous class- the egg layers.  Inherits Animal base class
// using a public interface.  This makes all member components in Animal
// publicly available to Oviparous if the member component is itself defined
// as public in the Animal class.

class Oviparous : public Animal {

	public:
		// Constructor
		Oviparous();

		// Getters
		int GetNumberOfEggs() const;

		// Setters
		void SetNumberOfEggs(int numEggs);

	private:

		int numEggs;
};

#endif /* OVIPAROUS_H_ */
