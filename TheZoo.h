/*
 * TheZoo.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 1715842_snhu
 */

#ifndef THEZOO_H_
#define THEZOO_H_

void PrintData(std::string str, unsigned int dataLength);
void PrintTrackNumber(int trackNum, unsigned int paddingLength);
void PrintTrackNumber(int trackNum, unsigned int paddingLength, std::ofstream &outputFile);
Animal* MakeAnimal(int trackNum, std::string name, std::string type, std::string subType, int numEggs, int nurse);
void GenerateData();
void AddAnimal(std::vector<Animal*>& zooAnimals);
void RemoveAnimal(std::vector<Animal*>& zooAnimals);
void LoadDataFromFile(std::vector<Animal*>& zooAnimals, std::string fileName);
void SaveDataToFile(std::vector<Animal*>& zooAnimals);
void DisplayAnimalData(std::vector<Animal*>& zooAnimals);
void DisplayMenu();
void RunZooProgram(std::vector<Animal*> zooAnimals);

#endif /* THEZOO_H_ */
