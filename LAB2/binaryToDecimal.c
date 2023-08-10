#include <stdio.h>
int find(int decimal, FILE *outputFile){
	if (decimal > 0){
		find(decimal / 2, outputFile);
		fprintf(outputFile, "%d", decimal % 2);
	}

}
// Driver code
int main(int argc, char * argv[]){
	int n;
	FILE *inputFile, *outputFile;
	inputFile = fopen(argv[1], "r");
	outputFile = fopen(argv[2], "w");
	if(inputFile == NULL || outputFile == NULL){
		printf("Error opening files\n");
		return 1;
	}
	fscanf(inputFile, "%d", &n);
	int decimal;
	for(int i = 0; i < n; i++){
		fscanf(inputFile, "%d", &decimal);
		find(decimal, outputFile);
		fprintf(outputFile, "w");
	}
	fclose(inputFile);
	fclose(outputFile);
	printf("Conversion from Decimal to Binary '%s:'", argv[2]);
	return 0;
}
