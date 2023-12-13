#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    //open and read file
    FILE *fp;
    fp = fopen("t4.txt", "r");

    int rows = 0, cols = 0;
    fscanf(fp, "rows=%d\ncols=%d\n", &rows, &cols);
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    //read matrix from file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }

    //output the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}