#include <stdio.h>

int main() {
    int matrix[50][50], sparse[50][3], transpose[50][3];
    int rows, cols, i, j, k = 1, t;

    // Input dimensions
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the original matrix
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Convert matrix to sparse form
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1; // number of non-zero elements

    // Print sparse matrix
    printf("\nSparse Matrix (Row, Column, Value):\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    // Compute transpose
    transpose[0][0] = sparse[0][1]; // rows become columns
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];

    t = 1;
    for (i = 0; i < sparse[0][1]; i++) { // for each column of original
        for (j = 1; j <= sparse[0][2]; j++) {
            if (sparse[j][1] == i) { // if column matches
                transpose[t][0] = sparse[j][1];
                transpose[t][1] = sparse[j][0];
                transpose[t][2] = sparse[j][2];
                t++;
            }
        }
    }

    // Print transpose sparse matrix
    printf("\nTranspose Sparse Matrix (Row, Column, Value):\n");
    for (i = 0; i < t; i++) {
        printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

    return 0;
}





