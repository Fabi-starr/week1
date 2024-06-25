#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "administration.h"

#define FILENAME "animals.txt"
#define MAX_INPUT_LENGTH 10
#define MAX_ANIMALS 5

const char* speciesNames[] = {"Cat", "Dog", "GuineaPig", "Parrot"};

void addAnimalPrompt(ANIMAL* animalArray, int* numAnimals) {
    ANIMAL animal;
    while (1) {
        int isValidName = 1; // Resetting for each loop iteration
        printf("Enter animal name: ");
        scanf("%s", animal.Name);

        for (int i = 0; animal.Name[i] != '\0'; i++) {
            if (!isalpha(animal.Name[i])) {
                isValidName = 0;
                break;
            }
        }
        if (!isValidName) {
            printf("Enter name with only alphabetic characters.\n");
            continue;
        }
        break; // Name is valid, proceed to next input
    }

    while (1) {
        printf("Choose the species of your animal (0: Cat, 1: Dog, 2: GuineaPig, 3: Parrot): ");
        scanf("%d", (int*)&animal.Species);
        if (animal.Species < 0 || animal.Species > 3) {
            printf("You have to choose from our species only: 0, 1, 2, 3.\n");
            continue;
        }
        break; // Species is valid, proceed to next input
    }

    while (1) {
        printf("Enter age of animal between 0 and 200: ");
        scanf("%d", &animal.Age);
        if (animal.Age < 0 || animal.Age > 200) {
            printf("Age must be between 0 and 200.\n");
            continue;
        }
        break; // Age is valid, proceed to add the animal
    }

    if (addAnimal(&animal, animalArray, *numAnimals) == 0) {
        (*numAnimals)++;
        printf("Animal added successfully!\n");
    } else {
        printf("Our shelter is full! Failed to add animal.\n");
    }
}

void removeAnimalPrompt(ANIMAL* animalArray, int* numAnimals) {
    char name[MaxNameLength];
    printf("Enter the name of the animal you want to remove: ");
    scanf("%s", name);
    int count = removeAnimal(name, animalArray, *numAnimals);
    if (count > 0) {
        *numAnimals -= count;
        printf("%d animal(s) removed successfully!\n", count);
    } else {
        printf("No animal found with the given name.\n");
    }
}

void displayAnimals(const ANIMAL* animalArray, int numAnimals) {
    if (numAnimals == 0) {
        printf("No animals in the shelter.\n");
    } else {
        printf("\nANIMALS IN OUR SHELTER NOW\n===============================\n");
        for (int i = 0; i < numAnimals; i++) {
            printf("%s, Species: %s, Age: %d\n", animalArray[i].Name, speciesNames[animalArray[i].Species], animalArray[i].Age);
        }
    }
}

void sortAnimalsPrompt(ANIMAL* animalArray, int numAnimals) {
    int choice;
    printf("Enter your choice of sorting: 1. Age 2. Name\n");
    scanf("%d", &choice);
    if (choice == 1) {
        sortAnimalsByAge(animalArray, numAnimals);
        printf("Animals are sorted by age.\n");
    } else if (choice == 2) {
        sortAnimalsByName(animalArray, numAnimals);
        printf("Animals are sorted by name.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

void findAnimalPrompt(const ANIMAL* animalArray, int numAnimals) {
    char name[MaxNameLength];
    printf("Enter the name of the animal to find: ");
    scanf("%s", name);

    ANIMAL foundAnimal;
    if (findAnimalByName(name, animalArray, numAnimals, &foundAnimal)) {
        printf("Animal found:\nName: %s, Species: %s, Age: %d\n", foundAnimal.Name, speciesNames[foundAnimal.Species], foundAnimal.Age);
    } else {
        printf("No animal with the name %s was found.\n", name);
    }
}

void saveAndExit(const ANIMAL* animalArray, int numAnimals) {
    saveAnimalsToFile(FILENAME, animalArray, numAnimals);
    printf("Exiting...\n");
}

int main(void) {
    printf("PRC assignment 'Animal Shelter' (version April 2019)\n");
    int numAnimals = 0;
    int choice = -1;
    ANIMAL animalArray[MAX_ANIMALS];
    loadAnimalsFromFile(FILENAME, animalArray, &numAnimals); // Load animals from file

    while (1) {
        printf("\nMENU\n====\n");
        printf("1: Add Animal\n");
        printf("2: Remove Animal\n");
        printf("3: Show Animals\n");
        printf("4: Find Animal\n");
        printf("5: Sort Animals\n");
        printf("0: Save and Exit\n");
        printf("Enter your choice: ");
        
        char input[MAX_INPUT_LENGTH];
        scanf("%s", input);
        
        // Check if the input is a digit only
        int isValidInput = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                isValidInput = 0;
                break;
            }
        }

        if (!isValidInput) {
            printf("Enter digits only\n");
            continue;
        }

        switch (choice) {
            case 1:
                addAnimalPrompt(animalArray, &numAnimals);
                break;
            case 2:
                removeAnimalPrompt(animalArray, &numAnimals);
                break;
            case 3:
                displayAnimals(animalArray, numAnimals);
                break;
            case 4:
                findAnimalPrompt(animalArray, numAnimals);
                break;
            case 5:
                sortAnimalsPrompt(animalArray, numAnimals);
                break;
            case 0:
                saveAndExit(animalArray, numAnimals);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
