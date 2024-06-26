/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 
Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1*/

#include <string.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int m = *matrixColSize;

    int isRowZero[n];
    int isColZero[m];

    memset(isRowZero, 0, sizeof(isRowZero));
    memset(isColZero, 0, sizeof(isColZero));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                isRowZero[i] = 1;
                isColZero[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isRowZero[i] || isColZero[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}