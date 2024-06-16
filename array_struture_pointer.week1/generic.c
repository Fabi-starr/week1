#include <stdio.h>

typedef struct {
    double sum;
    int count;
} Summary;

Summary summarize_array(double arr[], int size) {
    Summary summary;
    summary.sum = 0.0;
    summary.count = size;
    
    for (int i = 0; i < size; i++) {
        summary.sum += arr[i];
    }
    
    return summary;
}

int main() {
    double arr[] = {1.5, 2.3, 3.7, 4.2, 5.9};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    Summary summary = summarize_array(arr, size);
    
    printf("Sum: %.2f\n", summary.sum);
    printf("Count: %d\n", summary.count);
    
    return 0;
}
