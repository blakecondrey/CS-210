/*
 * Exceptions.h
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

bool ValidateTrackNumberIsUnique(std::vector<Animal*>& zooAnimals, int trackNum);
int ValidateTrackNumber();
std::string ValidateAnimalName();
std::string ValidateAnimalType();
std::string ValidateAnimalSubType(std::string animalType);
int InputEggs(std::string animalType);
int DetermineNurse(std::string animalType);

#endif /* EXCEPTIONS_H_ */
