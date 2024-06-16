#ifndef _ADMINISTRATION_H
#define _ADMINISTRATION_H

#include "animal.h"

// Function declarations
int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int position);
int removeAnimal(const char* name, ANIMAL* animalArray, int number);
int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength);
int sortAnimalsByName(ANIMAL* animalArray, int animalArrayLength);
int findAnimalByName(const char* name, const ANIMAL* animalArray, int animalArrayLength, ANIMAL* animalPtr);

#endif
