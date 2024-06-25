#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void help(char command[]) {
    printf("Usage: %s <initial_value> <new_value>\n", command);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        help(argv[0]);
        return 1; // Indicate error
    }

    // Validate that all characters in argv[1] and argv[2] are digits
    for (int i = 1; i < argc; i++) {
        char *eacharg = argv[i];
        int arglength = strlen(eacharg);
        for (int j = 0; j < arglength; j++) {
            if (!isdigit(eacharg[j])) {
                help(argv[0]);
                return 1; // Indicate error
            }
        }
    }

    int x = atoi(argv[1]); // Initial value from command-line argument
    int new_value = atoi(argv[2]); // New value from command-line argument

    int *p;
    int *d;
    p = &x;
    d = &x;

    printf("The initial value of x is %d\n", x);
    printf("The value of pointer p is %d\n", *p);
    printf("The address of x is %p\n", (void*)p); // Cast to void* for portability

    *d = new_value; // Assign new value to x through pointer d

    printf("The new value of x is %d\n", x);
    printf("The new value of pointer p is %d\n", *p);

    return 0; // Indicate success
}
