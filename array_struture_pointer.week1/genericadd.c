#include <stdio.h>

typedef struct {
    double sum;
    int count;
    double min; // Add a field to store the maximum value
} Summary;

int summarize_array(double arr[], int size, Summary *summary) {
    if (arr == NULL || summary == NULL || size == 0) {
        return -1; // Indicate an error
    }

    summary->sum = 0.0;
    summary->count = size;
    summary->min = arr[0]; // Initialize max to the first element of the array

    for (int i = 0; i < size; i++) {
        summary->sum += arr[i];
        if (arr[i] < summary->min) {
            summary->min = arr[i];
        }
    }

    return 0; // Indicate success
}

int main() {
    double arr[] = {1.5, 2.3, 33.7, 54.2, 5.9};
    int size = sizeof(arr) / sizeof(arr[0]);

    Summary summary;

    int result = summarize_array(arr, size, &summary);

    if (result == 0) {
        printf("Sum: %.2f\n", summary.sum);
        printf("Count: %d\n", summary.count);
        printf("Min: %.2f\n", summary.min);
    } else {
        printf("An error occurred while summarizing the array.\n");
    }

    return 0;
}
