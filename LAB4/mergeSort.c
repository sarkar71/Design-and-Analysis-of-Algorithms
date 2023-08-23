#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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

int main() {
    int option;
     char *input_file, *output_file;
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
        
       
        
        if (option == 1) {
            input_file = "inAsce.dat";
            output_file = "outMergeAsce.dat";
        } else if (option == 2) {
            input_file = "inDesc.dat";
            output_file = "outMergeDesc.dat";
        } else if (option == 3) {
            input_file = "inRand.dat";
            output_file = "outMergeRand.dat";
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
        
        comparisons = 0;
        clock_t start_time = clock();
        merge_sort(arr, 0, n - 1);
        clock_t end_time = clock();
        
        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        printf("Number of Comparisons: %lld\n", comparisons);
        printf("Execution Time (nanoseconds): %lld\n", (long long)(end_time - start_time));
        
        write_output_file(output_file, arr, n);
        printf("\n");
    }
    
    return 0;
}
