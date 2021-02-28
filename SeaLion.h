/*
 * SeaLion.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef SEALION_H_
#define SEALION_H_

#include "Mammal.h"

// SeaLion inherits Mammal

class SeaLion : public Mammal {

	public:

		SeaLion();
		SeaLion(int nurse);		// overriding constructor with nurse parameter
};

#endif /* SEALION_H_ */
