#include <stdio.h>
#include <string.h>
#include "administration.h"
#include "../Unity/unity.h"  // Assuming Unity framework is located in the parent directory

// Mock data for testing
#define MAX_ANIMALS_TEST 5
ANIMAL testAnimals[MAX_ANIMALS_TEST] = {
    {"Tom", Cat, 3},
    {"Buddy", Dog, 5},
    {"Coco", Dog, 2},
    {"Charlie", Parrot, 1},
    {"Whiskers", Cat, 4}
};

void setUp(void) {
    // Initialize test environment if needed
}

void tearDown(void) {
    // Clean up test environment if needed
}

void test_addAnimal(void) {
    ANIMAL addedAnimal = {"Max", Dog, 7};
    TEST_ASSERT_EQUAL_INT(0, addAnimal(&addedAnimal, testAnimals, MAX_ANIMALS_TEST));
    TEST_ASSERT_EQUAL_STRING("Max", testAnimals[MAX_ANIMALS_TEST - 1].Name);
}

void test_removeAnimal(void) {
    TEST_ASSERT_EQUAL_INT(1, removeAnimal("Coco", testAnimals, MAX_ANIMALS_TEST));
    TEST_ASSERT_EQUAL_INT(0, removeAnimal("Nonexistent", testAnimals, MAX_ANIMALS_TEST));
}

void test_sortAnimalsByAge(void) {
    TEST_ASSERT_EQUAL_INT(0, sortAnimalsByAge(testAnimals, MAX_ANIMALS_TEST));
    TEST_ASSERT_GREATER_OR_EQUAL(testAnimals[0].Age, testAnimals[MAX_ANIMALS_TEST - 1].Age);
}

void test_sortAnimalsByName(void) {
    TEST_ASSERT_EQUAL_INT(0, sortAnimalsByName(testAnimals, MAX_ANIMALS_TEST));
    TEST_ASSERT_TRUE(strcmp(testAnimals[0].Name, "Buddy") < 0);
    TEST_ASSERT_TRUE(strcmp(testAnimals[1].Name, "Coco") < 0);
    TEST_ASSERT_TRUE(strcmp(testAnimals[2].Name, "Charlie") < 0);
}

void test_findAnimalByName(void) {
    ANIMAL foundAnimal;
    TEST_ASSERT_EQUAL_INT(1, findAnimalByName("Tom", testAnimals, MAX_ANIMALS_TEST, &foundAnimal));
    TEST_ASSERT_EQUAL_STRING("Tom", foundAnimal.Name);
    TEST_ASSERT_EQUAL_INT(0, findAnimalByName("Nonexistent", testAnimals, MAX_ANIMALS_TEST, &foundAnimal));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_addAnimal);
    RUN_TEST(test_removeAnimal);
    RUN_TEST(test_sortAnimalsByAge);
    RUN_TEST(test_sortAnimalsByName);
    RUN_TEST(test_findAnimalByName);
    return UNITY_END();
}
