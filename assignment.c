#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE


    

    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number is 2\n", argc -1);
        return 1;
    }

    // Loop through each argument to check if it is a positive integer
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j])) {
                printf("Incorrect usage. The parameters you provided are not positive integers\n");
                return 1;
            }
        }

        // Check if the integer is positive
        if (atoi(argv[i]) <= 0) {
            printf("Incorrect usage. The parameters you provided are not positive integers\n");
            return 1;
        }
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i=0; i<rows;i++){
        matrix[i] = (int*)malloc(cols*sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j ++) {
            int num = (rand() % (maxrand - minrand + 1)) + minrand;
            matrix[i][j] = num;
        }
    }

    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j ++) {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols -1) {
                fprintf(file, " ");
            }
        }
        fprintf(file, "\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);



    return 0;
}


