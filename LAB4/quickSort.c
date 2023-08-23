#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void read_input_file(char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "r");
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

void write_output_file(char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

// Function to perform quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int option;
    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        
        printf("Enter option: ");
        scanf("%d", &option);
        
        if (option == 4) {
            break;
        }
        
        char *input_file, *output_file;
        
        if (option == 1) {
            input_file = "inAsce.dat";
            output_file = "outQuickAsce.dat";
        } else if (option == 2) {
            input_file = "inDesc.dat";
            output_file = "outQuickDesc.dat";
        } else if (option == 3) {
            input_file = "inRand.dat";
            output_file = "outQuickRand.dat";
        } else {
            printf("Invalid option. Please enter a valid option.\n");
            continue;
        }
        
        FILE *file = fopen(input_file, "r");
        int n;
        fscanf(file, "%d", &n);
        int arr[n];
        read_input_file(input_file, arr, n);
        
        printf("Before Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        
        clock_t start_time = clock();
        quickSort(arr, 0, n - 1);
        clock_t end_time = clock();
        
        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        printf("Execution Time (nanoseconds): %lld\n", (long long)(end_time - start_time));
        
        write_output_file(output_file, arr, n);
        printf("\n");
    }
    
    return 0;
}