#include <string.h>
#include "administration.h"

// Function to add an animal to the array
int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int position) {
    if (position < 0) {
        return -1;
    }
    animalArray[position] = *animalPtr;
    return 0;
}

// Function to remove animals by name
int removeAnimal(const char* name, ANIMAL* animalArray, int number) {
    int count = 0;
    for (int i = 0; i < number; i++) {
        if (strcmp(animalArray[i].Name, name) == 0) {
            for (int j = i; j < number - 1; j++) {
                animalArray[j] = animalArray[j + 1];
            }
            count++;
            number--;
            i--;
        }
    }
    return count;
}

// Function to sort animals by age
int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength) {
    if (animalArrayLength <= 0) {
        return -1;
    }
    for (int i = 0; i < animalArrayLength - 1; i++) {
        for (int j = 0; j < animalArrayLength - i - 1; j++) {
            if (animalArray[j].Age > animalArray[j + 1].Age) {
                ANIMAL temp = animalArray[j];
                animalArray[j] = animalArray[j + 1];
                animalArray[j + 1] = temp;
            }
        }
    }
    return 0;
}

// Function to sort animals by name
int sortAnimalsByName(ANIMAL* animalArray, int animalArrayLength) {
    if (animalArrayLength <= 0) {
        return -1;
    }
    for (int i = 0; i < animalArrayLength - 1; i++) {
        for (int j = 0; j < animalArrayLength - i - 1; j++) {
            if (strcmp(animalArray[j].Name, animalArray[j + 1].Name) > 0) {
                ANIMAL temp = animalArray[j];
                animalArray[j] = animalArray[j + 1];
                animalArray[j + 1] = temp;
            }
        }
    }
    return 0;
}

// Function to find an animal by name
int findAnimalByName(const char* name, const ANIMAL* animalArray, int animalArrayLength, ANIMAL* animalPtr) {
    for (int i = 0; i < animalArrayLength; i++) {
        if (strcmp(animalArray[i].Name, name) == 0) {
            *animalPtr = animalArray[i];
            return 1;
        }
    }
    return 0;
}
