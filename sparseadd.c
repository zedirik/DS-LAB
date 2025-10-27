#include <stdio.h>

int main() {
    int matrix1[50][50], matrix2[50][50];
    int sparse1[50][3], sparse2[50][3], sumSparse[100][3];
    int rows, cols, i, j, k1 = 1, k2 = 1, kSum = 1;

    // Input dimensions
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix1[i][j]);

    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix2[i][j]);

    // Print input matrices
    printf("\nFirst Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d\t", matrix1[i][j]);
        printf("\n");
    }

    printf("\nSecond Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d\t", matrix2[i][j]);
        printf("\n");
    }

    // Convert first matrix to sparse
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (matrix1[i][j] != 0) {
                sparse1[k1][0] = i;
                sparse1[k1][1] = j;
                sparse1[k1][2] = matrix1[i][j];
                k1++;
            }
    sparse1[0][0] = rows;
    sparse1[0][1] = cols;
    sparse1[0][2] = k1 - 1;

    // Convert second matrix to sparse
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (matrix2[i][j] != 0) {
                sparse2[k2][0] = i;
                sparse2[k2][1] = j;
                sparse2[k2][2] = matrix2[i][j];
                k2++;
            }
    sparse2[0][0] = rows;
    sparse2[0][1] = cols;
    sparse2[0][2] = k2 - 1;

    // Print sparse matrices
    printf("\nSparse Representation of First Matrix (row, col, value):\n");
    for (i = 0; i < k1; i++)
        printf("%d\t%d\t%d\n", sparse1[i][0], sparse1[i][1], sparse1[i][2]);

    printf("\nSparse Representation of Second Matrix (row, col, value):\n");
    for (i = 0; i < k2; i++)
        printf("%d\t%d\t%d\n", sparse2[i][0], sparse2[i][1], sparse2[i][2]);

    // Add two sparse matrices
    i = 1; j = 1;
    while (i <= sparse1[0][2] && j <= sparse2[0][2]) {
        int r1 = sparse1[i][0], c1 = sparse1[i][1];
        int r2 = sparse2[j][0], c2 = sparse2[j][1];

        if (r1 < r2 || (r1 == r2 && c1 < c2)) {
            sumSparse[kSum][0] = r1;
            sumSparse[kSum][1] = c1;
            sumSparse[kSum][2] = sparse1[i][2];
            i++; kSum++;
        } else if (r1 > r2 || (r1 == r2 && c1 > c2)) {
            sumSparse[kSum][0] = r2;
            sumSparse[kSum][1] = c2;
            sumSparse[kSum][2] = sparse2[j][2];
            j++; kSum++;
        } else {
            sumSparse[kSum][0] = r1;
            sumSparse[kSum][1] = c1;
            sumSparse[kSum][2] = sparse1[i][2] + sparse2[j][2];
            i++; j++; kSum++;
        }
    }

    // Copy remaining elements
    while (i <= sparse1[0][2]) {
        sumSparse[kSum][0] = sparse1[i][0];
        sumSparse[kSum][1] = sparse1[i][1];
        sumSparse[kSum][2] = sparse1[i][2];
        i++; kSum++;
    }
    while (j <= sparse2[0][2]) {
        sumSparse[kSum][0] = sparse2[j][0];
        sumSparse[kSum][1] = sparse2[j][1];
        sumSparse[kSum][2] = sparse2[j][2];
        j++; kSum++;
    }

    // Store metadata
    sumSparse[0][0] = rows;
    sumSparse[0][1] = cols;
    sumSparse[0][2] = kSum - 1;

    // Print result
    printf("\nSum of Sparse Matrices (row, col, value):\n");
    for (i = 0; i < kSum; i++)
        printf("%d\t%d\t%d\n", sumSparse[i][0], sumSparse[i][1], sumSparse[i][2]);

    return 0;
}










Step 1: Start

Begin the program execution.

Step 2: Input Dimensions

Prompt the user to enter the number of rows and columns.

Input: rows, cols

Step 3: Input First Matrix

Read all elements of the first matrix (matrix1[rows][cols]).

Step 4: Input Second Matrix

Read all elements of the second matrix (matrix2[rows][cols]).

Step 5: Display Input Matrices (for clarity)

Print the two matrices in normal 2D format to show the user what was entered.

Step 6: Convert First Matrix to Sparse Form

Initialize k1 = 1 (since index 0 will store metadata).

For each element of matrix1:

If the element is non-zero, store:

sparse1[k1][0] = row_index
sparse1[k1][1] = col_index
sparse1[k1][2] = value


Increment k1.

After traversal, store metadata:

sparse1[0][0] = rows
sparse1[0][1] = cols
sparse1[0][2] = k1 - 1     // total non-zero elements

Step 7: Convert Second Matrix to Sparse Form

Initialize k2 = 1.

For each element of matrix2:

If it is non-zero, store:

sparse2[k2][0] = row_index
sparse2[k2][1] = col_index
sparse2[k2][2] = value


Increment k2.

Store metadata:

sparse2[0][0] = rows
sparse2[0][1] = cols
sparse2[0][2] = k2 - 1

Step 8: Display Sparse Representations

Print sparse1 and sparse2 in (row, column, value) format for verification.

Step 9: Initialize Variables for Addition

Set:

i = 1, j = 1, kSum = 1


i → traverses sparse1

j → traverses sparse2

kSum → stores the result in sumSparse

Step 10: Add Sparse Matrices

While i <= sparse1[0][2] and j <= sparse2[0][2]:

Get current element positions:

r1 = sparse1[i][0]
c1 = sparse1[i][1]
r2 = sparse2[j][0]
c2 = sparse2[j][1]


Compare positions:

Case 1: If (r1 < r2) or (r1 == r2 and c1 < c2)
→ Copy element from sparse1 to sumSparse[kSum].
→ Increment i and kSum.

Case 2: If (r1 > r2) or (r1 == r2 and c1 > c2)
→ Copy element from sparse2.
→ Increment j and kSum.

Case 3: If (r1 == r2 && c1 == c2)
→ Same position → Add values:

sumSparse[kSum][0] = r1
sumSparse[kSum][1] = c1
sumSparse[kSum][2] = sparse1[i][2] + sparse2[j][2]


→ Increment all (i++, j++, kSum++).

Step 11: Copy Remaining Elements

If any elements are left over in one sparse matrix after the loop:

Copy them directly to sumSparse.

Example:

while (i <= sparse1[0][2]) { ... i++; kSum++; }
while (j <= sparse2[0][2]) { ... j++; kSum++; }

Step 12: Store Metadata for Result

At the end:

sumSparse[0][0] = rows
sumSparse[0][1] = cols
sumSparse[0][2] = kSum - 1   // number of non-zero elements in result

Step 13: Display Result

Print the final sum in sparse triplet form:

(row, column, value)

Step 14: End Program

Stop execution.