#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "administration.h"

int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int position) {
    if (position >= MAX_ANIMALS) {
        printf("SORRY! Our shelter is full\n");
        return -1; //  If No position available in our shelter
    }
    animalArray[position] = *animalPtr;
    return 0; // if there is Position available in our shelter
}

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

int saveAnimalsToFile(const char* filename, const ANIMAL* animalArray, int numAnimals) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        return -1;
    }

    for (int i = 0; i < numAnimals; i++) {
        fprintf(file, "%s %d %d\n", animalArray[i].Name, (int)animalArray[i].Species, animalArray[i].Age);
    }

    fclose(file);
    printf("Animals saved to file %s successfully.\n", filename);
    return 0; 
}

int loadAnimalsFromFile(const char* filename, ANIMAL* animalArray, int* numAnimals) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Can't open file %s for reading.\n", filename);
        return -1;
    }

    *numAnimals = 0;
    while (fscanf(file, " %24s %d %d", animalArray[*numAnimals].Name, (int*)&animalArray[*numAnimals].Species, &animalArray[*numAnimals].Age) == 3) {
        (*numAnimals)++;
        if (*numAnimals >= MAX_ANIMALS) {
            fclose(file);
            return -1; 
        }
    }

    fclose(file);
    printf("Animals loaded from file %s successfully.\n", filename);
    return 0; 
}

int sortAnimalsByName(ANIMAL* animalArray, int animalArrayLength) {
    int sorted = 0;
    for (int i = 0; i < animalArrayLength - 1; i++) {
        for (int j = 0; j < animalArrayLength - i - 1; j++) {
            if (strcmp(animalArray[j].Name, animalArray[j + 1].Name) > 0) {
                ANIMAL temp = animalArray[j];
                animalArray[j] = animalArray[j + 1];
                animalArray[j + 1] = temp;
                sorted = 1;
            }
        }
    }
    return sorted ? 0 : -1; // Return 0 if sorted, -1 if already sorted or empty array
}

int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength) {
    int sorted = 0;
    for (int i = 0; i < animalArrayLength - 1; i++) {
        for (int j = 0; j < animalArrayLength - i - 1; j++) {
            if (animalArray[j].Age > animalArray[j + 1].Age) {
                ANIMAL temp = animalArray[j];
                animalArray[j] = animalArray[j + 1];
                animalArray[j + 1] = temp;
                sorted = 1;
            }
        }
    }
    return sorted ? 0 : -1; // Return 0 if sorted, -1 if already sorted or empty array
}

int findAnimalByName(const char* name, const ANIMAL* animalArray, int animalArrayLength, ANIMAL* animalPtr) {
    if (name == NULL || animalArray == NULL || animalPtr == NULL) {
        return -1; // Return -1 if any input parameter is invalid
    }
    
    for (int i = 0; i < animalArrayLength; i++) {
        if (strcmp(animalArray[i].Name, name) == 0) {
            *animalPtr = animalArray[i];
            return 1; // Return 1 if animal found
        }
    }
   
    return 0; // Return 0 if animal not found
}
