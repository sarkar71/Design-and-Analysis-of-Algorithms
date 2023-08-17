#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int el = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > el){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = el;
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int maxNumbers = 1000; // Change this to a suitable value
    int numbers[maxNumbers];
    int numCount = 0;

    // Read numbers from the input file
    while (fscanf(inputFile, "%d", &numbers[numCount]) == 1) {
        numCount++;
    }

    fclose(inputFile);

    // Sort the numbers using bubble sort
    insertionSort(numbers, numCount);

    // Write sorted numbers to the output file
    for (int i = 0; i < numCount; i++) {
        fprintf(outputFile, "%d\n", numbers[i]);
    }

    fclose(outputFile);

    printf("Numbers sorted and written to output.txt\n");

    return 0;
}
