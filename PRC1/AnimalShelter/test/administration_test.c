#include "Unity/unity.h"
#include "../product/administration.h"
#include <stdio.h>
#include <string.h>

#define MAX_TEST_ANIMALS 5
ANIMAL testAnimalArray[MAX_TEST_ANIMALS];
int numTestAnimals = 0;

void setUp(void) {
    numTestAnimals = 0;
}

void tearDown(void) {
}

void test_addAnimal(void) {
    ANIMAL animal = {"TestCat", 3, Cat};
    TEST_ASSERT_EQUAL_INT(0, addAnimal(&animal, testAnimalArray, numTestAnimals));
    numTestAnimals++;
}

void test_removeAnimal(void) {
    ANIMAL testAnimals[MAX_TEST_ANIMALS] = {
        {"TestDog", 2, Dog},
        {"TestParrot", 1, Parrot},
        {"TestGuineaPig", 4, GuineaPig},
        {"TestCat", 3, Cat},
        {"TestDog", 5, Dog}
    };
    memcpy(testAnimalArray, testAnimals, sizeof(testAnimals));
    numTestAnimals = MAX_TEST_ANIMALS;

    TEST_ASSERT_EQUAL_INT(2, removeAnimal("TestDog", testAnimalArray, numTestAnimals));
    numTestAnimals -= 2;
}

void test_sortAnimalsByName(void) {
    ANIMAL testAnimals[MAX_TEST_ANIMALS] = {
        {"B", 5, Cat},
        {"A", 3, Dog},
        {"D", 2, Parrot},
        {"C", 4, GuineaPig},
        {"E", 1, Dog}
    };
    memcpy(testAnimalArray, testAnimals, sizeof(testAnimals));
    numTestAnimals = MAX_TEST_ANIMALS;

    sortAnimalsByName(testAnimalArray, numTestAnimals);

    TEST_ASSERT_EQUAL_STRING("A", testAnimalArray[0].Name);
    TEST_ASSERT_EQUAL_STRING("B", testAnimalArray[1].Name);
    TEST_ASSERT_EQUAL_STRING("C", testAnimalArray[2].Name);
    TEST_ASSERT_EQUAL_STRING("D", testAnimalArray[3].Name);
    TEST_ASSERT_EQUAL_STRING("E", testAnimalArray[4].Name);
}

void test_sortAnimalsByAge(void) {
    ANIMAL testAnimals[MAX_TEST_ANIMALS] = {
        {"B", 1, Cat},
        {"A", 2, Dog},
        {"D", 3, Parrot},
        {"C", 4, GuineaPig},
        {"E", 5, Dog}
    };
    memcpy(testAnimalArray, testAnimals, sizeof(testAnimals));
    numTestAnimals = MAX_TEST_ANIMALS;

    sortAnimalsByAge(testAnimalArray, numTestAnimals);

    TEST_ASSERT_EQUAL_INT(1, testAnimalArray[0].Age);
    TEST_ASSERT_EQUAL_INT(2, testAnimalArray[1].Age);
    TEST_ASSERT_EQUAL_INT(3, testAnimalArray[2].Age);
    TEST_ASSERT_EQUAL_INT(4, testAnimalArray[3].Age);
    TEST_ASSERT_EQUAL_INT(5, testAnimalArray[4].Age);
}

void test_findAnimalByName(void) {
    ANIMAL testAnimals[MAX_TEST_ANIMALS] = {
        {"TestDog", 2, Dog},
        {"TestParrot", 1, Parrot},
        {"TestGuineaPig", 4, GuineaPig},
        {"TestCat", 3, Cat},
        {"TestDog", 5, Dog}
    };
    memcpy(testAnimalArray, testAnimals, sizeof(testAnimals));
    numTestAnimals = MAX_TEST_ANIMALS;

    ANIMAL foundAnimal;
    int found = findAnimalByName("TestCat", testAnimalArray, numTestAnimals, &foundAnimal);
    TEST_ASSERT_EQUAL_INT(1, found);
    TEST_ASSERT_EQUAL_STRING("TestCat", foundAnimal.Name);
}

int main(void) {
    UnityBegin( );

    RUN_TEST(test_addAnimal, __LINE__);
    RUN_TEST(test_removeAnimal, __LINE__);
    RUN_TEST(test_sortAnimalsByAge, __LINE__);
    RUN_TEST(test_sortAnimalsByName, __LINE__);
    RUN_TEST(test_findAnimalByName, __LINE__);

    return UnityEnd();
}
