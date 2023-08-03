
/*
#include<stdio.h>
int main(){
    int n; scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int freq[n];
    for(int i = 0; i < n; i++){
        freq[i] = -1;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt = 1;
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                cnt++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0){
            freq[i] = cnt;
        }
    }
    int maxi = 0, element;
    for(int i = 0; i < n; i++){
        if(freq[i] != 0 && freq[i] > maxi){
            maxi = freq[i];
            element = arr[i];
            
        }   
    }
    printf("%d occured %d times \n", element, maxi);
}
*/
#include <stdio.h>
#include <stdlib.h>

void read_integers_from_file(const char* file_path, int* arr, int n) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

int main() {
    const char* file_path = "input_file.txt"; // Replace this with the actual file path
    const int max_size = 100; // Set this to the maximum number of integers in the file
    int a[max_size],n;
    printf("Enter the number of elements ");
    scanf("%d", &n);
 read_integers_from_file(file_path,a, n);
   
   
    // total number of duplicate elements.
    int duplicates = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                duplicates++;
                break; 
            }
        }
    }

    printf("Total number of duplicate elements: %d\n", duplicates);

    //most repeating element in the array.
    int most= a[0];
    int max_frequency = 1;

    for (int i = 0; i < n; i++) {
        int frequency = 1;

        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                frequency++;
            }
        }

        if (frequency > max_frequency) {
            max_frequency = frequency;
            most= a[i];
        }
    }
    printf("Most repeating element: %d\n", most);

    return 0;
}