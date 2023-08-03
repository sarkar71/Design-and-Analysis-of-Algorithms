#include<stdio.h>
#include<stdlib.h>

void read_array_from_file(char *filename, int *arr, int n){
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("Error");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}
int main(){
    char filename[] = "inputQ1.txt";
    int n = 0;
    FILE * file = fopen(filename, "r");
    if(file == NULL){
        printf("ERROR");
        return 1;
    }
    int num;
    while(fscanf(file, "%d", &num) != EOF){
        n++;
    }
    fclose(file);

    int * arr = (int *)malloc(sizeof(int));
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    read_array_from_file(filename, arr, n);
    printf("Second Smallest : %d\n", arr[1]);
    printf("Second Largest : %d\n", arr[n - 2]);
    free(arr);
}