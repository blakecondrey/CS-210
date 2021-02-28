/*
 * main.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: blakecondrey
 */

#include <iostream> // cin/cout
#include <jni.h>	// for java code
#include <vector>	//create vector of animals that are pointers to base class
#include "Bat.h"
#include "Crocodile.h"
#include "Exceptions.h"
#include "Goose.h"
#include "Pelican.h"
#include "SeaLion.h"
#include "Whale.h"
#include "TheZoo.h"

using namespace std;

int main() {
	vector<Animal*> zooAnimals;
	RunZooProgram(zooAnimals);
	return 0;
}
