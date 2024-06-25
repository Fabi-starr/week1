#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <stdio.h>
#include "animal.h"
#define MAX_ANIMALS 3

int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int position);
int removeAnimal(const char* name, ANIMAL* animalArray, int number);
int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength);
int sortAnimalsByName(ANIMAL* animalArray, int animalArrayLength);
int saveAnimalsToFile(const char* filename, const ANIMAL* animalArray, int numAnimals);
int loadAnimalsFromFile(const char* filename, ANIMAL* animalArray, int* numAnimals);
int findAnimalByName(const char* name, const ANIMAL* animalArray, int animalArrayLength, ANIMAL* animalPtr);

#endif // ADMINISTRATION_H
