/*
 * Pelican.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef PELICAN_H_
#define PELICAN_H_

#include "Oviparous.h"

// Pelican inherits Oviparous

class Pelican : public Oviparous {

	public:

		Pelican();
		Pelican(int numEggs);	// overriding constructor with numEggs parameter
};

#endif /* PELICAN_H_ */
