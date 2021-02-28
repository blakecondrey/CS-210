/*
 * Animal.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>

	// Base class
class Animal {

	public:
		// Default Constructor
		Animal();

		// Destructor
		virtual ~Animal() = 0;

		// Accessors and Mutators (Setters and Getters)
		std::string GetName() const;			// return name data member
		int GetTrackNum() const;				// return trackNum data member
		std::string GetType() const;			// return type
		std::string GetSubType() const;			// return sub type

		/*
		 * A virtual function is a member function that can be overridden
		 * in a derived class by a function of the same name. At runtime,
		 * when a virtual function is called using a pointer or reference
		 * to an object, the call is dynamically determined based on the
		 * actual object type.  The virtual functions here are used
		 * to look to the sub classes for each animal type to return that
		 * instance's number of eggs or nursing flag
		 * (ZyBooks Programming Languages 8.4: Polymorphism and Virtual Member Functions)
		 */

		virtual int GetNumberOfEggs() const;
		virtual int GetNurse() const;

		// Setters
		void SetName(std::string name);						// set the animal's name
		void SetTrackNum(int trackNum);						// set the aniaml's tracknum
		virtual void SetNumberOfEggs(int numEggs);			// calls Oviparous' function
		virtual void SetNurse(int nurse);					// calls Mammal's function

	private:

		std::string name;
		int trackNum;
		int numEggs;
		int nurse;

	protected:							// These fields are protected so they can
										// be accessed at the subclass level.
		std::string type;				// type to be defined at subclass level
		std::string subType;			// sub-type to be defined at subclass level
};

#endif /* ANIMAL_H_ */
