#include <stdio.h>

typedef struct {
    double sum;
    int count;
} Summary;

int summarize_array(double arr[], int size, Summary *summary) {
    if (arr == NULL || summary == NULL) {
        return -1; // Indicate an error
    }

    summary->sum = 0.0;
    summary->count = size;

    for (int i = 0; i < size; i++) {
        summary->sum += arr[i];
    }

    return 0; // Indicate success
}

int main() {
    double arr[] = {1.5, 2.3, 3.7, 4.2, 5.9};
    int size = sizeof(arr) / sizeof(arr[0]);

    Summary summary;

    int result = summarize_array(arr, size, &summary);

    if (result == 0) {
        printf("Sum: %.2f\n", summary.sum);
        printf("Count: %d\n", summary.count);
    } else {
        printf("An error occurred while summarizing the array.\n");
    }

    return 0;
}
