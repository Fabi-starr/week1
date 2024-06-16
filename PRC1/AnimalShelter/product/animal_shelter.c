#include <stdio.h>
#include <string.h>
#include "animal.h"
#include "administration.h"  // Include administration header

#define MaxAnimals 100  // Maximum number of animals in the shelter

ANIMAL animals[MaxAnimals];  // Array to store animals
int numAnimals = 0;  // Current number of animals in the shelter

// Function to show all animals
void showAnimals() {
    printf("List of Animals:\n");
    if (numAnimals == 0) {
        printf("No animals currently in the shelter.\n");
    } else {
        for (int i = 0; i < numAnimals; i++) {
            printf("Name: %s, Species: ", animals[i].Name);
            switch (animals[i].Species) {
                case Cat:
                    printf("Cat");
                    break;
                case Dog:
                    printf("Dog");
                    break;
                case GuineaPig:
                    printf("Guinea Pig");
                    break;
                case Parrot:
                    printf("Parrot");
                    break;
                default:
                    printf("Unknown");
                    break;
            }
            printf(", Age: %d\n", animals[i].Age);
        }
    }
}

// Function to add an animal
void addAnimalMenu() {
    if (numAnimals >= MaxAnimals) {
        printf("Cannot add more animals. Shelter full.\n");
        return;
    }
    
    ANIMAL newAnimal;
    printf("Enter name of the animal: ");
    scanf(" %[^\n]", newAnimal.Name);
    
    int speciesChoice;
    printf("Enter species of the animal (0: Cat, 1: Dog, 2: Guinea Pig, 3: Parrot): ");
    scanf("%d", &speciesChoice);
    if (speciesChoice < 0 || speciesChoice > 3) {
        printf("Invalid species choice.\n");
        return;
    }
    newAnimal.Species = (SPECIES)speciesChoice;
    
    printf("Enter age of the animal: ");
    scanf("%d", &newAnimal.Age);
    
    if (addAnimal(&newAnimal, animals, numAnimals) == 0) {
        numAnimals++;
        printf("Animal added successfully.\n");
    } else {
        printf("Failed to add animal.\n");
    }
}

// Function to remove an animal by name
void removeAnimalMenu() {
    char nameToRemove[MaxNameLength];
    printf("Enter the name of the animal to remove: ");
    scanf(" %[^\n]", nameToRemove);
    
    int removedCount = removeAnimal(nameToRemove, animals, numAnimals);
    if (removedCount > 0) {
        numAnimals -= removedCount;
        printf("Animal '%s' removed successfully.\n", nameToRemove);
    } else {
        printf("Animal '%s' not found in the shelter.\n", nameToRemove);
    }
}

// Function to find an animal by name
void findAnimalByNameMenu() {
    char nameToFind[MaxNameLength];
    printf("Enter the name of the animal to find: ");
    scanf(" %[^\n]", nameToFind);
    
    ANIMAL foundAnimal;
    if (findAnimalByName(nameToFind, animals, numAnimals, &foundAnimal)) {
        printf("Animal Found:\n");
        printf("Name: %s, Species: ", foundAnimal.Name);
        switch (foundAnimal.Species) {
            case Cat:
                printf("Cat");
                break;
            case Dog:
                printf("Dog");
                break;
            case GuineaPig:
                printf("Guinea Pig");
                break;
            case Parrot:
                printf("Parrot");
                break;
            default:
                printf("Unknown");
                break;
        }
        printf(", Age: %d\n", foundAnimal.Age);
    } else {
        printf("Animal '%s' not found in the shelter.\n", nameToFind);
    }
}

// Main function
int main(void) {
    printf("PRC assignment 'Animal Shelter' (version April 2019)\n");
    
    int choice = -1;
    while (choice != 0) {
        printf("\nMENU\n====\n");
        printf("1: Show Animals\n");
        printf("2: Add Animal\n");
        printf("3: Remove Animal\n");
        printf("4: Find Animal by name\n");
        printf("0: Quit\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                showAnimals();
                break;
            case 2:
                addAnimalMenu();
                break;
            case 3:
                removeAnimalMenu();
                break;
            case 4:
                findAnimalByNameMenu();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("ERROR: Invalid choice: %d\n", choice);
                break;
        }
    }
    
    return 0;
}
