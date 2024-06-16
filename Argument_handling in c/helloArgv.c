#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help() {
    printf("Usage: ./helloArgv [--m M] [--e E]\n");
    printf("  --m M    Print M morning-welcome-messages\n");
    printf("  --e E    Print E evening-welcome-messages\n");
}

void print_morning_message(int count) {
    for (int i = 0; i < count; i++) {
        printf("Good morning!\n");
    }
}

void print_evening_message(int count) {
    for (int i = 0; i < count; i++) {
        printf("Good evening!\n");
    }
}

int main(int argc, char *argv[]) {
    int morning_count = 0;
    int evening_count = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "--m") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                morning_count = atoi(argv[++i]);
            } else {
                morning_count = 1;
            }
        } else if (strcmp(argv[i], "--e") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                evening_count = atoi(argv[++i]);
            } else {
                evening_count = 1;
            }
        } else {
            printf("Unknown option: %s\n", argv[i]);
            print_help();
            return 1;
        }
    }

    if (morning_count > 0) {
        print_morning_message(morning_count);
    }

    if (evening_count > 0) {
        print_evening_message(evening_count);
    }

    return 0;
}

